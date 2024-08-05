/*
724. Find Pivot Index:
Given an array of integers nums, calculate the pivot index of this array.

The pivot index is the index where the sum of all the numbers strictly to the left of the index is equal to the sum of all the numbers strictly to the index's right.
*/

#include <iostream>
#include <cfloat>
#include <vector>
using namespace std;

int pivotIndex(vector<int> &nums)
{
    int n = nums.size();
    vector<int> leftSum(n, 0);
    vector<int> rightSum(n, 0);
    for (int i = 1; i < n; i++)
    {
        leftSum[i] = leftSum[i - 1] + nums[i - 1];
    }
    for (int i = n - 2; i >= 0; i--)
    {
        rightSum[i] = rightSum[i + 1] + nums[i + 1];
    }
    for (int i = 0; i < n; i++)
    {
        if (leftSum[i] == rightSum[i])
            return i;
    }
    return -1;
}

int main()
{
    vector<int> nums = {1, 7, 3, 6, 5, 6};
    int ans = pivotIndex(nums);
    if (ans != -1)
    {
        cout << "the leftmost pivot index." << ans;
    }
    else
    {
        cout << "no such index exists";
    }
    
    cout<<endl<<DBL_MIN;
    return 0;
}