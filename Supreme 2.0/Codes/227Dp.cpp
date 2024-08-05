// 1312. Minimum Insertion Steps to Make a String Palindrome

#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int solveUsingTabulationOptimization(string &a, string &b){
    vector<int> curr(a.length()+1, 0);
    vector<int> next(a.length()+1, 0);

    int ans = 0;
    for (int j = b.length()-1; j >= 0; j--){
        for (int i = a.length()-1; i >= 0; i--){
            if (a[i] == b[j])ans = 1 + next[i+1];
            else ans = 0 + max(curr[i+1], next[i]);                    
            curr[i] = ans;
        }
        next = curr;
    }
return next[0];
}
int longestPalindromeSubseq(string &s) {
    string reverseStr = s;
    reverse(reverseStr.begin(), reverseStr.end());
    return solveUsingTabulationOptimization(s, reverseStr);
}

int solveUsingRecc(string &s, int start, int end){
    if(start>=end) return 0;

    if(s[start] == s[end]) return solveUsingRecc(s, start+1, end-1); 
    else{
        int leftInsertion = 1 + solveUsingRecc(s, start, end-1);
        int rightInsertion = 1 + solveUsingRecc(s, start+1, end);
        return min(leftInsertion, rightInsertion);
    }
}

int solveUsingMemoisation(string &s, int start, int end, vector<vector<int> >&dp){
    if(start>=end) return 0;
    
    if(dp[start][end] != -1) return dp[start][end];

    if(s[start] == s[end]) return solveUsingMemoisation(s, start+1, end-1, dp); 
    else{
        int leftInsertion = 1 + solveUsingMemoisation(s, start, end-1, dp);
        int rightInsertion = 1 + solveUsingMemoisation(s, start+1, end, dp);
        dp[start][end] = min(leftInsertion, rightInsertion);
    }
return dp[start][end];
}

void minInsertions(string &s) {
    cout<<s.size() - longestPalindromeSubseq(s);
    int start = 0;
    int n = s.size();
    int end = n-1;
    cout<<endl<<solveUsingRecc(s, start, end);
    vector<vector<int>>dp(n,vector<int>(n,-1));
    cout<<endl<<solveUsingMemoisation(s, start, end, dp);

}

int main(){
    string s = "mbadm";
    minInsertions(s);

return 0; 
}