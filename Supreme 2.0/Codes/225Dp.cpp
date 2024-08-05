/* 
312. Burst Balloons
You are given n balloons, indexed from 0 to n - 1. Each balloon is painted with a number on it represented by an array nums. You are asked to burst all the balloons.
*/

#include<iostream>
#include<vector>
#include<limits.h>
using namespace std;

int solveUsingRecc(vector<int>& nums, int s, int e){
    if(s>e) return 0;
    int ans = INT_MIN;
    for (int i = s; i <= e; i++){
        ans = max(ans, ((nums[s-1]*nums[i]*nums[e+1]) + solveUsingRecc(nums, s, i-1) + solveUsingRecc(nums, i+1, e)));
    }
    return ans;
} 

int solveUsingMemoisation(vector<int>& nums, int s, int e, vector<vector<int> >&dp){
    if(s>e) return 0;
    int ans = INT_MIN;
    if(dp[s][e] != -1) return dp[s][e]; 
    for (int i = s; i <= e; i++){
        ans = max(ans, ((nums[s-1]*nums[i]*nums[e+1]) + solveUsingMemoisation(nums, s, i-1, dp) + solveUsingMemoisation(nums, i+1, e, dp)));
    }
    return dp[s][e] = ans;
} 

int solveUsingTabulation(vector<int>& nums){
    int n = nums.size();
    vector<vector<int> >dp(n, vector<int> (n, 0));

    for (int start = n-2; start >= 1; start--)
    {
        for (int end = start; end <= n-2; end++)
        {
            int ans = INT_MIN;
            for (int i = start; i <= end; i++){
                ans = max(ans, ((nums[start-1]*nums[i]*nums[end+1]) + dp[start][i-1] + dp[i+1][end]));
            }
            dp[start][end] = ans;
        }
    }
return dp[1][n-2];
} 


void maxCoins(vector<int>& nums) {
    nums.insert(nums.begin(), 1);
    nums.insert(nums.end(), 1);
    
    int n = nums.size();
    cout<<"The maximum coins you can collect by bursting the balloons wisely : "<<solveUsingRecc(nums, 1, n - 2);
    vector<vector<int> >dp(n, vector<int> (n, -1));
    cout<<endl<<"The maximum coins you can collect by bursting the balloons wisely : "<<solveUsingMemoisation(nums, 1, n - 2, dp);
    cout<<endl<<"The maximum coins you can collect by bursting the balloons wisely : "<<solveUsingTabulation(nums);

}

int main(){
    vector<int> nums = {3,1,5,8};
    maxCoins(nums);
return 0;
}