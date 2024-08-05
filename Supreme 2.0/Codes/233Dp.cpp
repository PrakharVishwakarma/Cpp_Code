// Leetcode 494. Target Sum

#include<iostream>
#include<vector>
#include<utility>
#include<map>

using namespace std;

int solveUsingRecc(vector<int>& nums, int target, int i){
    if(i>=nums.size()) return target==0 ? 1 : 0;

    int way1 = solveUsingRecc(nums, target-nums[i], i+1);
    int way2 = solveUsingRecc(nums, target+nums[i], i+1);
return way1+way2;
}

int solveUsingMemoisation(vector<int>& nums, int target, int i, map<pair<int, int>, int> &dp){
    if(i>=nums.size()) return target==0 ? 1 : 0;

    if(dp.find({i, target}) != dp.end()) return dp[{i, target}];

    int way1 = solveUsingMemoisation(nums, target-nums[i], i+1, dp);
    int way2 = solveUsingMemoisation(nums, target+nums[i], i+1, dp);
return dp[{i, target}] = way1+way2;
}

int solveUsingTabulation(vector<int>& nums, int &target){
    map<pair<int, int>, int> dp;
    int n = nums.size();
    dp[{n, 0}] = 1;

    int total = 0;
    for(auto num: nums) total+=num;

    for (int i = n-1; i >= 0; i--){
        for(int sum = -total; sum <= total; sum++){
            int way1 = (dp.find({i+1, sum-nums[i]}) != dp.end()) ? dp[{i+1, sum-nums[i]}] : 0;
            int way2 = (dp.find({i+1, sum+nums[i]}) != dp.end()) ? dp[{i+1, sum+nums[i]}] : 0;
        dp[{i, sum}] = way1+way2;
        }
    }
return dp[{0, target}];
}
void findTargetSumWays(vector<int>& nums, int &target) {
    int i = 0;
    cout<<"There are "<<solveUsingRecc(nums, target, i)<<" ways to assign symbols to make the sum of nums be target "<<target<<endl;

    map<pair<int, int>, int> dp;
    cout<<"There are "<<solveUsingMemoisation(nums, target, i, dp)<<" ways to assign symbols to make the sum of nums be target "<<target<<endl;

    cout<<"There are "<<solveUsingTabulation(nums, target)<<" ways to assign symbols to make the sum of nums be target "<<target<<endl;

}

int main(){
    vector<int> nums = {1,1,1,1,1};
    int target = 3;
    findTargetSumWays(nums, target);
return 0;
}