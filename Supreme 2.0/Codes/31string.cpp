// Leetcode 179 : 179. Largest Number
/*
Given a list of non-negative integers nums, arrange them such that they form the largest number and return it.Since the result may be very large,
so you need to return a string instead of an integer.

Input: nums = [3,30,34,5,9]
Output: "9534330"

*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

static bool cmp(string &a, string &b)
{
    return (a + b) > (b + a);
}

string largestNumber(vector<int> &nums){
    vector<string> str;
    for (auto i : nums)
    {
        str.push_back(to_string(i));
    }
    sort(str.begin(), str.end(), cmp);
    if (str[0] == "0")
        return "0";
    string ans = "";
    for (auto i : str)
    {
        ans += i;
    }
    return ans;
}

int main(){
    vector<int>nums = {3,30,34,5,9};
    cout<<largestNumber(nums);
}