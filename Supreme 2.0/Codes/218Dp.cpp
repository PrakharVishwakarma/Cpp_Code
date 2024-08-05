/*
115. Distinct Subsequences : Given two strings s and t, return the number of distinct subsequences of s which equals t.
The test cases are generated so that the answer fits on a 32-bit signed integer.
*/

#include <iostream>
#include <vector>
using namespace std;

int solveUsingRecursion(string &s, string &t, int i, int j)
{
    if (j == t.size())
        return 1;

    if (i == s.size())
        return 0;

    int ans = 0;
    if (s[i] == t[j])
        ans += solveUsingRecursion(s, t, i + 1, j + 1);

    ans += solveUsingRecursion(s, t, i + 1, j);

    return ans;
}

int solveUsingMemoisation(string &s, string &t, int i, int j, vector<vector<int>> &dp)
{
    if (j == t.size())return 1;

    if (i == s.size())return 0;

    if (dp[i][j] != -1)return dp[i][j];

    int ans = 0;
    if (s[i] == t[j])
        ans += solveUsingMemoisation(s, t, i + 1, j + 1, dp);

    ans += solveUsingMemoisation(s, t, i + 1, j, dp);

    dp[i][j] = ans;
    return dp[i][j];
}

int solveUsingTabulation(string &s, string &t){
    vector<vector<int>> dp(s.size() + 1, vector<int>(t.size() + 1, 0));
    for (int i = t.size(); i >= 0 ; i--)
    {
        dp[i][t.size()] = 1;
    }

    for (int i = s.size()-1; i >= 0; i--)
    {
        for (int j = t.size()-1; j >= 0; j--){
            int ans = 0;
            if (s[i] == t[j])
                ans += solveUsingMemoisation(s, t, i + 1, j + 1, dp);

            ans += solveUsingMemoisation(s, t, i + 1, j, dp);
            dp[i][j] = ans;
        }
    }
return dp[0][0];
}

void numDistinct(string &s, string &t)
{
    cout << "the number of distinct subsequences of " << s << "which equals " << t << " are : " << solveUsingRecursion(s, t, 0, 0) << endl;

    vector<vector<int>> dp(s.size() + 1, vector<int>(t.size() + 1, -1));
    cout<< "the number of distinct subsequences of " << s << "which equals " << t << " are : " << solveUsingMemoisation(s, t, 0, 0, dp) << endl;

    cout << "the number of distinct subsequences of " << s << "which equals " << t << " are : " << solveUsingTabulation(s, t) << endl;
}

int main()
{
    string s = "babgbag", t = "bag";
    numDistinct(s, t);

    return 0;
}