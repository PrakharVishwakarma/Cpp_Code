// Leetcode 1878 : Get Biggest Three Rhombus Sums in a Grid

#include<iostream>
#include<queue>
#include<vector>

using namespace std;

bool checkBound(vector<vector<int>> &grid, vector<pair<int, int> > &v){
    for(auto pt: v){
        if (pt.first< 0 || pt.first >= grid.size() || pt.second< 0 || pt.second >= grid[0].size() )
            return false;  

    }
return true;
}
bool getallVertices(vector<vector<int>> &grid, vector<pair<int, int> > &v, pair<int, int>c, int &delta){
    pair<int, int> pointA(c.first-delta, c.second);
    pair<int, int> pointB(c.first, c.second+delta);
    pair<int, int> pointC(c.first+delta, c.second);
    pair<int, int> pointD(c.first, c.second-delta);
    
    v[0] = pointA;
    v[1] = pointB;
    v[2] = pointC;
    v[3] = pointD;
    if (checkBound(grid, v))
        return true;
    else return false;
    
}
void getAllSum(vector<vector<int>> &grid, int &cX, int &cY, priority_queue<int> &pq){
    pq.push(grid[cX][cY]);
    int delta = 1;
    vector<pair<int, int> >v(4);
    while (getallVertices(grid, v, {cX, cY}, delta))
    {
        pair<int, int> &A = v[0];   
        pair<int, int> &B = v[1];   
        pair<int, int> &C = v[2];   
        pair<int, int> &D = v[3];

        int csum = grid[A.first][A.second] + grid[B.first][B.second] + grid[C.first][C.second] + grid[D.first][D.second];

        for (int i = 1; i < B.first- A.first; i++)
        {
            csum += grid[A.first+i][A.second+i];
        }
        for (int i = 1; i < C.first- B.first; i++)
        {
            csum += grid[B.first+i][A.second+i];
        }
        for (int i = 1; i < C.first- D.first; i++)
        {
            csum += grid[C.first-i][C.second-i];
        }
        for (int i = 1; i < D.first- A.first; i++)
        {
            csum += grid[D.first-i][D.second+i];
        }
        pq.push(csum);
        ++delta;
    }
    
}
bool canPush(vector<int>&ans, int &top){
    for(auto val:ans){
        if (val == top)return false;
    }
    return true;
}
vector<int> getBiggestRhombus(vector<vector<int>> grid){
    vector<int>ans;
    priority_queue<int> pq;
    
    for (int i = 0; i < grid.size(); i++)
    {
        for (int j = 0; j < grid[0].size(); j++)
        {
            getAllSum(grid, i, j, pq);
        } 
    }
    while (!pq.empty() && ans.size() < 3)
    {
        int top = pq.top();
        pq.pop();
        if(canPush(ans, top)){
            ans.push_back(top);
        }
    }
    return ans;
}

int main(){
    vector<vector<int>> grid = {
        {3,4,5,1,3},
        {3,3,4,2,3},
        {20,30,200,40,10},
        {1,5,5,4,1},
        {4,3,2,2,5}
    } ;
    vector<int>ans = getBiggestRhombus(grid);
    for (int i = 0; i < ans.size(); i++)
    {
        cout<<ans[i]<<" ";
    }
    
return 0;
}