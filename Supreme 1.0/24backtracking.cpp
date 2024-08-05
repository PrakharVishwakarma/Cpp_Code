
#include <iostream>
#include <vector>

using namespace std;

bool isSafe(vector<vector<int>> &puzzle, int value, int row, int col)
{
    int n = puzzle.size();

    for (int i = 0; i < n; i++)
    {
        // row check
        if (puzzle[row][i] == value) return false;

        // col check
        if (puzzle[i][col] == value) return false;

        // 3*3 box check
        if (puzzle[3 * (row / 3) + (i / 3)][3 * (col / 3) + (i % 3)] == value) return false;
    }
    
    return true;
}

bool solveSudoku(vector<vector<int>> &puzzle)
{
    int n = puzzle.size();

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            // check for empty cell
            if (puzzle[i][j] == 0)
            {
                // try to fill with values ranging from 1 to 9
                for (int val = 1; val <= 9; val++)
                {
                    // check for safety
                    if (isSafe(puzzle, val, i, j))
                    {
                        // insert
                        puzzle[i][j] = val;
                        // recursion sambal lega
                        bool remainingBoardSolution = solveSudoku(puzzle);
                        if (remainingBoardSolution == true)
                        {
                            return true;
                        }
                        else
                        {
                            // backtrack
                            puzzle[i][j] = 0;
                        }
                    }
                }
                // if 1 se 9 tak koi bhi value se solution
                // nahi nikla ,current cell pr,
                // that means piche kahin pr galti h ,
                // go back by returning false
                return false;
            }
        }
    }
    // all cells filled
    return true;
}

int main()
{
    vector<vector<int>> puzzle = {
        {4, 5, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 2, 0, 7, 0, 6, 3, 0},
        {0, 0, 0, 0, 0, 0, 0, 2, 8},

        {0, 0, 0, 9, 5, 0, 0, 0, 0},
        {0, 8, 6, 0, 0, 0, 2, 0, 0},
        {0, 2, 0, 6, 0, 0, 7, 5, 0},

        {0, 0, 0, 0, 0, 0, 4, 7, 6},
        {0, 7, 0, 0, 4, 5, 0, 0, 0},
        {0, 0, 8, 0, 0, 9, 0, 0, 0}};

    for (int i = 0; i < puzzle.size(); i++)
    {
        for (int j = 0; j < puzzle.size(); j++)
        {
            cout << puzzle[i][j] << " ";
        }
        cout << endl;
    }

    cout << endl<< "Solution of the sudoku puzzle is : " << endl;
    solveSudoku(puzzle);

    for (int i = 0; i < puzzle.size(); i++)
    {
        for (int j = 0; j < puzzle.size(); j++)
        {
            cout << puzzle[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}