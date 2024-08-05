// Leetcode 1143 : Longest common subsequences

#include<iostream>
#include<vector>

using namespace std;

int solveUsingRecursion(string &a, string &b, int i, int j){
    if(i >= a.length())return 0; 
    if(j >= b.length())return 0;

    int ans = 0;
    if (a[i] == b[j]){
        ans = 1 + solveUsingRecursion(a, b, i+1, j+1);
    }
    else{
        ans = 0 + max(solveUsingRecursion(a, b, i+1, j), solveUsingRecursion(a, b, i, j+1));
    }
    return ans;
}

int solveUsingMemoisation(string &a, string &b, int i, int j, vector<vector<int> > &dp){
    if(i >= a.length())return 0; 
    if(j >= b.length())return 0;

    if (dp[i][j] != -1)return dp[i][j];
    
    int ans = 0;
    if (a[i] == b[j]){
        ans = 1 + solveUsingMemoisation(a, b, i+1, j+1, dp);
    }
    else{
        ans = 0 + max(solveUsingMemoisation(a, b, i+1, j, dp), solveUsingMemoisation(a, b, i, j+1, dp));
    }
    dp[i][j] = ans;
    return dp[i][j];
}

int solveUsingTabulation(string &a, string &b){
    vector<vector<int> > dp(a.length()+1, vector<int> (b.length()+1, 0));

    int ans = 0;
    for (int i = a.length()-1; i >= 0; i--)
    {
        for (int j = b.length()-1; j >= 0; j--)
        {
            if (a[i] == b[j]){
                ans = 1 + dp[i+1][j+1];
            }
            else{
                ans = 0 + max(dp[i+1][j], dp[i][j+1]);
            }
            dp[i][j] = ans;
        }
    }
return dp[0][0];
}

int solveUsingTabulationOptimization1(string &a, string &b){
    vector<int> curr(a.length()+1, 0);
    vector<int> next(a.length()+1, 0);

    int ans = 0;
    for (int j = b.length()-1; j >= 0; j--){
        for (int i = a.length()-1; i >= 0; i--)
        {
            if (a[i] == b[j]){
                ans = 1 + next[i+1];
            }
            else{
                ans = 0 + max(curr[i+1], next[i]);
            }
            curr[i] = ans;
        }
        next = curr;
    }
return next[0];
}

void longestCommonSubsequence(string &text1, string &text2) {
    // Solve Using Recc : 
    int i = 0;
    int j = 0;
    cout<<"The longest common subsequence is : "<<solveUsingRecursion(text1, text2, i, j);

    // Solve using memoisation: 
    vector<vector<int> > dp(text1.length()+1, vector<int> (text2.length()+1, -1));
    cout<<endl<<"The longest common subsequence is : "<<solveUsingMemoisation(text1, text2, i, j, dp);

    cout<<endl<<"The longest common subsequence is : "<<solveUsingTabulation(text1, text2);

    cout<<endl<<"The longest common subsequence is : "<<solveUsingTabulationOptimization1(text1, text2);
}

int main(){
    string text1 = "abcde", text2 = "ace";
    longestCommonSubsequence(text1, text2);

return 0;
}