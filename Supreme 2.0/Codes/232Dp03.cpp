
#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int solveUsingRecc(vector<int>& prices, int i, int buying, int limit){
    if(i>=prices.size() || limit == 0) return 0;

    int profit = 0;
    if(buying){
        int buyItProfit = -prices[i] + solveUsingRecc(prices, i+1, 0, limit);
        int skipItsProfit = solveUsingRecc(prices, i+1, 1, limit);
        profit = max(buyItProfit, skipItsProfit);
    }
    else{
        int sellItProfit = prices[i] + solveUsingRecc(prices, i+1, 1, limit-1);
        int skipItsProfit = solveUsingRecc(prices, i+1, 0, limit);
        profit = max(sellItProfit, skipItsProfit);
    }
return profit;
}

int solveUsingMemoisation(vector<int>& prices, int i, int buying, int limit, vector<vector<vector<int>>> &dp){
    if(i>=prices.size() || limit == 0) return 0;
    if(dp[i][buying][limit] != -1) return dp[i][buying][limit];
    int profit = 0;
    if(buying){
        int buyItProfit = -prices[i] + solveUsingMemoisation(prices, i+1, 0, limit, dp);
        int skipItsProfit = solveUsingMemoisation(prices, i+1, 1, limit, dp);
        profit = max(buyItProfit, skipItsProfit);
    }
    else{
        int sellItProfit = prices[i] + solveUsingMemoisation(prices, i+1, 1, limit-1, dp);
        int skipItsProfit = solveUsingMemoisation(prices, i+1, 0, limit, dp);
        profit = max(sellItProfit, skipItsProfit);
    }
return dp[i][buying][limit] = profit;
}

int solveUsingTabulation(vector<int>& prices, int k){
    int n = prices.size();
    vector<vector<vector<int>>> dp(n+1, vector<vector<int> >(2, vector<int>(k+1, 0)));

    for (int i = n-1; i >= 0; i--){
        for (int buying = 0; buying < 2; buying++){
            for (int limit = 1; limit < k+1; limit++){
                int profit = 0;
                if(buying){
                    int buyItProfit = -prices[i] + dp[i+1][0][limit];
                    int skipItsProfit = + dp[i+1][1][limit];
                    profit = max(buyItProfit, skipItsProfit);
                }
                else{
                    int sellItProfit = prices[i] + dp[i+1][1][limit-1];
                    int skipItsProfit = + dp[i+1][0][limit];
                    profit = max(sellItProfit, skipItsProfit);
                }
            dp[i][buying][limit] = profit;
            }
        }
    }
return dp[0][1][k];
}

int solveUsingTabulationSO(vector<int>& prices, int k){
    vector<vector<vector<int>>> dp(2, vector<vector<int> >(2, vector<int>(k+1, 0)));

    for (int i = prices.size()-1; i >= 0; i--){
        for (int buying = 0; buying < 2; buying++){
            for (int limit = 1; limit < k+1; limit++){
                int profit = 0;
                if(buying){
                    int buyItProfit = -prices[i] + dp[1][0][limit];
                    int skipItsProfit = + dp[1][1][limit];
                    profit = max(buyItProfit, skipItsProfit);
                }
                else{
                    int sellItProfit = prices[i] + dp[1][1][limit-1];
                    int skipItsProfit = + dp[1][0][limit];
                    profit = max(sellItProfit, skipItsProfit);
                }
            dp[0][buying][limit] = profit;
            }
        }
        dp[1] = dp[0];
    }
return dp[0][1][k];
}

void maxProfit(int k, vector<int>& prices) {
    cout<<"The maximum profit you can achieve is : "<<solveUsingRecc(prices, 0, true, k);

    vector<vector<vector<int>>> dp(prices.size(), vector<vector<int> >(2, vector<int>(k+1, -1)));
    cout<<endl<<"The maximum profit you can achieve is : "<<solveUsingMemoisation(prices, 0, true, k, dp);

    cout<<endl<<"The maximum profit you can achieve is : "<<solveUsingTabulation(prices, k);

    cout<<endl<<"The maximum profit you can achieve is : "<<solveUsingTabulationSO(prices, k);

}

int main(){
    int k = 2;
    vector<int> prices = {3,2,6,5,0,3};
    maxProfit(k, prices);


return 0;
}