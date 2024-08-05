/*
Leetcode 39: Combination Sum

Given an array of distinct integers candidates and a target integer target,
return a list of all unique combinations of candidates where the chosen numbers sum to target. 
You may return the combinations in any order.

*/

#include <iostream>
#include <vector>

using namespace std;

void CombSum(vector<int> &candidate, int index, int target, vector<int> &v)
{

    // Base Condition :
    if (target < 0)return;
    
    if (target == 0){
        for (int i = 0; i < v.size(); i++){
            cout<<v[i]<<" ";
        }
        cout<<endl;
        return;
    }

    for (int i = index; i < candidate.size(); i++){
        v.push_back(candidate[i]);
        // Recusion :
        CombSum(candidate, i, target - candidate[i], v);
        // backtracking :
        v.pop_back();  
    }
}
int main()
{

    vector<int> candidate = {2, 3, 5};
    vector<int> v;
    vector<vector<int>> ans;
    int target = 10;

    CombSum(candidate, 0, target, v);
    return 0;
}