/*
Leetcode 221. Maximal Square:

    Given an m x n binary matrix filled with 0's and 1's, find the largest square containing only 1's and return its area.
*/

#include<iostream>
#include<vector>
#include<limits.h>

using namespace std;

int solve(vector<vector<char>> &matrix, int i, int j, int &rows, int &cols, int &maxi){
    if (i>=rows || j >= cols) return 0;

    int rightMeJao = solve(matrix, i, j+1, rows, cols, maxi);
    int diagonalMeJao = solve(matrix, i+1, j+1, rows, cols, maxi);
    int downJao = solve(matrix, i+1, j, rows, cols, maxi);

    if(matrix[i][j] == '1'){
        int ans = 1 + min(rightMeJao, min(diagonalMeJao, downJao));
        maxi = max(maxi, ans);
        return ans;
    }
    else{
        return 0;
    }
}

int main(){
    vector<vector<char>> matrix = {
        {'1','0','1','0','0'},
        {'1','0','1','1','1'},
        {'1','1','1','1','1'},
        {'1','0','1','1','1'}
    };
    int rows = matrix.size();
    int cols = matrix[0].size();
    int i = 0;
    int j = 0;
    int max = 0;
    int largestSquare = solve(matrix, i, j, rows, cols, max);
    cout<<"Area of largest square containing only 1's : "<<max*max;
return 0;
}