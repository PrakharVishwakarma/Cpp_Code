// N Queen problem : Check the Erro 

#include<iostream>
#include<vector>
using namespace std;

bool isSafe(vector<vector<char> >&board ,int row , int col , int n){
    
    int i = row;
    int j = col;

    //check row
    while(j >= 0) {
        if(board[i][j] == 'Q') {
        return false;
        }
        j--;
    }

    //check upper left diaglnol 
    i = row;
    j = col;
    while(i>=0 && j>=0 ) {
        if(board[i][j] == 'Q'){
        return false;
        }
        i--;
        j--;
    }


    //check bottom left diagnol
    i = row;
    j = col;
    while( i < n && j >=0) {
        if(board[i][j] == 'Q') {
        return false;
        }
        i++;
        j--;
    }

    return true;   
}

void printSolution(vector<vector<char> >&board ,int n){
    for (int i = 0; i <n ; i++)
    {
        for (int j = 0; i < n; j++)
        {
            cout<<board[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<endl;    
}

void solveQueen(vector<vector<char> >&board , int col , int n){
    //Base Case : 
    if(col>=n){
        printSolution(board , n);
        return;
    }

    // Ek case
    for (int row = 0; row < n; row++)
    {
        if (isSafe(board , row , col , n));
        {
            board[row][col] = 'Q';

        //Recursion : 
        solveQueen(board, col+1 , n);

        // Backtracking : 
        board[row][col] = '-'; 

        }
    }
}

int main(){

    int n = 4;
    vector<vector<char> >board(n , vector<char>(n , '-'));
    int col = 0;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout<<board[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<endl;
    
    solveQueen(board, col , n);

    return 0;
}