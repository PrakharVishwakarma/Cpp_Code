// Leetcode : 375: Guess Number Higher or Lower 2:

#include<iostream>
#include<limits.h>
#include<vector>

using namespace std;

int solveUsingRecursion(int start, int end){
    if(start >= end) return 0;

    int ans = INT_MAX;
    for (int i = start; i <= end; i++)
    {
        ans = min(ans, i+ max(solveUsingRecursion(start, i-1), solveUsingRecursion(i+1, end)));   
    }
return ans; 
}

int solveUsingMemoisation(int start, int end, vector<vector<int> > &dp){
    if(start >= end) return 0;

    int ans = INT_MAX;

    if (dp[start][end] != -1)return dp[start][end];
    
    for (int i = start; i <= end; i++)
    {
        ans = min(ans, i+ max(solveUsingMemoisation(start, i-1, dp), solveUsingMemoisation(i+1, end, dp)));   
    }
    dp[start][end] = ans;
return ans;
}

int solveUsingTabulation(int &n){
    vector<vector<int> >dp(n+2, vector<int> (n+1, 0));

    for (int start_index = n; start_index >= 1; start_index--)
    {
        for (int end_index = 1; end_index <= n; end_index++)
        {
            if (start_index >= end_index)
            {
                continue;
            }
            int ans = INT_MAX;
            for (int i = start_index; i <= end_index; i++)
            {
                ans = min(ans, i+ max(dp[start_index][i-1], dp[i+1][end_index]));   
            }
            dp[start_index][end_index] = ans;   
        }
    }
return dp[1][n];
}

void getMoneyAmount(int &n) {
    int start = 1;
    int end = n;
    cout<<"the minimum amount of money you need to guarantee a win regardless of what number I pick is : "<<solveUsingRecursion(start, end)<<endl;

    // Because the problem is related to 2d DP.
    vector<vector<int> >dp(n+1, vector<int> (n+1, -1));
    cout<<"the minimum amount of money you need to guarantee a win regardless of what number I pick is : "<<solveUsingMemoisation(start, end, dp)<<endl;

    cout<<"the minimum amount of money you need to guarantee a win regardless of what number I pick is : "<<solveUsingTabulation(n)<<endl;
}

int main(){
    int n = 10;
    getMoneyAmount(n);
return 0;
}