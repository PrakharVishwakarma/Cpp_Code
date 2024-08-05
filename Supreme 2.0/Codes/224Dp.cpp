// Leetcode:1406. Stone Game III

#include<iostream>
#include<vector>
#include<limits.h>
using namespace std;

int solveUsingRecursion(vector<int>& stoneValue, int i, int n){
    if(i == n) return 0;

    int ans = INT_MIN;
    int total = 0;
    for (int x = 1; x <= 3; x++)
    {
        if((i+x-1) >= n) break; 
        total += stoneValue[i+x-1];
        ans = max(ans, (total  - solveUsingRecursion(stoneValue, i+x, n)));
    }
    return ans;
}

int solveUsingMemoisation(vector<int>& stoneValue, int i, int n, vector<int> dp){
    if(i == n) return 0;

    if(dp[i] != -1) return dp[i];

    int ans = INT_MIN;
    int total = 0;
    for (int x = 1; x <= 3; x++)
    {
        if((i+x-1) >= n) break; 
        total += stoneValue[i+x-1];
        ans = max(ans, (total  - solveUsingMemoisation(stoneValue, i+x, n, dp)));
    }
    dp[i] = ans;
return dp[i]; 
}

int solveUsingTabulation(vector<int>& stoneValue, int n){
    vector<int> dp(n+1 , 0);

    for (int i = n-1; i >= 0; i--)
    {
        int ans = INT_MIN;
        int total = 0;
        for (int x = 1; x <= 3; x++)
        {
            if((i+x-1) >= n) break; 
            total += stoneValue[i+x-1];
            ans = max(ans, (total  - dp[i+x]));
        }
        dp[i] = ans;
    }
return dp[0];
}

void stoneGameIII(vector<int>& stoneValue) {
    int ans;
    // ans = solveUsingRecursion(stoneValue, 0, stoneValue.size());

    vector<int> dp(stoneValue.size()+1 , -1); 
    // ans = solveUsingMemoisation(stoneValue, 0, stoneValue.size(), dp);
     
    ans = solveUsingTabulation(stoneValue, stoneValue.size());
    
    if(ans < 0)cout<<"Bob has Won the game. "<< endl;
    else if(ans > 0)cout<<"Alice has Won the game. "<< endl;
    else cout<<"Game has been Tie."<< endl;
    
}

int main(){
    vector<int> stoneValue = {1,2,3,6};
    stoneGameIII(stoneValue);

return 0;
}