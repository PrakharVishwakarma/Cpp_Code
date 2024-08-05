/*
Leetcode : 539. Minimum Time Difference
    Input: timePoints = ["23:59","00:00"]
    Output: 1

*/

#include<iostream>
#include<vector>
#include<algorithm>
#include<limits.h>
using namespace std;

int strToMinutes(string &str){
    int hours = stoi(str.substr(0,2));
    int minutes = stoi(str.substr(3,2));
    return hours*60 + minutes;
}
int findMinDifference(vector<string>& timePoints) {
    vector<int> mins;

    for (auto str : timePoints)mins.push_back(strToMinutes(str));
    
    sort(mins.begin(), mins.end());

    int ans = INT_MAX;
    for (int i = 0; i < mins.size()-1; i++){
        ans = min(ans, mins[i+1]-mins[i]);
    }

    // Edge case is :
    int lastDiff = mins[0] + 1440 - mins[mins.size()-1];
    return min(ans, lastDiff);
}
int main(){
    vector<string> timePoints = {"22:59","00:15","06:30","16:17"};
    cout<<" the minimum minutes difference between any two time-points in the list is : "<<findMinDifference(timePoints)<<endl;

return 0;
}