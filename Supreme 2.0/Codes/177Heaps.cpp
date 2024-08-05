// Leetcode 973 : K closest point to origin.

#include<iostream>
#include<queue>
#include<vector>
#include <utility>

using namespace std;

class mycomp{
public:
    bool operator()(pair<int, int>&a, pair<int, int>&b){
        int distA = a.first*a.first + a.second*a.second;
        int distB = b.first*b.first + b.second*b.second;
        return distA > distB;
    }
};

vector<vector<int>> kClosestPointToOrigin(vector<vector<int>> &points, int k){
    vector<vector<int>> ans;
    priority_queue<pair<int, int>, vector<pair<int, int>> , mycomp> pq;
    for(auto p:points){
        pq.push({p[0], p[1]});
    }
    while (!pq.empty() && k--)
    {
        auto topOfPq = pq.top();
        ans.push_back({topOfPq.first, topOfPq.second});
        pq.pop();
    }
    return ans;
}

int main(){
    vector<vector<int>> v{{3,3}, {5,-1}, {-2,4}};
    int k = 2;
    vector<vector<int>> ans = kClosestPointToOrigin(v, k);
    for(auto p:ans){
        cout<<p[0]<<","<<p[1]<<endl;
    }    

return 0;
}