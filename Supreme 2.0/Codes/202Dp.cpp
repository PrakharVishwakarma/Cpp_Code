// Leetcode 302 : Coin Change 

#include<iostream>
#include<vector>
#include<limits.h>

using namespace std;

int solveUsingRecc(vector<int>& coins, int amount){
    if (amount == 0)
        return 0;
        
    int mini = INT_MAX;
    for (int i = 0; i < coins.size(); i++)
    {
        if (amount - coins[i] >= 0)     // In case the amount is -ve then to handle it 
        {
            int recursionKaAns = solveUsingRecc(coins, amount-coins[i]);
            if (recursionKaAns != INT_MAX)
            {
                int ans = 1 + recursionKaAns;
                mini = min(mini, ans);
            }
        }
    }
return mini;
}   

int solveUsingMemoisation(vector<int>& coins, int amount, vector<int> &dp){
    if (amount == 0)
        return 0;
    
    if(dp[amount] != -1) return dp[amount];

    int mini = INT_MAX;
    for (int i = 0; i < coins.size(); i++)
    {
        if (amount - coins[i] >= 0)
        {
            int recursionKaAns = solveUsingMemoisation(coins, amount-coins[i], dp);
            if (recursionKaAns != INT_MAX){
                int ans = 1 + recursionKaAns;
                mini = min(mini, ans);
            }
        }
    }
    dp[amount] = mini;
return dp[amount];
}   

int solveUsingTabulation(vector<int> &coins, int amount){
    int n = amount;
    vector<int> dp(n+1, INT_MAX);
    
    dp[0] = 0;

    for (int i = 1; i <= amount; i++)
    {
        int mini = INT_MAX;
        for (int i = 0; i < coins.size(); i++)
        {
            if (i - coins[i] >= 0)
            {
                int recursionKaAns = dp[i -coins[i]];
                if (recursionKaAns != INT_MAX){
                    int ans = 1 + recursionKaAns;
                    mini = min(mini, ans);
                }
            }
        }
        dp[i] = mini;
    }
    return dp[amount];
}
void coinChange(vector<int>& coins, int amount) {
    // Using simple recursion : 
    int ans = solveUsingRecc(coins, amount);
    if (ans == INT_MAX){
        cout<<"fewest number of coins that are need to make up that amount : "<<amount<<" is "<<-1<<endl;   
    }
    else {
        cout<<"fewest number of coins that are need to make up that amount : "<<amount<<" is "<<ans<<endl;
    }

    // Using Memoisation:
    vector<int> dp(amount+1, -1);
    int ans2 = solveUsingMemoisation(coins, amount, dp);
    if (ans2 == INT_MAX){
        cout<<"fewest number of coins that are need to make up that amount : "<<amount<<" is "<<-1<<endl;   
    }
    else {
        cout<<"fewest number of coins that are need to make up that amount : "<<amount<<" is "<<ans<<endl;
    }

    // Using Tabulation:
    int ans3 = solveUsingTabulation(coins, amount);
    if (ans3 == INT_MAX){
        cout<<"fewest number of coins that are need to make up that amount : "<<amount<<" is "<<-1<<endl;   
    }
    else {
        cout<<"fewest number of coins that are need to make up that amount : "<<amount<<" is "<<ans<<endl;
    }

    // Solve using space optimization : 
    // No space optimization possible.
}    

int main(){
    vector<int> coins = {2};
    int amount = 3;
    coinChange(coins, amount);
return 0;
}