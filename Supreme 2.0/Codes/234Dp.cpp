// Leetcode: 474. Ones and Zeroes

#include<iostream>
#include<utility>
#include<vector>

using namespace std;

void convertStrToNumStr(vector<string>& strs, vector<pair<int, int>> &numStr){
    for(auto str : strs){
        int zeros = 0, ones = 0;
        for(auto ch : str){
            if(ch =='0')zeros++;
            else ones++;
        }
    numStr.push_back({zeros, ones});
    }
}

int solveUsingRecc(vector<pair<int, int>> &numStr, int i, int m, int n){
    if(i>=numStr.size()) return 0;

    int zeros = numStr[i].first;
    int ones = numStr[i].second;
    int include = 0, exclude = 1;
    if(m-zeros >= 0 && n-ones >= 0) include = 1 + solveUsingRecc(numStr, i+1, m-zeros, n-ones);
    exclude = solveUsingRecc(numStr, i+1, m, n);

return max(include , exclude);
}

int solveUsingMemoisation(vector<pair<int, int>> &numStr, int i, int m, int n, vector<vector<vector<int> > > dp){
    if(i>=numStr.size()) return 0;
    if(dp[i][m][n] != -1) return dp[i][m][n];
    int zeros = numStr[i].first;
    int ones = numStr[i].second;
    int include = 0, exclude = 1;
    if(m-zeros >= 0 && n-ones >= 0) include = 1 + solveUsingMemoisation(numStr, i+1, m-zeros, n-ones, dp);
    exclude = solveUsingMemoisation(numStr, i+1, m, n, dp);

return dp[i][m][n] = max(include , exclude);
}

int solveUsingTabulation(vector<pair<int, int>> &numStr, int m, int n){
    vector<vector<vector<int>>> dp(numStr.size()+1, vector<vector<int>> (m+1, vector<int>(n+1, 0)));
    
    for (int i = numStr.size()-1; i >= 0; i--){
        for (int j = 0; j <= m; j++){
            for (int k = 0; k <= n; k++){
                int zeros = numStr[i].first;
                int ones = numStr[i].second;
                int include = 0, exclude = 1;
                if(j-zeros >= 0 && k-ones >= 0) include = 1 + dp[i+1][j-zeros][k-ones];
                exclude = dp[i+1][j][k];

            dp[i][j][k] = max(include , exclude);
            }
        }
    }
return dp[0][m][n];
}

void findMaxForm(vector<string>& strs, int &m, int &n) { 
    vector<pair<int, int>> numStr;
    convertStrToNumStr(strs, numStr);
    for(auto pr : numStr){
        cout<<pr.first<<" "<<pr.second<<endl;
    }cout<<endl;
    
    cout<<" the size of the largest subset of strs such that there are at most "<<m<<" 0's and "<<n<<" 1's in the subset : "<<solveUsingRecc(numStr, 0, m, n)<<endl; 

    vector<vector<vector<int>>> dp(numStr.size()+1, vector<vector<int>> (m+1, vector<int>(n+1, -1)));
    cout<<" the size of the largest subset of strs such that there are at most "<<m<<" 0's and "<<n<<" 1's in the subset : "<<solveUsingMemoisation(numStr, 0, m, n, dp)<<endl; 

    cout<<" the size of the largest subset of strs such that there are at most "<<m<<" 0's and "<<n<<" 1's in the subset : "<<solveUsingTabulation(numStr, m, n)<<endl; 
}

int main(){
    vector<string> strs = {"10","0001","111001","1","0"};
    int m = 5, n = 3;
    findMaxForm(strs, m, n);
return 0;
}