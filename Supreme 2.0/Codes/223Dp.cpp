// Leetcode : 1140. Stone Game 2

#include<iostream>
#include<vector>
#include<limits.h>

using namespace std;

int solveUsingRecursion(vector<int>& piles, int i, int m, int n, bool alice){
    if(i == n) return 0;

    int total = 0;
    int ans = alice ? INT_MIN : INT_MAX;
    for (int x = 1; x <= 2*m; x++)
    {
        if((i+x-1) > n) break;

        total += piles[i+x-1]; 
        if(alice)ans = max(ans, (total + solveUsingRecursion(piles, i+x, max(m, x), n, !alice)));
        
        else ans = min(ans, solveUsingRecursion(piles, i+x, max(m, x), n, !alice));    
    }

return ans;
}

int solveUsingMemoisation(vector<int>& piles, int i, int m, int n, int alice, vector<vector<vector<int>>> &dp){
    if(i == n) return 0;

    if(dp[i][m][alice] != -1) return dp[i][m][alice];

    int total = 0;
    int ans = alice ? INT_MIN : INT_MAX;
    for (int x = 1; x <= 2*m; x++)
    {
        if((i+x-1) > n) break;

        total += piles[i+x-1]; 
        if(alice)ans = max(ans, (total + solveUsingMemoisation(piles, i+x, max(m, x), n, !alice, dp)));
        
        else ans = min(ans, solveUsingMemoisation(piles, i+x, max(m, x), n, !alice, dp));    
    }
    dp[i][m][alice] = ans;
return dp[i][m][alice];
}

int solveUsingTabulation(vector<int>& piles){
    int n = piles.size();
    vector<vector<vector<int>>> dp(piles.size()+1, vector<vector<int>> (piles.size()+1, vector<int> (2, 0)));

    for (int i = piles.size(); i >= 0; i--)
    {
        for (int m = piles.size(); m >= 0; m--)
        {
            for (int alice = 0; alice <= 1; alice++)
            {
                int total = 0;
                int ans = alice ? INT_MIN : INT_MAX;
                for (int x = 1; x <= 2*m; x++)
                {
                    if((i+x-1) > n) break;

                    total += piles[i+x-1]; 
                    if(alice)ans = max(ans, (total + dp[i+x][max(m, x)][!alice]));
                    
                    else ans = min(ans, dp[i+x][max(m, x)][!alice]);    
                }
            dp[i][m][alice] = ans;
            } 
        }
    }

return dp[0][1][2];
}
void stoneGame(vector<int>& piles) {
    cout<<"the maximum number of stones Alice can get : "<<solveUsingRecursion(piles, 0, 1, piles.size(), true)<<endl;

    // vector<vector<vector<int>>> dp(piles.size()+1, vector<vector<int>> (piles.size()+1, vector<int> (2, -1)));
    // cout<<"the maximum number of stones Alice can get : "<<solveUsingMemoisation(piles, 0, 1, piles.size(), 1, dp)<<endl;

    // cout<<"the maximum number of stones Alice can get : "<<solveUsingTabulation(piles)<<endl;
     
}

int main(){
    
    vector<int> piles = {2,7,9,4,4};
    stoneGame(piles);

return 0;
}