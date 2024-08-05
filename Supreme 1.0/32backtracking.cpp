// Distributing repeating integer : Leetcode1655

#include<iostream>
#include<vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

bool distributeHelper(vector<int> &counts, vector<int> &quantity, int ithCust){
    if(ithCust >= quantity.size()) return true;

    for (int i = 0; i < counts.size(); i++)
    {
        if (counts[i] >= quantity[ithCust])
        {
            counts[i] -= quantity[ithCust];
            if(distributeHelper(counts, quantity, ithCust+1)){
                return true;
            }   
            counts[i] += quantity[ithCust];
        }
    }
    return false;
}

bool canDistribute(vector<int>& nums, vector<int>& quantity) {
    unordered_map<int, int> countMap;
    for(auto num : nums)countMap[num]++;
    
    vector<int>counts;
    for(auto i : countMap)counts.push_back(i.second);

    sort(quantity.rbegin(), quantity.rend());
    return distributeHelper(counts, quantity, 0);
}

int main()
{
    vector<int> nums = {1,1,2,2}; 
    vector<int> quantity = {2,2};
    
    string isPossible = canDistribute(nums, quantity) == true ? "yes" : "no";
    cout<<"Possible to distribute : "<<isPossible;
return 0;
}






/*
#include <iostream>
using namespace std;

void remove(string &s, int start)
{
    if (start >= s.size())
        return;
    for (int i = start + 1; i < s.size(); i++)
    {
        if (s[i] == s[start])
            s.erase(s.begin() + i);
    }
    remove(s, start + 1);
}
int main(){
    string s = "bcabc";
    remove(s,0);
    cout<<s;
    return 0;
}
*/

/*
#include <iostream>
using namespace std;

void remove(string &s, int start)
{
    if (start >= s.size())
        return;
    for (int i = start+1 ; i < s.size(); i++){
        if (s[start] == s[i]){
            s.erase(s.begin());
            continue;
        }
        if (start>0 && s[start] == s[start-1]) s.erase(s.begin() + (start-1));
    }
    remove(s, start + 1);
}
int main(){
    string s = "bcabc";
    remove(s,0);
    cout<<s;
    return 0;
}
*/