// Leetcode 714. Best Time to Buy and Sell Stock with Transaction Fee.

#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int solveUsingRecc(vector<int>& prices, int i, int buying, int &fee){
    if(i>=prices.size()) return 0;

    int profit = 0;
    if(buying){
        int buyItProfit = -prices[i] + solveUsingRecc(prices, i+1, 0, fee);
        int skipItsProfit = solveUsingRecc(prices, i+1, 1, fee);
        profit = max(buyItProfit, skipItsProfit);
    }
    else{
        int sellItProfit = prices[i] + solveUsingRecc(prices, i+1, 1, fee)-fee;
        int skipItsProfit = solveUsingRecc(prices, i+1, 0, fee);
        profit = max(sellItProfit, skipItsProfit);
    }
return profit;
}

int solveUsingMemoisation(vector<int>& prices, int i, int buying, vector<vector<int> > &dp, int &fee){
    if(i>=prices.size()) return 0;

    if(dp[i][buying] != -1) return dp[i][buying];

    int profit = 0;
    if(buying){
        int buyItProfit = -prices[i] + solveUsingMemoisation(prices, i+1, 0, dp, fee);
        int skipItsProfit = solveUsingMemoisation(prices, i+1, 1, dp, fee);
        profit = max(buyItProfit, skipItsProfit);
    }
    else{
        int sellItProfit = prices[i] + solveUsingMemoisation(prices, i+1, 1, dp, fee) - fee;
        int skipItsProfit = solveUsingMemoisation(prices, i+1, 0, dp, fee);
        profit = max(sellItProfit, skipItsProfit);
    }
return dp[i][buying] = profit;
}

int solveUsingTabulation(vector<int>& prices, int &fee){
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
                    int sellItProfit = prices[i] + dp[i+1][1] - fee;
                    int skipItsProfit = dp[i+1][0];
                    profit = max(sellItProfit, skipItsProfit);
                }
            dp[i][buying] = profit;
        }
    }
return dp[0][1];
}  

int solveUsingTabulationSO(vector<int>& prices, int &fee){
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
                    int sellItProfit = prices[i] + dp[1][1] - fee;
                    int skipItsProfit = + dp[1][0];
                    profit = max(sellItProfit, skipItsProfit);
                }
            dp[0][buying] = profit;
        }
        dp[1]=dp[0];
    }
return dp[0][1];
} 

void maxProfit(vector<int>& prices, int &fee) {
    cout<<"The maximum profit you can achieve is : "<<solveUsingRecc(prices, 0, 1, fee);
    
    vector<vector<int> > dp(prices.size(), vector<int> (2, -1));
    cout<<endl<<"The maximum profit you can achieve is : "<<solveUsingMemoisation(prices, 0, 1, dp, fee);

    cout<<endl<<"The maximum profit you can achieve is : "<<solveUsingTabulation(prices, fee);
    
    cout<<endl<<"The maximum profit you can achieve is : "<<solveUsingTabulationSO(prices, fee);
}

int main(){
    vector<int> prices = {1,3,2,8,4,9};
    int fee = 2;
    maxProfit(prices, fee);

return 0;
}