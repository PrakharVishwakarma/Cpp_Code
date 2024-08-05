// Leetcode 139 : Word Break.

#include<iostream>
#include<vector>
using namespace std;

bool checkInDict(string &s, vector<string>& wordDict){
    for (auto i:wordDict){
        if(s == i) return true;
    }
    return false;
}

bool solveUsingRecursion(string &s, vector<string>& wordDict, int start){
    if(start == s.size()) return true;

    string word = "";
    bool flag = false;
    for (int i = start; i < s.size(); i++)
    {
        word += s[i];
        if(checkInDict(word, wordDict)){
            flag = flag || solveUsingRecursion(s, wordDict, i+1);
        }
    }
    return flag;
}

bool solveUsingMemoisation(string &s, vector<string>& wordDict, int start, vector<int> &dp){
    if(start == s.size()) return true;

    if(dp[start] != -1) return dp[start];

    string word = "";
    bool flag = false;
    for (int i = start; i < s.size(); i++)
    {
        word += s[i];
        if(checkInDict(word, wordDict)){
            flag = flag || solveUsingMemoisation(s, wordDict, i+1, dp);
        }
    }
    dp[start] = flag;
    return dp[start];
}

bool solveUsingTabulation(string &s, vector<string>& wordDict, int start){
    vector<bool> dp(s.size()+1 , true); 


    for (int start = s.size()-1; start >= 0; start--)
    {
        string word = "";
        bool flag = false;
        for (int i = start; i < s.size(); i++)
        {
            word += s[i];
            if(checkInDict(word, wordDict)){
                flag = flag || dp[i+1];
            }
        }        
    dp[start] = flag;
    }
return dp[0];
}

bool wordBreak(string &s, vector<string>& wordDict) {

    if ((solveUsingRecursion(s, wordDict, 0))){
        cout<<"String "<<s<< " can be segmented into a space-separated sequence of one or more dictionary words."<<endl;
    }
    else {
        cout<<"String "<<s<< " can not be segmented into a space-separated sequence of one or more dictionary words."<<endl;
    }
    
    vector<int> dp(s.size()+1 , -1);
    if ((solveUsingMemoisation(s, wordDict, 0, dp))){
        cout<<"String "<<s<< " can be segmented into a space-separated sequence of one or more dictionary words."<<endl;
    }
    else {
        cout<<"String "<<s<< " can not be segmented into a space-separated sequence of one or more dictionary words."<<endl;
    }

    if ((solveUsingTabulation(s, wordDict, 0))){
        cout<<"String "<<s<< " can be segmented into a space-separated sequence of one or more dictionary words."<<endl;
    }
    else {
        cout<<"String "<<s<< " can not be segmented into a space-separated sequence of one or more dictionary words."<<endl;
    }
}

int main(){
    string s = "applepenapple";
    vector<string> wordDict = {"apple","pen"};

    wordBreak(s, wordDict);

return 0;
}