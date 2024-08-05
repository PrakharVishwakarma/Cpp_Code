#include<iostream>
#include<vector>
#include<limits.h>

using namespace std;

int solveUsingRecc(vector<int>& nums, int s, int e){
    if(s>=e) return nums[s];
    int diffByStart = nums[s] - solveUsingRecc(nums, s+1, e);
    int diffByEnd = nums[e] - solveUsingRecc(nums, s, e-1);
return max(diffByStart, diffByEnd); 
}

int solveUsingMemoisation(vector<int>& nums, int s, int e, vector<vector<int>> &dp){
    if(s>=e) return nums[s];
    if(dp[s][e] != -1) return dp[s][e];
    int diffByStart = nums[s] - solveUsingMemoisation(nums, s+1, e, dp);
    int diffByEnd = nums[e] - solveUsingMemoisation(nums, s, e-1, dp);
return dp[s][e] = max(diffByStart, diffByEnd); 
}

int solveUsingTabulation(vector<int>& nums){
    int n = nums.size();
    vector<vector<int>> dp(n, vector<int>(n+1, -1));
    for (int i = 0; i < n; i++)dp[i][i] = nums[i];
    
    int i = n;
    for (int s = n-1; s >= 0; s--){
        for (int e = i; e < n; e++){
            int diffByStart = nums[s] - dp[s+1][e];
            int diffByEnd = nums[e] - dp[s][e-1];  
        dp[s][e] = max(diffByStart, diffByEnd); 
        }
        --i;
    }
return dp[0][n-1];
}

bool predictTheWinner(vector<int>& nums) {
    // return solveUsingRecc(nums, 0, nums.size()-1) >= 0;
    
    // vector<vector<int>> dp(nums.size(), vector<int>(nums.size(), -1));
    // return solveUsingMemoisation(nums, 0, nums.size()-1, dp) >= 0;

    return solveUsingTabulation(nums) >= 0;

}

int main(){
    vector<int> nums = {1,5,233,7};
    bool canPlayerOnewin = predictTheWinner(nums);
    if(canPlayerOnewin)cout<<" Player 1 can win the game. "<<endl;
    else cout<<" Player 1 can not win the game. "<<endl;
    
return 0;
}