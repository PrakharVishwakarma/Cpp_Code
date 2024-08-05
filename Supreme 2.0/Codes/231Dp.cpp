// 1187. Make Array Strictly Increasing

#include<iostream>
#include<vector>
#include <limits>
#include <algorithm>
#include <map>
#include <utility>

#define INF (1e9 + 1)

using namespace std;

int solveUsingRecc(vector<int>& arr1, vector<int>& arr2, int prev, int i){
    if(i>= arr1.size()) return 0;

    int option1 = INF;
    if(prev<arr1[i]) option1 = solveUsingRecc(arr1, arr2, arr1[i], i+1);

    int option2 = INF;
    auto it = upper_bound(arr2.begin(), arr2.end(), prev);
    if(it != arr2.end()){
        int index = it- arr2.begin();
        // arr1[i] = arr2[index];
        // option2 = 1 + solveUsingRecc(arr1, arr2, arr1[i], i+1);
        // since we don't want to modify the original array then
        option2 = 1 + solveUsingRecc(arr1, arr2, arr2[index], i+1);
    }
return min(option1, option2);
}

int solveUsingMemoisation(vector<int>& arr1, vector<int>& arr2, int prev, int i, map<pair<int, int>, int> &dp){
    if(i>= arr1.size()) return 0;
    if(dp.find({prev, i})!=dp.end()) return dp[{prev, i}];
    int option1 = INF;
    if(prev<arr1[i]) option1 = solveUsingMemoisation(arr1, arr2, arr1[i], i+1, dp);

    int option2 = INF;
    auto it = upper_bound(arr2.begin(), arr2.end(), prev);
    if(it != arr2.end()){
        int index = it- arr2.begin();
        // arr1[i] = arr2[index];
        // option2 = 1 + solveUsingRecc(arr1, arr2, arr1[i], i+1);
        // since we don't want to modify the original array then
        option2 = 1 + solveUsingMemoisation(arr1, arr2, arr2[index], i+1, dp);
    }
return dp[{prev, i}] = min(option1, option2);
}

int makeArrayIncreasing(vector<int>& arr1, vector<int>& arr2) {
    // int ans = solveUsingRecc(arr1, arr2, -1, 0); 
    map<pair<int, int>, int> dp;
    int ans = solveUsingMemoisation(arr1, arr2, -1, 0, dp);   
    sort(arr2.begin(), arr2.end());
    if(ans!= INF)return ans;
    else return -1;
}

int main(){
    vector<int> arr1 = {1,5,3,6,7}, arr2 = {1,3,2,4};
    cout<<"The minimum number of operations (possibly zero) needed to make arr1 strictly increasing are : "<<makeArrayIncreasing(arr1, arr2);
return 0;
}
