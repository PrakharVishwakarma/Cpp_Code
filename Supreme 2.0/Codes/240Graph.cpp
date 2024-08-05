#include<iostream>
#include<vector>
#include<unordered_map>
#include<queue>
#include<list>

using namespace std;

class Graph{
public:
    unordered_map<int, list<int> > adjList;

    void addEdge(int u, int v, bool isdirected){
        if(isdirected){
            adjList[u].push_back(v);
        }
        else{
            adjList[u].push_back(v);
            adjList[v].push_back(u);
        }

    cout<<"Printing the edgeList : "<<endl;
    printList();
    }

    void printList(){
        for (auto i : adjList)
        {
            cout<<i.first<<": {";
            for(auto neighbour : i.second){
                cout<<neighbour<<" ";
            }
            cout<<"}"<<endl;
        }
    }

    bool checkCyclic(int src, unordered_map<int,bool>& vis,
        unordered_map<int,bool> &dfsTrack ) {
            
        vis[src] = true;
        dfsTrack[src] = true;
        
        for(auto nbr: adjList[src]) {
            if(!vis[nbr]) {
                bool ans = checkCyclic(nbr, vis, dfsTrack);
                if(ans == true) {
                    return true;
                }
            }
            if(vis[nbr]==1 && dfsTrack[nbr]==1) {
                //cycle present
                return true;
            }
        }
        
        //backtrack - [yahi galti karta hu]
        dfsTrack[src] = false;
        return false;
    }
    // Function to detect cycle in a directed graph.
    bool isCyclic(int V) {
       unordered_map<int,bool> vis;
       unordered_map<int,bool> dfsTrack;
       
       for(int node=0; node<V; node++) {
           if(!vis[node]) {
               bool isCyclic = checkCyclic(node, vis, dfsTrack);
               if(isCyclic) {
                   return true;
               }
           }
       }
       return false;
    }
};

int main()
{
    // Graph g;
    // g.addEdge(0, 1, 1);
    // g.addEdge(1, 2, 1);
    // g.addEdge(1, 3, 1);
    // g.addEdge(2, 3, 1);

    Graph g;
    g.addEdge(0, 1, 1);
    g.addEdge(1, 3, 1);
    g.addEdge(3, 2, 1);
    g.addEdge(2, 1, 1);
    g.addEdge(1, 4, 1);
    g.addEdge(4, 5, 1);
    g.addEdge(5, 1, 1);

    int noOfNodes = 6;
    bool isSrc = g.isCyclic(noOfNodes);
    if(isSrc) cout<<"Cycle is present in the Graph."<<endl;
    else cout<<"Cycle is not present in the Graph."<<endl;


return 0;
}