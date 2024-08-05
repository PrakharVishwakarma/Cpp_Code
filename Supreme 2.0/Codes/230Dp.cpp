// 1671. Minimum Number of Removals to Make Mountain Array

#include<iostream>
#include<vector>
#include<algorithm>
#include<limits.h>
using namespace std;

int solveUsingBinarySearch(vector<int> &num, vector<int> &lis) {
    if (num.size() == 0)return 0;
    
    vector<int> ans;
    //initial state
    ans.push_back(num[0]);
    lis.push_back(1);
    for(int i=1; i<num.size(); i++) {
        if(num[i] > ans.back()) {
            ans.push_back(num[i]);
            lis.push_back(ans.size());
        }
        else {
            //just bada number exist krta hai
            int index = lower_bound(ans.begin(), ans.end(), num[i]) - ans.begin();
            // the function lower_bound returns an iterator pointing to the next smallest number just greater than or equal to that number.
            //replace 
            ans[index] = num[i];
            lis.push_back(index+1);
        }
    }
    return ans.size();
}

int minimumMountainRemovals(vector<int>& nums) {
    vector<int>lis;
    solveUsingBinarySearch(nums, lis);
    for(auto i : lis)cout<<i<<" ";
    cout<<endl;

    vector<int>lds;
    reverse(nums.begin(), nums.end());
    solveUsingBinarySearch(nums, lds);
    for (int i = 0; i < lds.size(); i++)cout<<lds[lds.size()-i-1]<<" ";
    cout<<endl;
    
    int ans = INT_MIN;
    for (int i = 0; i < nums.size(); i++)
    {
        if(lis[i] == 1 || lds[lds.size()-i-1] == -1) continue;
        ans = max(ans , (lis[i] + lds[lds.size()-i-1]) - 1);
    }
    
    return nums.size() - ans;
}

int main(){
    vector<int> nums = {2,1,1,5,6,2,3,1};
    cout<<"The minimum number of elements to remove to make mountain array : "<<minimumMountainRemovals(nums);

return 0;
}