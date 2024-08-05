/*Leetcode: 5 : Longest Palindromic Substring. */

#include<iostream>
#include<vector>
using namespace std;

int start = 0;
int maxLen = 1;

bool solveUsingRecurr(string &s, int i , int j){
    if(i>=j) return true;
    bool flag = false;
    if(s[i] == s[j]){
        flag = solveUsingRecurr(s, i+1, j-1);
    }
    if(flag){
        int currLen = j-i+1;
        if(currLen > maxLen){
            maxLen = currLen;
            start = i;
        }
    }
    return flag;
}

bool solveUsingMemoisation(string &s, int i , int j, vector<vector<int>> &dp){
    if(i>=j) return true;
    
    if(dp[i][j] != -1) return dp[i][j];

    bool flag = false;
    if(s[i] == s[j]){
        flag = solveUsingMemoisation(s, i+1, j-1, dp);
    }
    if(flag){
        int currLen = j-i+1;
        if(currLen > maxLen){
            maxLen = currLen;
            start = i;
        }
    }
    dp[i][j] = flag;
return dp[i][j];
}

string longestPalindrome(string &s) {
    int n = s.size();
    vector<vector<int> > dp(n, vector<int> (n, -1));
    for (int i = 0; i < n; i++)
    {
        for (int j = i; j < n; j++)
        {
            // bool t = solveUsingRecurr(s, i, j);
            bool t = solveUsingMemoisation(s, i, j, dp);
        }
    }
return s.substr(start, maxLen);
}

int main(){
    string s = "babad";
    cout<< "the longest palindromic substring in s is : "<<longestPalindrome(s);

return 0;
}