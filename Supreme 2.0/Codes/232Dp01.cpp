// 122. Best Time to Buy and Sell Stock II

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int solveUsingRecc(vector<int>& prices, int i, int buying){
    if(i>=prices.size()) return 0;

    int profit = 0;
    if(buying){
        int buyItProfit = -prices[i] + solveUsingRecc(prices, i+1, 0);
        int skipItsProfit = solveUsingRecc(prices, i+1, 1);
        profit = max(buyItProfit, skipItsProfit);
    }
    else{
        int sellItProfit = prices[i] + solveUsingRecc(prices, i+1, 1);
        int skipItsProfit = solveUsingRecc(prices, i+1, 0);
        profit = max(sellItProfit, skipItsProfit);
    }
return profit;
}

int solveUsingMemoisation(vector<int>& prices, int i, int buying, vector<vector<int> > dp){
    if(i>=prices.size()) return 0;

    if(dp[i][buying] != -1) return dp[i][buying];

    int profit = 0;
    if(buying){
        int buyItProfit = -prices[i] + solveUsingMemoisation(prices, i+1, 0, dp);
        int skipItsProfit = solveUsingMemoisation(prices, i+1, 1, dp);
        profit = max(buyItProfit, skipItsProfit);
    }
    else{
        int sellItProfit = prices[i] + solveUsingMemoisation(prices, i+1, 1, dp);
        int skipItsProfit = solveUsingMemoisation(prices, i+1, 0, dp);
        profit = max(sellItProfit, skipItsProfit);
    }
return dp[i][buying] = profit;
}

int solveUsingTabulation(vector<int>& prices){
    int n = prices.size();
    vector<vector<int> > dp(n+1, vector<int> (2, 0));

    for (int i = n-1; i >= 0; i--){
        for (int buying = 0; buying < 2; buying++){
                int profit = 0;
                if(buying){
                    int buyItProfit = -prices[i] + dp[i+1][0];
                    int skipItsProfit = dp[i+1][1];
                    profit = max(buyItProfit, skipItsProfit);
                }
                else{
                    int sellItProfit = prices[i] + dp[i+1][1];
                    int skipItsProfit = dp[i+1][0];
                    profit = max(sellItProfit, skipItsProfit);
                }
            dp[i][buying] = profit;
        }
    }
return dp[0][1];
}   

int solveUsingTabulationSO(vector<int>& prices){
    vector<vector<int> > dp(2, vector<int> (2, 0));

    for (int i = prices.size()-1; i >= 0; i--){
        for (int buying = 0; buying < 2; buying++){
                int profit = 0;
                if(buying){
                    int buyItProfit = -prices[i] + dp[1][0];
                    int skipItsProfit = + dp[1][1];
                    profit = max(buyItProfit, skipItsProfit);
                }
                else{
                    int sellItProfit = prices[i] + dp[1][1];
                    int skipItsProfit = + dp[1][0];
                    profit = max(sellItProfit, skipItsProfit);
                }
            dp[0][buying] = profit;
        }
        dp[1]=dp[0];
    }
return dp[0][1];
}   

int maxProfit(vector<int>& prices) {
    // int ans = solveUsingRecc(prices, 0, true);
    
    // vector<vector<int> > dp(prices.size(), vector<int> (2, -1));
    // int ans = solveUsingMemoisation(prices, 0, true, dp);

    // int ans = solveUsingTabulation(prices);

    int ans = solveUsingTabulationSO(prices);

    return ans;
}

int main(){
    vector<int> prices = {7,1,5,3,6,4};
    cout<<"The maximum profit you can achieve : "<<maxProfit(prices);
return 0;
}