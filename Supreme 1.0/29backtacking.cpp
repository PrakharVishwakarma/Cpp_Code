// Leet code 40 : Combination 2

#include <iostream>
#include <algorithm>
#include <vector>
#include <set>

using namespace std;

void CombSum(vector<int> &candidate, int index, int target, vector<int> &v, vector<vector<int>> &ans)
{

    // Base Condition :
    if (target < 0)return;
    
    if (target == 0)
    {
        ans.push_back(v);
        return;
    }

    for (int i = index; i < candidate.size(); i++)
    {
        if (i > index && candidate[i] == candidate[i-1])
        {
            continue;
        }
        
        v.push_back(candidate[i]);
        // Recusion :
        CombSum(candidate, i + 1, target - candidate[i], v, ans);
        // backtracking :
        v.pop_back();
    }
}
int main()
{

    vector<int> candidate = {10,1,2,7,6,1,5};
    sort(candidate.begin(), candidate.end());
    vector<int> v;
    vector<vector<int>> ans;

    int target = 8;

    CombSum(candidate, 0, target, v, ans);

    for(auto vec : ans){
        for(auto element : vec){
            cout<<element<<" ";
        }cout<<endl;
    }
    return 0;
}