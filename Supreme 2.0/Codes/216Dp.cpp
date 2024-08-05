// Leetcode : 712 Minimum ASCII delete Sum for two strings

#include<iostream>
#include<vector>
using namespace std;

int solveUsingRecursion(string &s1, string &s2, int i, int j){
    int cost = 0;
    if(i >= s1.size() || j >= s2.size()){
        for (int x = i; x < s1.size(); x++) cost+=s1[x]; 
        for (int x = j; j < s2.size(); j++) cost+=s2[x];
    }   

    else if(s1[i] == s2[j]){
        cost = solveUsingRecursion(s1, s2, i+1, j+1);
    } 
    
    else{
        int cost1 = s1[i] + solveUsingRecursion(s1, s2, i+1, j);
        int cost2 = s2[j] + solveUsingRecursion(s1, s2, i, j+1);
        cost = min(cost1, cost2);
    }
    return cost;
}

int solveUsingMemoisation(string &s1, string &s2, int i, int j, vector<vector<int> > &dp){
    int cost = 0;

    if(dp[i][j] != -1) return dp[i][j];

    if(i >= s1.size() || j >= s2.size()){
        for (int x = i; x < s1.size(); x++) cost+=s1[x]; 
        for (int x = j; j < s2.size(); j++) cost+=s2[x];
    }   

    else if(s1[i] == s2[j]){
        cost = solveUsingMemoisation(s1, s2, i+1, j+1, dp);
    } 
    
    else{
        int cost1 = s1[i] + solveUsingMemoisation(s1, s2, i+1, j, dp);
        int cost2 = s2[j] + solveUsingMemoisation(s1, s2, i, j+1, dp);
        cost = min(cost1, cost2);
    }
    dp[i][j] = cost;
    return dp[i][j];
}

int solveUsingTabulation(string &s1, string &s2){
    vector<vector<int> >dp(s1.size()+1, vector<int> (s2.size()+1, 0));

// Base Case : 
    // dp[s1.size()][s2.size()] = 0;    //Already dp is initialized with 0
    for (int i = s1.size()-1; i >= 0; i--)
    {
        dp[i][s2.size()] = s1[i] + dp[i+1][s2.size()]; 
    }
    for (int i = s2.size()-1; i >= 0; i--)
    {
        dp[s1.size()][i] = s2[i] + dp[s1.size()][i+1]; 
    }

// Insert the values in the dp array : 
    for (int i = s1.size()-1; i >= 0; i--)
    {
        for (int j = s2.size()-1; j >= 0; j--){
            int cost = 0;
            if(s1[i] == s2[j]){
                cost = dp[i+1][j+1];
            } 
            
            else{
                int cost1 = s1[i] + dp[i+1][j];
                int cost2 = s2[j] + dp[i][j+1];
                cost = min(cost1, cost2);
            }
            dp[i][j] = cost;
        }
    }
    return dp[0][0];
}



void minimumDeleteSum(string s1, string s2) {
    cout<<"the lowest ASCII sum of deleted characters to make two strings equal is : "<<solveUsingRecursion(s1, s2, 0, 0) <<endl;       

    vector<vector<int> >dp(s1.size()+1, vector<int> (s2.size()+1, -1));
    cout<<"the lowest ASCII sum of deleted characters to make two strings equal is : "<<solveUsingMemoisation(s1, s2, 0, 0, dp) <<endl;       
    
    cout<<"the lowest ASCII sum of deleted characters to make two strings equal is : "<<solveUsingTabulation(s1, s2) <<endl;       

}

int main(){

    string s1 = "delete";
    string s2 = "leet";
    minimumDeleteSum(s1, s2);
return 0;
}