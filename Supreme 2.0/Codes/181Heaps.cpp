// Leetcode 239 : Sliding Window max : 

#include<iostream>
#include<queue>
#include<vector>
using namespace std;

vector<int> maxSlidingWindow(vector<int>& nums, int k) {
    priority_queue<pair<int, int>>pq;
    vector<int>ans;
    for (int i = 0; i < k; ++i)
        pq.push({nums[i], i});
    
    ans.push_back(pq.top().first);

    for (int i = k; i < nums.size(); i++)
    {
        pq.push({nums[i], i});
        while (pq.top().second <= i-k)
        {
            pq.pop();
        }
        
    ans.push_back(pq.top().first);
    }
return ans;        
}

int main(){
    vector<int>nums = {1,3,-1,-3,5,3,6,7}; 
    int k = 3;
    vector<int>ans = maxSlidingWindow(nums, k);
    cout<<"Sliding Window max : ";
    for (int i = 0; i < ans.size(); i++)
    {
        cout<<ans[i]<<" ";
    }
    
return 0;
}