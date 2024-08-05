// Leetcode : 416. Partition Equal Subset Sum. 

#include<iostream>
#include<vector>
using namespace std;

bool solveUsingRecursion(vector<int> &nums, int index, int sum, int target){
    if(index > nums.size()) return 0;
    if(sum > target) return 0;
    if(sum == target) return true;

    bool include = solveUsingRecursion(nums, index+1, sum+nums[index], target);
    bool exclude = solveUsingRecursion(nums, index+1, sum, target);
return include || exclude;
}

bool solveUsingMemoisation(vector<int> &nums, int index, int sum, int target, vector<vector<int> > &dp){
    if(index > nums.size()) return 0;
    if(sum > target) return 0;
    if(sum == target) return true; 

    if(dp[index][sum] != -1) return dp[index][sum];

    bool include = solveUsingMemoisation(nums, index+1, sum+nums[index], target, dp);
    bool exclude = solveUsingMemoisation(nums, index+1, sum, target, dp);
    dp[index][sum] = (include || exclude);
return dp[index][sum];
}

bool solveUsingTabulation(vector<int> &nums, int target){
    int n = nums.size();
    vector<vector<int> > dp(nums.size()+1, vector<int> (target+1, 0));
    for (int row = 0; row <= n; row++)
    {
        dp[row][target] = 1;
    }
    
    for (int ind = n-1; ind >= 0 ; ind--)
    {
        for (int s = target; s >= 0; s--)
        {
            bool include = (s+nums[ind]) <= target ? dp[ind+1][s+nums[ind]] : 0;    // Dp ke andar jo index access kar rahe hain make sure vo valid hon.
            bool exclude = dp[ind+1][s];   
            dp[ind][s] = (include || exclude);
        }
    }
return dp[0][0];
}

bool solveUsingTabulationSO(vector<int> &nums, int target){
    int n = nums.size();
    vector<int>curr(target+1, 0);
    vector<int>next(target+1, 0);

    curr[target] = 1;
    next[target] = 1;
    
    for (int ind = n-1; ind >= 0 ; ind--)
    {
        for (int s = target; s >= 0; s--)
        {
            bool include = (s+nums[ind]) <= target ? next[s+nums[ind]] : 0;    // Dp ke andar jo index access kar rahe hain make sure vo valid hon.
            bool exclude = next[s];   
            curr[s] = (include || exclude);
            
            next = curr;
        }
    }
return next[0];
}

void canPartition(vector<int>& nums) {
    int totalSum = 0;
    for (int i = 0; i < nums.size(); i++)
    {
        totalSum += nums[i];
    }

    if(totalSum & 1){   // Total Sum is odd.
        cout<<"the array can not partition into two subsets such that the sum of the elements in both subsets is equal "<<endl;
        return;
    }
    else{
        int target = totalSum/2;
        int index = 0;
        int currSum = 0;
        if(solveUsingRecursion(nums, index, currSum, target)){
            cout<<"the array can partition into two subsets such that the sum of the elements in both subsets is equal "<<endl;
        }
        else{
            cout<<"the array can not partition into two subsets such that the sum of the elements in both subsets is equal "<<endl;
        }

        // Solve Using Memoisation : 
        vector<vector<int> > dp(nums.size()+1, vector<int> (target+1, -1));
        if(solveUsingMemoisation(nums, index, currSum, totalSum, dp)){
            cout<<"the array can partition into two subsets such that the sum of the elements in both subsets is equal "<<endl;
        }
        else{
            cout<<"the array can not partition into two subsets such that the sum of the elements in both subsets is equal "<<endl;
        }

        // Solve Using Tabulation: 
        if(solveUsingTabulation(nums, target)){
            cout<<"the array can partition into two subsets such that the sum of the elements in both subsets is equal "<<endl;
        }
        else{
            cout<<"the array can not partition into two subsets such that the sum of the elements in both subsets is equal "<<endl;
        }
        // Solve using Tabulation Optimizatio;
        if(solveUsingTabulationSO(nums, target)){
            cout<<"the array can partition into two subsets such that the sum of the elements in both subsets is equal "<<endl;
        }
        else{
            cout<<"the array can not partition into two subsets such that the sum of the elements in both subsets is equal "<<endl;
        }
    }
}

int main(){
    vector<int>nums = {1,5,11,5};
    canPartition(nums);

return 0;
}