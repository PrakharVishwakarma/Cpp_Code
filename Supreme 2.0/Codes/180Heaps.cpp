// Leetcode 871 : Minimum number of trefuling points.

#include<iostream>
#include<queue>
#include<vector>
using namespace std;
    
int minRefuelStops(int target, int startFuel, vector<vector<int>> &stations){
    int stops = 0;
    int dist = 0; 
    int i = 0;
    int fuel = startFuel;
    priority_queue<pair<int,int>>pq;
    while(true){
        while (i<stations.size())
        {
            if (stations[i][0] <= dist + fuel)pq.push({stations[i][1], stations[i][0]});
            else break;
            ++i;
        }
        dist += fuel;
        fuel = 0;

        if(dist >= target) break;

        if(pq.empty()){
            stops = -1;
            break;
        }

        auto &top = pq.top();
        fuel = (dist-top.second) + top.first;
        dist = top.second;
        pq.pop();
        ++stops;
    }
    return stops;
}

int main(){
    int target = 100;
    int startFuel = 10;
    vector<vector<int>> stations = {{10,60},{20,30},{30,30},{60,40}};
    cout<<"Minimum Number of Refueling Stops are : "<<minRefuelStops(target, startFuel, stations);
return 0;
}