// 354. Russian Doll Envelopes

#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

bool checkCriteria(vector<int> &curr, vector<int> &prev){
    if (prev[0] < curr[0] && prev[1] < curr[1])
    {
        return true;
    }
    else{ 
        return false;
    }
    
}

int solveUsingTabulationSO(vector<vector<int>> &env){
    int n = env.size();

    vector<int> currRow(n+1, 0); 
    vector<int> nextRow(n+1, 0); 

    for (int curr_index = n-1; curr_index >= 0; curr_index--){
        for (int prev_index = curr_index-1 ; prev_index >= -1; prev_index--)
        {
            int include = 0;
            if (prev_index == -1 || checkCriteria(env[curr_index], env[prev_index])){
                include = 1 + nextRow[curr_index+1];   
            } 
            int exclude = 0 + nextRow[prev_index+1];   
            currRow[prev_index+1] = max(include, exclude);   
        }   
        nextRow = currRow;
    }
    return nextRow[0]
}

void maxEnvelopes(vector<vector<int>>& envelopes) {
     sort(envelopes.begin(), envelopes.end());
     int ans = solveUsingTabulationSO(envelopes);
     cout<<"the maximum number of envelopes you can Russian doll : "<<ans<<endl;   

}

int main(){
    vector<vector<int>>envelopes = {{5,4},{6,4},{6,7},{2,3}};
    maxEnvelopes(envelopes);
return 0;
}