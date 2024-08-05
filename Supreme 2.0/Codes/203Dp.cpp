// Painting Fence Problem : 

#include<iostream>
#include<vector>

using namespace std;

int solveUsingRecc(int n, int k){
    if (n == 1) return k;

    if (n == 2) return k + (k*(k-1));

    int ans = (solveUsingRecc(n-2, k) + solveUsingRecc(n-1, k))* (k-1);
return ans;
}

int solveUsingMemoisation(int n, int k, vector<int> &dp){
    if (n == 1) return k;

    if (n == 2) return k + (k*(k-1));

    if(dp[n] != -1) return dp[n];

    dp[n] = (solveUsingMemoisation(n-2, k, dp) + solveUsingMemoisation(n-1, k, dp))* (k-1);
return dp[n];
}

int solveUsingTabulation(int n, int k){
    vector<int> dp(n+1, -1);
    dp[1] = k;
    dp[2] = k + (k*(k-1));

    for (int i = 3; i <= n; i++){
        dp[i] = (dp[i-2] + dp[i-1])*(k-1);
    }

return dp[n];
}

int solveUsingTabulationOptimization(int n, int k){
    int prev2 = k;
    int prev1 = k+ k*(k-1);

    if(n == 1) return prev2;
    if(n == 2) return prev1;
    
    int curr;
    for (int i = 3; i <= n; i++)
    {
        curr = (prev2 + prev1)* (k-1);
        prev2 = prev1;
        prev1 = curr;
    }
return curr;
}

int main(){
    int numOfPost = 5;
    int numOfColor = 3;

    cout<<"The total number of ways to fence the color : "<<solveUsingRecc(numOfPost, numOfColor)<<endl;

    vector<int> dp(numOfPost +1, -1);
    cout<<"The total number of ways to fence the color : "<<solveUsingMemoisation(numOfPost, numOfColor, dp)<<endl;

    cout<<"The total number of ways to fence the color : "<<solveUsingTabulation(numOfPost, numOfColor)<<endl;
    
    cout<<"The total number of ways to fence the color : "<<solveUsingTabulationOptimization(numOfPost, numOfColor)<<endl;
return 0;
}