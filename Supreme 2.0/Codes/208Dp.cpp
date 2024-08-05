// Leetcode : 1691 : Maximum Height by Stacking Cuboids : 

#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

bool checkCriteria(vector<int> &curr, vector<int> &prev){
    if (prev[0] <= curr[0] && prev[1] <= curr[1] && prev[2] <= curr[2])
    {
        return true;
    }
    else{
        return false;
    }
    
}

int solveUsingTabulationSO(vector<vector<int>> &cuboid){
    int n = cuboid.size();

    vector<int> currRow(n+1, 0); 
    vector<int> nextRow(n+1, 0); 

    for (int curr_index = n-1; curr_index >= 0; curr_index--){
        for (int prev_index = curr_index-1 ; prev_index >= -1; prev_index--)
        {
            int include = 0;
            if (prev_index == -1 || checkCriteria(cuboid[curr_index], cuboid[prev_index])){
                int heightToAdd = cuboid[curr_index][2];
                include = heightToAdd + nextRow[curr_index+1];   
            } 
            int exclude = 0 + nextRow[prev_index+1];   
            currRow[prev_index+1] = max(include, exclude);   
        }   
        nextRow = currRow;
    }
return nextRow[0];
}

int maxHeight(vector<vector<int>> &cuboid){
    for(auto &it : cuboid){
        sort(it.begin(), it.end());
    }
    sort(cuboid.begin(), cuboid.end());

    int ans = solveUsingTabulationSO(cuboid);
    cout<<"The total height is : "<<ans<<endl;
}

int main(){
    vector<vector<int>> cuboid = {{50,45,20},{95,37,53},{45,23,12}};
    maxHeight(cuboid);

return 0;
}


