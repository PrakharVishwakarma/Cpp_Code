// Leetcode : 97 : interleaving-string.

#include<iostream>
#include<vector>
using namespace std;

bool solveUsingRecursion(string &s1, string &s2, string &s3, int i, int j, int k){
    if (i == s1.size() && j == s2.size() && k == s3.size())return true;

    bool flag = false;
    if (i < s1.size() && s3[k] == s1[i])
    {
        flag = flag || solveUsingRecursion(s1, s2, s3, i+1, j, k+1);
    }
    if (j < s2.size() && s3[k] == s2[j])
    {
        flag = flag || solveUsingRecursion(s1, s2, s3, i, j+1, k+1);
    }
return flag;
}

bool solveUsingMemoisation(string &s1, string &s2, string &s3, int i, int j, int k, vector<vector<vector<int>>> &dp){
    if (i == s1.size() && j == s2.size() && k == s3.size())return true;

    if(dp[i][j][k] != -1) return dp[i][j][k];

    bool flag = false;
    if (i < s1.size() && s3[k] == s1[i])
    {
        flag = flag || solveUsingMemoisation(s1, s2, s3, i+1, j, k+1, dp);
    }
    if (j < s2.size() && s3[k] == s2[j])
    {
        flag = flag || solveUsingMemoisation(s1, s2, s3, i, j+1, k+1, dp);
    }
    dp[i][j][k] = flag;
return dp[i][j][k];
}


bool solveUsingTabulation(string &s1, string &s2, string &s3){
    int n1 = s1.size(), n2 = s2.size(), n3 = s3.size();
    vector<vector<vector<int>>> dp(n1+1, vector<vector<int>> (n2+1, vector<int> (n3+1, 0)));
    dp[n1][n2][n3] = 1;
    for (int i =n1; i >= 0; i--){
        for (int j = n2; j >= 0; j--){
            for (int k = n3; k >= 0; k--){
                if(i == n1 && j == n2 && k == n3)continue;
                bool flag = false;
                if (i < n1 && s1[i] == s3[k])flag = flag || dp[i+1][j][k+1];
                if (j < n2 && s2[j] == s3[k])flag = flag || dp[i][j+1][k+1];
                dp[i][j][k] = flag;
            }
        }
    }
return dp[0][0][0];
}

void isInterleave(string &s1, string &s2, string &s3) {
    if(solveUsingRecursion(s1, s2, s3, 0, 0, 0))cout<<"s3 can formed by an interleaving of s1 and s2."<<endl;
    else cout<<"s3 can not formed by an interleaving of s1 and s2"<<endl;

    vector<vector<vector<int>>> dp(s1.size()+1, vector<vector<int>> (s2.size()+1, vector<int> (s3.size()+1, -1)));
    if(solveUsingMemoisation(s1, s2, s3, 0, 0, 0, dp))cout<<"s3 can formed by an interleaving of s1 and s2."<<endl;
    else cout<<"s3 can not formed by an interleaving of s1 and s2"<<endl;

    if(solveUsingTabulation(s1, s2, s3))cout<<"s3 can formed by an interleaving of s1 and s2."<<endl;
    else cout<<"s3 can not formed by an interleaving of s1 and s2"<<endl;

    if(solveUsingIterative(s1, s2, s3))cout<<"s3 can formed by an interleaving of s1 and s2."<<endl;
    else cout<<"s3 can not formed by an interleaving of s1 and s2"<<endl;
}

int main(){
    string s1= "aabcc", s2 = "dbbca", s3 = "aadbbcbc";
    // string s1 = "aabcc", s2 = "dbbca", s3 = "aadbbcbcac";
    isInterleave(s1, s2, s3);
return 0;
}