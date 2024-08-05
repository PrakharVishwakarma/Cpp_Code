// Leetcode 239: Sliding window maximum.

#include<iostream>
#include<vector>
#include<deque>

using namespace std;
vector<int> maxSlidingWindow(vector<int>& nums, int k) {
    vector<int>ans;
    deque<int> dq;

    for (int i = 0; i < k; i++)
    {
        int element = nums[i];
        while (!dq.empty() && element > dq.back())
        {
            dq.pop_back();
        }
        dq.push_back(i);
    }
    
    for (int i = k; i < nums.size(); i++)
    {
        ans.push_back(nums[dq.front()]);
        if (i-dq.front() >= k)
        {
            dq.pop_front();
        }
        int element = nums[i];
        while (!dq.empty() && element > dq.back())
        {
            dq.pop_back();
        }
        dq.push_back(i);
    }
    ans.push_back(nums[dq.front()]);
return ans;
}

int main()
{
    vector<int> nums = {1,3,-1,-3,5,3,6,7};
    int k = 3;
    vector<int>ans = maxSlidingWindow(nums , k);
    for (int i = 0; i < ans.size(); i++)
    {
        cout<<ans[i]<<" ";
    }
    
return 0;
}