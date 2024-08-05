// Leetcode 213. House Robber II : [All houses at this place are arranged in a circle. That means the first house is the neighbor of the last one.]
/*
Input: nums = [2,3,2]
Output: 3
Explanation: You cannot rob house 1 (money = 2) and then rob house 3 (money = 2), because they are adjacent houses.
*/

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int houseRobber(vector<int>& lootInHouses , int index, int lastindex){
        
        if (index > lastindex) return 0;
        
        int isGharKichoriKaro = lootInHouses[index] +houseRobber(lootInHouses , index+2 , lastindex);
        int isGharKichoriNiKaro = 0 + houseRobber(lootInHouses , index+1, lastindex);
return max(isGharKichoriKaro , isGharKichoriNiKaro);
}

int main(){
    vector<int>nums = {2,3,2};
    int n = nums.size();
    if(n==1){
        cout<<nums[0];
    }
    else{
    int option1 = houseRobber(nums,0,n-2);
    int option2 = houseRobber(nums,1,n-1);
    cout<<max(option1,option2);
    } 
return 0;
}