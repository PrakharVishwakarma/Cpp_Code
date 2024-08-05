// Leetcode 279 : Perfect Square
 
#include<iostream>
#include<vector>
#include<limits.h>
using namespace std;

int numSquares(int n) {
    if(n==0) return 1;

    if(n<0) return 0;
    
    int ans = INT_MAX;
    for (int i = 1; i*i <= n; i++)
    {
        int numOfPerfSquare = 1 + numSquares(n - i*i);
        ans = min(ans, numOfPerfSquare);
    }
    return ans;
}

int solveUsingMemoisation(int n, vector<int> &dp) {
    if(n==0) return 1;

    if(n<0) return 0;
    
    if(dp[n] != -1) return dp[n];

    int ans = INT_MAX;
    for (int i = 1; i*i <= n; i++)
    {
        int numOfPerfSquare = 1 + solveUsingMemoisation(n - i*i, dp);
        ans = min(ans, numOfPerfSquare);
    }
    dp[n] = ans;
return dp[n];
}

int solveUsingTabulation(int n) {
    vector<int> dp(n+1, -1);

    dp[0] = 1;

    for (int i = 1; i <= n; i++){
        int ans = INT_MAX;
        for (int s = 1; s*s <= i; s++)
        {
            int numOfPerfSquare = 1 + dp[i - s*s];
            ans = min(ans, numOfPerfSquare);
        }
        dp[i] =  ans;
    }

return dp[n];
}

int main(){
    int  n = 13; 
    int ans = numSquares(n)-1;
    cout<<"the least number of perfect square numbers that sum to : " <<n<<" is "<<ans<<endl;
    
    vector<int> dp(n+1, -1);
    ans = solveUsingMemoisation(n, dp)-1;
    cout<<"the least number of perfect square numbers that sum to : " <<n<<" is "<<ans<<endl;

    ans = solveUsingTabulation(n)-1;
    cout<<"the least number of perfect square numbers that sum to : " <<n<<" is "<<ans<<endl;


return 0;
}
