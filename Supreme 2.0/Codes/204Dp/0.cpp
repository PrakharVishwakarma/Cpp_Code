// 0/1 KnapSack Problem: 

#include<iostream>
#include<vector>

using namespace std;

int solveUsingRecc(int capacity, vector<int> wt, vector<int> profit, int i, int n){
    if(i >= n)return 0;
    // if (i == n-1)
    // {
    //     if (wt[i]<= capacity)return profit[i];
    //     else return 0;
    // }
    
    int include = 0;
    if (wt[i]<= capacity)
    {
        include = profit[i] + solveUsingRecc(capacity-wt[i], wt, profit, i+1, n);
    }
    int exclude = 0 + solveUsingRecc(capacity, wt, profit, i+1, n);
return max(include, exclude);
}

int solveUsingMemoisation(int capacity, vector<int> wt, vector<int> profit, int i, int n, vector<vector<int> > &dp){
    if(i >= n)return 0;

    if(dp[capacity][i] != -1) return dp[capacity][i];

    int include = 0;
    if (wt[i] <= capacity)
    {
        include = profit[i] + solveUsingMemoisation(capacity-wt[i], wt, profit, i+1, n, dp);
    }
    int exclude = 0 + solveUsingMemoisation(capacity, wt, profit, i+1, n, dp);
    
    dp[capacity][i] = max(include, exclude);

return dp[capacity][i];
}

int solveusingtabulation(int capacity, vector<int> wt, vector<int> profit, int n){
    vector<vector<int> > dp(capacity + 1 , vector<int>(n+1, -1));    

    for (int row = 0; row <= capacity; row++)
    {
        dp[row][n] = 0;
    }
    
    for (int row = 0; row <= capacity; row++)
    {
        for (int col = n-1; col >= 0; col--)
        {
            int include = 0;
            if (wt[col] <= row)
            {
                include = profit[col] + dp[row-wt[col]][col+1];
            }
            int exclude = 0 + dp[row][col+1];
            
            dp[row][col] = max(include, exclude);   
        } 
    }
    
return dp[capacity][0];   
}

 

int main(){
    int capacity = 50;
    vector<int> wt = {10, 20, 30};
    vector<int> profit = {60, 100, 120};
    int index = 0;
    int n = wt.size();

    int ans = solveUsingRecc(capacity, wt, profit, index, n);
    cout<<"Maximum Profit achieved with this knapsack : "<<ans<<endl;

    vector<vector<int> > dp(capacity + 1 , vector<int>(n+1, -1));
    cout<<"Maximum Profit achieved with this knapsack : "<<solveUsingMemoisation(capacity, wt, profit, index, n, dp)<<endl;

    cout<<"Maximum Profit achieved with this knapsack : "<<solveusingtabulation(capacity, wt, profit, n)<<endl;



return 0;
}

