#include<iostream>
#include<vector>
#include<limits.h>
#include<algorithm>

using namespace std;


int solveUsingRecc(vector<int>& satisfaction, int i, int time){
    if(i == satisfaction.size()) return 0;

    int include = time*satisfaction[i] + solveUsingRecc(satisfaction, i+1, time+1);
    int exclude =  solveUsingRecc(satisfaction, i+1, time);
return max(include, exclude);
}

int solveUsingMemoisation(vector<int>& satisfaction, int i, int time, vector<vector<int>> &dp){
    if(i >= satisfaction.size()) return 0;
    if(dp[i][time] != -1) return dp[i][time];
    int include = time*satisfaction[i] + solveUsingMemoisation(satisfaction, i+1, time+1, dp);
    int exclude =  solveUsingMemoisation(satisfaction, i+1, time, dp);
return dp[i][time] = max(include, exclude);
}

int solveUsingTabulation(vector<int>& satisfaction){
    vector<vector<int>> dp(satisfaction.size()+1, vector<int>(satisfaction.size()+2, 0));    
    for (int i = satisfaction.size()-1; i >= 0; i--){
        for (int time = satisfaction.size(); time >= 0; time--){
            int include = time*satisfaction[i] + dp[i+1][time+1];
            int exclude =  dp[i+1][time];
        dp[i][time] = max(include, exclude);
        }
    }
    return dp[0][1];
}

void maxSatisfaction(vector<int>& satisfaction) {
    sort(satisfaction.begin(), satisfaction.end());
    cout<<" the maximum sum of like-time coefficient that the chef can obtain after preparing some amount of dishes : "<<solveUsingRecc(satisfaction, 0, 1)<<endl;

    vector<vector<int>> dp(satisfaction.size(), vector<int>(satisfaction.size()+1, -1));    
    cout<<" the maximum sum of like-time coefficient that the chef can obtain after preparing some amount of dishes : "<<solveUsingMemoisation(satisfaction, 0, 1, dp)<<endl;
    
    cout<<" the maximum sum of like-time coefficient that the chef can obtain after preparing some amount of dishes : "<<solveUsingTabulation(satisfaction)<<endl;

}

int main()
{
    vector<int> satisfaction = {-1,-8,0,5,-9};
    maxSatisfaction(satisfaction);

return 0;
}