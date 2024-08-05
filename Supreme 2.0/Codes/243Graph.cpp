// Prims Algorithms : 

#include<iostream>
#include<vector>
#include<unordered_map>
#include<list>
#include<set>
#include<limits.h>

using namespace std;

class Graph{
public:
    unordered_map<int, list<pair<int, int>> > adjList;

    void addEdge(int u, int v, int wt, bool isdirected){
        if(isdirected){
            adjList[u].push_back(make_pair(v, wt));
        }
        else{
            adjList[u].push_back({v, wt});
            adjList[v].push_back({u, wt});
        }

    cout<<"Printing the edgeList : "<<endl;
    printList();
    }

    void printList(){
        for (auto i : adjList)
        {
            cout<<i.first<<": { ";
            for(auto neighbour : i.second){
                cout<<"{"<<neighbour.first<<", "<<neighbour.second<<"} ";
            }
            cout<<"}"<<endl;
        }
    }

    int getMinNodeIndex(vector<int> &mst, vector<int> &key){
        int temp = INT_MAX;
        int index = -1;

        for (int i = 0; i < key.size(); i++){
            if(key[i] < temp && mst[i] == false){
                temp = key[i];
                index = i;
            }
        }
    return index;
    }

    void minimalSpanningTree(vector<pair<pair<int, int>, int>> adjList, int v){
        unordered_map<int, list<pair<int, int>> > adj;
        for (int i = 0; i < adjList.size(); i++)
        {
            int u = adjList[i].first.first;
            int v = adjList[i].first.second;
            int w = adjList[i].second;

            adj[u].push_back(make_pair(v,w));
            adj[v].push_back(make_pair(u,w));
        }
        
        
        vector<int>key(v, INT_MAX);
        vector<int>mst(v, false);
        vector<int>parent(v, -1);

        key[0] = 0;
        while (true)
        {
            int u = getMinNodeIndex(mst, key);
            if(u == -1) break;

            mst[u] = true;

            for(auto nbrPair: adj[u]) {
                int v = nbrPair.first;
                int w = nbrPair.second;
                if(mst[v] == false && w < key[v]){
                    key[v] = w;
                    parent[v] = u;
                }
            }
        }
        
        vector<pair<pair<int, int>, int>> result;
        for (int i = 1; i < v; i++)
        {
            result.push_back({{parent[i], i}, key[i]});
        }

        cout<<"Printing the minimal spanning tree : "<<endl;
        for (auto i: result)
        {
            cout<<i.first.first<<" "<<i.first.second<<" "<<i.second<<endl;;
        }
            
    }
};

int main(){
    Graph g;
    g.addEdge(1, 0, 2, 0);
    g.addEdge(1, 3, 8, 0);
    g.addEdge(1, 2, 3, 0);
    g.addEdge(1, 4, 5, 0);
    g.addEdge(0, 3, 6, 0);
    g.addEdge(4, 2, 7, 0);

    vector<pair<pair<int, int>, int>> adjList = {
        {{1, 0}, 2},
        {{1, 3}, 8},
        {{1, 2}, 3},
        {{1, 4}, 5},
        {{0, 3}, 6},
        {{4, 2}, 7}
    };
    g.minimalSpanningTree(adjList, 5);
    
    
return 0;
}