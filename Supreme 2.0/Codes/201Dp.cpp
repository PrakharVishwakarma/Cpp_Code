// Leetcode 198 : House Robber

#include<iostream>
#include<vector>
using namespace std;

int solveUsingRecc(vector<int>& nums, int index){
    if (index >= nums.size())return 0;
    
    int include = nums[index] + solveUsingRecc(nums, index+2);
    int exclude = 0 + solveUsingRecc(nums, index+1);
    int ans = max(include, exclude);
return ans; 
}
 
int solveUsingMemoisation(vector<int>& nums, int index, vector<int> &dp){
    if (index >= nums.size())return 0;

    if(dp[index] != -1) return dp[index];

    int include = nums[index] + solveUsingMemoisation(nums, index+2, dp);
    int exclude = 0 + solveUsingMemoisation(nums, index+1, dp);
    dp[index] = max(include, exclude);
return dp[index];
}

int solveUsingTabulation(vector<int>& nums){
    int n = nums.size();
    vector<int> dp(n, -1);

    dp[n-1] = nums[n-1];    //Matlab (n-1)th index ke right me jitna answer ban raha hai. Last index par hain toh us ghar me jitna paisa hai utna sara chori kiiya jayega 

    for (int i = n-2; i >= 0; i--)
    {
        int tempAns = 0;
        if(i+2 < n) tempAns = dp[i + 2];

        int include = nums[i] + tempAns;
        int exclude = 0 + dp[i+1];
        dp[i] = max(include, exclude);
    }
return dp[0];
}

int solveUsingTabulationOptimization(vector<int>& nums){
    int n = nums.size();
    int forward = nums[n-1];
    int nextOfForward = 0;
    int curr = 0;

    for (int i = n-2; i >= 0; i--)
    {
        int tempAns = 0;
        if(i+2 < n) tempAns = nextOfForward;

        int include = nums[i] + tempAns;
        int exclude = 0 + forward;
        curr = max(include, exclude);
        nextOfForward = forward;
        forward = curr;
    }
return forward;     // We are not returning currrent cause in case of single house code fat jayega.
}

int rob(vector<int>& nums) {
    int index = 0;
    // int ans = solveUsingRecc(nums, index);

    // Solve using memoisation
    /* int n = nums.size();
    vector<int> dp(n, -1); 
    int ans = solveUsingMemoisation(nums, index, dp); */

    // int ans = solveUsingTabulation(nums);
    
    int ans = solveUsingTabulationOptimization(nums);

    return ans;
}

int main(){
    vector<int>nums = {2,7,9,3,1};
    cout<<"Maximum amount of money you can rob tonight without alerting the police : "<<rob(nums)<<endl;

return 0;
}