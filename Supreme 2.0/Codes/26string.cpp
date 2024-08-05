// Leetcode : 49 : Group anagram.
/*
Input: strs = ["eat","tea","tan","ate","nat","bat"]
Output: [["bat"],["nat","tan"],["ate","eat","tea"]]
*/

#include <iostream>
#include <vector>
#include <array>
#include <algorithm>
#include <map>
using namespace std;

void groupAnagrams(vector<string> &strs, vector<vector<string>> &ans)
{
    map<string, vector<string>> mp;

    for (auto str : strs)
    {
        string s = str;
        sort(s.begin(), s.end());
        mp[s].push_back(str);
    }

    for (auto i = mp.begin(); i != mp.end(); i++)
    {
        ans.push_back(i->second);
    }

}

/* Method second
std::array<int, 256> hash(string str){
    std::array<int, 256> hash={0};
    for(auto ch: str) hash[ch]++;
    return hash;
}

vector<vector<string>> groupAnagramsUsingHashAyyay(vector<string>& strs, vector<vector<string>> &ans) {
        map<std::array<int, 256 >, vector<string>> mp;
        for (auto str : strs){
            mp[hash(str)].push_back(str);
        }
        vector<vector<string>> ans;
        for (auto i = mp.begin(); i != mp.end(); i++)ans.push_back(i->second);
    return ans; 
}
*/

int main()
{
    vector<string> strs = {"eat", "tea", "tan", "ate", "nat", "bat"};

    vector<vector<string>> ans;
    groupAnagrams(strs, ans);
    for (int i = 0; i < ans.size(); ++i)
    {
        for (int j = 0; j < ans[i].size(); ++j)
        {
            cout << ans[i][j] << " ";
        }
        cout << std::endl;
    }cout<<endl;

    // vector<vector<string>> ans2;
    // groupAnagramsUsingHashAyyay(strs, ans2);
    // for (int i = 0; i < ans2.size(); ++i)
    // {
    //     for (int j = 0; j < ans2[i].size(); ++j)
    //     {
    //         cout << ans2[i][j] << " ";
    //     }
    //     cout << std::endl;
    // }
    return 0;
}


