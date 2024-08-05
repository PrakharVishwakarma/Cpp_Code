// Leetcode : 72. Edit Distance
#include<iostream>
#include<vector>

using namespace std;


int solveUsingRecursion(string &a, string &b, int i, int j){
    if(i>=a.length()) return b.length() - j;
    if(j>=b.length()) return a.length() - i;

    int ans = 0;
    if (a[i] == b[j]){
        ans = 0 + solveUsingRecursion(a, b, i+1, j+1);
    }
    else{
        int replace = 1 + solveUsingRecursion(a, b, i+1, j+1 );
        int insert = 1 + solveUsingRecursion(a, b, i, j+1 );
        int removal = 1 + solveUsingRecursion(a, b, i+1, j );
    ans = min(replace, min(insert, removal));
    }
return ans;
}


int solveUsingMemoisation(string &a, string &b, int i, int j, vector<vector<int> > &dp){
    if(i>=a.length()) return b.length() - j;
    if(j>=b.length()) return a.length() - i;

    if(dp[i][j] != -1) return dp[i][j];

    int ans = 0;
    if (a[i] == b[j]){
        ans = 0 + solveUsingMemoisation(a, b, i+1, j+1, dp);
    }
    else{
        int replace = 1 + solveUsingMemoisation(a, b, i+1, j+1, dp);
        int insert = 1 + solveUsingMemoisation(a, b, i, j+1, dp);
        int removal = 1 + solveUsingMemoisation(a, b, i+1, j, dp);
    ans = min(replace, min(insert, removal));
    }
    dp[i][j] = ans;
return dp[i][j];
}

int solveUsingTabulation(string a, string b) {
    vector<vector<int> > dp(a.length()+1, vector<int>(b.length()+1, -1));

    for(int col=0; col<=b.length(); col++) {
        dp[a.length()][col] = b.length()-col;
    }
    for(int row=0; row<=a.length(); row++) {
        dp[row][b.length()] = a.length()-row;
    }

    for(int i_index=a.length()-1; i_index>=0; i_index--) {
        for(int j_index=b.length()-1; j_index>=0; j_index--) {
            int ans = 0;
            if(a[i_index] == b[j_index] ) {
                ans = 0 + dp[i_index+1][j_index+1];
            }
            else {
                int replace = 1 + dp[i_index+1][j_index+1];
                int insert = 1 + dp[i_index][j_index+1];
                int remove = 1 + dp[i_index+1][j_index];
                ans = min(insert,min(remove,replace));
            }
            dp[i_index][j_index] = ans;
        }
    }
return dp[0][0];
}

int solveUsingTabulationSO(string a, string b){
    vector<int> curr(a.length()+1, 0);
    vector<int> next(a.length()+1, 0);

    for (int row = 0; row <= a.length(); row++)
    {
        next[row] = a.length() - row;
    }

    for(int j_index=b.length()-1; j_index>=0; j_index--) {
        
        curr[a.length()] = b.length() - j_index; //m.Imp: Kyunki ek dibbe ka answer uske just niche vale dibbe par bhi toh depend kar raha hai.
        
        for(int i_index=a.length()-1; i_index>=0; i_index--) {
            int ans = 0;
            if(a[i_index] == b[j_index] ) {
                ans = 0 + next[i_index+1];
            }
            else {
                int replace = 1 + next[i_index+1];
                int insert = 1 + next[i_index];
                int remove = 1 + curr[i_index+1];
                ans = min(insert,min(remove,replace));
            }
            curr[i_index] = ans;
        }
        next = curr;
    }
return next[0];
}
    

void minDistance(string &word1, string &word2) {
    int i = 0;
    int j = 0;
    cout<<"minimum number of operations required to convert "<< word1 <<" to "<< word2 <<" is "<<solveUsingRecursion(word1, word2, i, j)<<endl;

    // Solve Using Memoisation: 
    vector<vector<int> > dp(word1.length()+1, vector<int>(word2.length()+1, -1));
    cout<<"minimum number of operations required to convert "<< word1 <<" to "<< word2 <<" is "<<solveUsingMemoisation(word1, word2, i, j, dp)<<endl;

    cout<<"minimum number of operations required to convert "<< word1 <<" to "<< word2 <<" is "<<solveUsingTabulation(word1, word2)<<endl;

    cout<<"minimum number of operations required to convert "<< word1 <<" to "<< word2 <<" is "<<solveUsingTabulationSO(word1, word2)<<endl;
}
int main()
{
    string word1 = "intention", word2 = "execution";
    minDistance(word1, word2);

return 0;
}
