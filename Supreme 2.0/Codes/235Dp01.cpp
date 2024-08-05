// Leetcode 801. Minimum Swaps To Make Sequences Increasing

#include<iostream>
#include<limits.h>
#include<limits>
#include<vector>
#include<algorithm>

using namespace std;

int solveUsingRecc(vector<int>& nums1, vector<int>& nums2, int i, int p1, int p2){
    if(i == nums1.size()) return 0;

    int doSwap = INT_MAX, dontSwap = INT_MAX;
    if(p1 < nums2[i] && p2 < nums1[i]) doSwap = 1 + solveUsingRecc(nums1, nums2, i+1, nums2[i], nums1[i]);
    if(p1 < nums1[i] && p2 < nums2[i]) dontSwap = solveUsingRecc(nums1, nums2, i+1, nums1[i], nums2[i]);
return min(doSwap, dontSwap);
}

int solveUsingMemoisation(vector<int>& nums1, vector<int>& nums2, int i, int p1, int p2, vector<vector<int>> &dp, int isSwap){
    if(i == nums1.size()) return 0;
    if(dp[i][isSwap] != -1) return dp[i][isSwap];
    int doSwap = INT_MAX, dontSwap = INT_MAX;
    if(p1 < nums2[i] && p2 < nums1[i]) doSwap = 1 + solveUsingMemoisation(nums1, nums2, i+1, nums2[i], nums1[i], dp, 1);
    if(p1 < nums1[i] && p2 < nums2[i]) dontSwap = solveUsingMemoisation(nums1, nums2, i+1, nums1[i], nums2[i], dp, 0);
return dp[i][isSwap] = min(doSwap, dontSwap);
}

int solveUsingTabulation(vector<int>& nums1, vector<int>& nums2){
    nums1.insert(nums1.begin(), -1);
    nums2.insert(nums2.begin(), -1);
    vector<vector<int>> dp(nums1.size()+1, vector<int>(2, 0));
    for (int i = nums1.size()-1; i >= 1; i--){
        for (int j = 1; j >= 0; j--){
            int p1 = nums1[i-1];
            int p2 = nums2[i-1];
            if(j)swap(p1, p2);

            int doSwap = INT_MAX, dontSwap = INT_MAX;
            if(p1 < nums2[i] && p2 < nums1[i]) doSwap = 1+ dp[i+1][1];
            if(p1 < nums1[i] && p2 < nums2[i]) dontSwap = dp[i+1][0];
            dp[i][j] = min(doSwap, dontSwap);   
        }
    }
return dp[1][0];
}
void minSwap(vector<int>& nums1, vector<int>& nums2) {
    cout<<"the minimum number of needed operations to make nums1 and nums2 strictly increasing are : "<<solveUsingRecc(nums1, nums2, 0, -1, -1)<<endl;

    vector<vector<int>> dp(nums1.size(), vector<int>(2, -1));
    cout<<"the minimum number of needed operations to make nums1 and nums2 strictly increasing are : "<<solveUsingMemoisation(nums1, nums2, 0, -1, -1, dp, 0)<<endl;

    cout<<"the minimum number of needed operations to make nums1 and nums2 strictly increasing are : "<<solveUsingTabulation(nums1, nums2);

}

int main(){
    vector<int> nums1 = {1,3,5,4};
    vector<int> nums2 = {1,2,3,7};
    minSwap(nums1, nums2);
    
return 0;
}