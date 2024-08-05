// Leetcode : 1155. Number of Dice Rolls With Target Sum

#include<iostream>
#include<vector>

using namespace std;

long long int MOD = 1000000007;

int solveUsingRecursion(int n, int &k, int target){
    if(target == 0 && n == 0) return 1;
    if(target != 0 && n == 0) return 0;
    if(target == 0 && n != 0) return 0;

    int ans = 0;
    for (int i = 1; i <= k; i++)
    {
        int reccKaAns = 0;
        if(target - i >= 0){
            reccKaAns = solveUsingRecursion(n-1, k, target-i) ;
        }
        ans = (ans + reccKaAns);
    }
    return ans;
}

int solveUsingMemoisation(int n, int &k, int target, vector<vector<int> >&dp){
    if(target == 0 && n == 0) return 1;
    if(target != 0 && n == 0) return 0;
    if(target == 0 && n != 0) return 0;

    if(dp[n][target] != -1) return dp[n][target];

    int ans = 0;
    for (int i = 1; i <= k; i++)
    {
        int reccKaAns = 0;
        if(target - i >= 0){
            reccKaAns = solveUsingMemoisation(n-1, k, target-i, dp);
        }
        ans = (ans + reccKaAns);
    }
    dp[n][target] = ans;
return dp[n][target];
}

int solveUsingTabulation(int n, int &k, int target){
    vector<vector<int> >dp(n+1, vector<int> (target+1, 0));

    dp[0][0] = 1;

    for (int num = 1; num <= n; num++)
    {
        for (int tgt = 1; tgt <= target ; tgt++)
        {
            int ans = 0;
            for (int i = 1; i <= k; i++)
            {
                int reccKaAns = 0;
                if(tgt - i >= 0){
                    reccKaAns = dp[num-1][tgt-i];
                }
                ans = (ans + reccKaAns);
            }
            dp[num][tgt] = ans;  
        }
    }
return dp[n][target];
}

void numRollsToTarget(int &n, int &k, int &target) {
    
    cout<<"Numbers of Ways to get a sum "<<target<< " is : "<<solveUsingRecursion(n, k, target)<<endl;

    vector<vector<int> >dp(n+1, vector<int> (target+1, -1));
    cout<<"Numbers of Ways to get a sum "<<target<< " is : "<<solveUsingMemoisation(n, k, target, dp)<<endl;

    cout<<"Numbers of Ways to get a sum "<<target<< " is : "<<solveUsingTabulation(n, k, target)<<endl;

}

int main(){
    int n = 2; 
    int k = 6; 
    int target = 7;
    numRollsToTarget(n, k, target);

return 0;
}
