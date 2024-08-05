/*Leetcode-300: Longest Increasing Subsequence: 
Given an integer array nums, return the length of the longest strictly increasing subsequence
.*/

#include<iostream>
#include<vector>
using namespace std;

int solveUsingRecursion(vector<int>& nums, int curr, int prev){
    if (curr >= nums.size())return 0;

    int include = 0;
    if (prev == -1 || nums[curr] > nums[prev]) {
        include = 1 + solveUsingRecursion(nums, curr+1, curr);
    } 
    int exclude = 0 + solveUsingRecursion(nums, curr+1, prev); 
    int ans = max(include, exclude);
return ans;
}

int solveUsingMemoisation(vector<int>& nums, int curr, int prev, vector<vector<int> > &dp){
    if (curr >= nums.size())return 0; 

    if(dp[curr][prev+1] != -1) return dp[curr][prev+1];  // prev = -1 pass ho raha hai aur vo ek valid index nii hai isiliye index shift karna padega to the nearest index then (prev) ki jagah par (prev+1).

    int include = 0;
    if (prev == -1 || nums[curr] > nums[prev]) {
        include = 1 + solveUsingMemoisation(nums, curr+1, curr, dp);
    } 
    int exclude = 0 + solveUsingMemoisation(nums, curr+1, prev, dp); 
    dp[curr][prev+1] = max(include, exclude);

return dp[curr][prev+1];
}

int solveUsingTabulation(vector<int>nums){
    // vector< vector<int> >dp(n+1, vector<int> (n+1, -1));
    // According to base case : 
    int n = nums.size();
    vector< vector<int> >dp(n+1, vector<int> (n+1, 0));

    for (int curr_index = n-1; curr_index >= 0; curr_index--)
    {
        for (int prev_index = curr_index-1 ; prev_index >= -1; prev_index--)
        {
            int include = 0;
            if (prev_index == -1 || nums[curr_index] > nums[prev_index]) {
                include = 1 + dp[curr_index+1][curr_index+1];   // Shifting of prev
            } 
            int exclude = 0 + dp[curr_index+1][prev_index+1];   // Shifting of prev
            dp[curr_index][prev_index+1] = max(include, exclude);   
        }   
    }
return dp[0][-1+1];     //Shifting of prev
}

int solveUsingTabulationSO(vector<int>nums){
    // vector< vector<int> >dp(n+1, vector<int> (n+1, -1));
    // According to base case : 
    int n = nums.size();
    vector<int> currRow(n+1, 0); 
    vector<int> nextRow(n+1, 0); 

    for (int curr_index = n-1; curr_index >= 0; curr_index--)
    {
        for (int prev_index = curr_index-1 ; prev_index >= -1; prev_index--)
        {
            int include = 0;
            if (prev_index == -1 || nums[curr_index] > nums[prev_index]) {
                include = 1 + nextRow[curr_index+1];   
            } 
            int exclude = 0 + nextRow[prev_index+1];   
            currRow[prev_index+1] = max(include, exclude);   
        }   
        nextRow = currRow;
    }
return nextRow[0];     //Shifting of prev
}

int solveUsingBinarySearch(vector<int>& num ) {
    if (num.size() == 0)return 0;
    
    vector<int> ans;
    //initial state
    ans.push_back(num[0]);
    
    for(int i=1; i<num.size(); i++) {
        if(num[i] > ans.back()) {
            ans.push_back(num[i]);
        }
        else {
            //just bada number exist krta hai
            int index = lower_bound(ans.begin(), ans.end(), num[i]) - ans.begin();
            // the function lower_bound returns an iterator pointing to the next smallest number just greater than or equal to that number.
            //replace 
                ans[index] = num[i];
        }
    }
    cout<<endl;
    for (int i = 0; i < ans.size(); i++)
    {
        cout<<ans[i]<<" ";
    }
    
    return ans.size();
}

void lengthOfLIS(vector<int>& nums){
    int curr = 0;
    int prev = -1;

    cout<<"The longest increasing subsequence is "<<solveUsingRecursion(nums, curr, prev);

    int n = nums.size();
    vector< vector<int> >dp(n+1, vector<int> (n+1, -1));
    cout<<endl<<"The longest increasing subsequence is "<<solveUsingMemoisation(nums, curr, prev, dp);

    cout<<endl<<"The longest increasing subsequence is "<<solveUsingTabulation(nums);

    cout<<endl<<"The longest increasing subsequence is "<<solveUsingTabulationSO(nums);

    cout<<endl<<"The longest increasing subsequence is "<<solveUsingBinarySearch(nums);
}


int main(){
    vector<int>nums = {10,9,2,5,3,7,101,18};
    lengthOfLIS(nums);

return 0;
}