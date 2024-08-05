// Rat in maze problem.

#include <iostream>
#include <vector>
using namespace std;

bool isSafe(int i, int j, int row, int col, int arr[][4], vector<vector<bool>> &visited)
{

  if (((i >= 0 && i < row) && (j >= 0 && j < col)) && (arr[i][j] == 1) && (visited[i][j] == false))
    return true;
  else
    return false;
}

void solveMaze(int arr[][4], int row, int col, int i, int j, vector<vector<bool>> &visited, vector<string> &path, string &output)
{

  // base case
  if (i == row - 1 && j == col - 1)
  {
    // answer found
    path.push_back(output);
    return;
  }

  // Down -> i+1, j
  if (isSafe(i + 1, j, row, col, arr, visited))
  {
    visited[i + 1][j] = true;
    output.push_back('D');
    solveMaze(arr, row, col, i + 1, j, visited, path, output);
    // backtrack
    output.pop_back();
    visited[i + 1][j] = false;
  }

  // Left -> i, j-1
  if (isSafe(i, j - 1, row, col, arr, visited))
  {
    visited[i][j - 1] = true;
    output.push_back('L');
    solveMaze(arr, row, col, i, j - 1, visited, path, output);
    // backtrack
    output.pop_back();
    visited[i][j - 1] = false;
  }

  // Right -> i, j+1
  if (isSafe(i, j + 1, row, col, arr, visited))
  {
    visited[i][j + 1] = true;
    output.push_back('R');
    solveMaze(arr, row, col, i, j + 1, visited, path, output);
    // backtrack
    output.pop_back();
    visited[i][j + 1] = false;
  }

  // Up-> i-1, j
  if (isSafe(i - 1, j, row, col, arr, visited))
  {
    visited[i - 1][j] = true;
    output.push_back('U');

    solveMaze(arr, row, col, i - 1, j, visited, path, output);

    // backtrack
    output.pop_back();
    visited[i - 1][j] = false;
  }
}

int main()
{
  int maze[4][4] = {{1, 0, 0, 0},
                    {1, 1, 0, 1},
                    {1, 1, 0, 0},
                    {0, 1, 1, 1}};

  if (maze[0][0] == 0)
  {
    cout << "No Path Exists " << endl;
    return 0;
  }

  int row = 4;
  int col = 4;

  vector<vector<bool>> visited(row, vector<bool>(col, false));
  // src ki value k true mark kredete h
  visited[0][0] = true;

  vector<string> path;
  string output = "";

  solveMaze(maze, row, col, 0, 0, visited, path, output);

  cout << "printing the results " << endl;
  for (auto i : path)
  {
    cout << i << " ";
  }
  cout << endl;
  if (path.size() == 0)
  {
    cout << "No Path Exists " << endl;
  }

  return 0;
}

/*




#include <iostream>
#include<vector>
using namespace std;


bool isSafe(int i, int j, int row, int col, int arr[][4], vector<vector<bool> > &visited) {

  if( ((i>=0 && i < row) && (j >= 0 && j< col)) &&(arr[i][j] == 1 ) && (visited[i][j]==false)) return true;
  else return false;

}

int dx[] = {1 , 0 , 0 , -1};
int dy[] = {0 , -1 , 1 , 0};
string dir[] = {" Down " , " Left " , " Right " , " Up "};

void solveMaze(int arr[][4], int row,int col, int i, int j, vector<vector<bool> > &visited, vector<string>& path, string output) {

    //base case
    if(i == row-1 && j == col-1) {
        //answer found
        path.push_back(output);
        return;
    }

    for (int k = 0; k < 4; k++)
    {
        int newi = i+dx[k];
        int newj = j+dy[k];
        string direction = dir[k];
        string newoutput = output + direction;

        if(isSafe(newi, newj, row, col, arr, visited)) {
            visited[newi][newj] = true;
            solveMaze(arr, row, col, newi, newj, visited, path, newoutput);
            //backtrack
            visited[newi][newj] = false;
        }
    }
}

int main() {
  int maze[4][4] = { {1,0,0,0},
                     {1,1,1,1},
                     {1,1,1,0},
                     {0,1,1,1}};

  if(maze[0][0] == 0) {
    cout << "No Path Exists " << endl;
    return 0;
  }

  int row = 4;
  int col = 4;

  vector<vector<bool> > visited(row, vector<bool>(col,false));
  //src ki value k true mark kredete h
  visited[0][0] = true;

  vector<string> path;
  string output = "";

  solveMaze(maze,row,col, 0,0, visited, path, output);

  cout << "printing the results " << endl;
  for(auto i: path) {
    cout << i << endl;
  }
  cout << endl;

  if(path.size() == 0 ){
    cout << "No Path Exists " << endl;
  }

  return 0;
}
*/