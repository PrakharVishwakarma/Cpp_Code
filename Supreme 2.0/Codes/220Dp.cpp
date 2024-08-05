/*
140. Word Break II : Given a string s and a dictionary of strings wordDict, add spaces in s to construct a sentence where each word is a valid dictionary word. Return all such possible sentences in any order.
Note that the same word in the dictionary may be reused multiple times in the segmentation.
*/

#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

vector<string> solveUsingRecursion(string &s, unordered_map<string, bool> &dict, int i) {
    if(i == s.size()) return {""};

    vector<string> ans;
    string word;
    for (int start = i; start < s.size(); start++)
    {
        word.push_back(s[start]);
        if (dict.find(word) == dict.end())continue;

        auto rightKaSentence = solveUsingRecursion(s, dict, start + 1);
        for(auto eachRightPart : rightKaSentence){
            string endPart;
            if(eachRightPart.size() > 0)endPart = " " + eachRightPart;
            ans.push_back(word + endPart);
        }
    }
return ans;
}

vector<string> solveUsingMemoisation(string &s, unordered_map<string, bool> &dict, int i, unordered_map<int, vector<string> > &dp) {
    if(i == s.size()) return {""};

    if(dp.find(i) != dp.end()) return dp[i];

    vector<string> ans;
    string word;
    for (int start = i; start < s.size(); start++)
    {
        word.push_back(s[start]);
        if (dict.find(word) == dict.end())continue;

        auto rightKaSentence = solveUsingMemoisation(s, dict, start + 1, dp);
        for(auto eachRightPart : rightKaSentence){
            string endPart;
            if(eachRightPart.size() > 0)endPart = " " + eachRightPart;
            ans.push_back(word + endPart);
        }
    }
    dp[i] = ans;
return dp[i];
}
void wordBreak(string &s, vector<string>& wordDict) {
    unordered_map<string, bool> dict;
    for(auto word : wordDict) dict[word] = true;

    vector<string> ans = solveUsingRecursion(s, dict, 0);  
    for (auto i : ans)
    {
        cout<<i<<endl;
    }cout<<endl;
         
    unordered_map<int, vector<string> > dp;
    ans = solveUsingMemoisation(s, dict, 0, dp);  
    for (auto i : ans)
    {
        cout<<i<<endl;
    }
}

int main()
{
    string s = "pineapplepenapple";
    vector<string> wordDict= {"apple","pen","applepen","pine","pineapple"};
    wordBreak(s, wordDict);
return 0;
} 