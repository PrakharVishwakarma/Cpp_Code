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

    bool checkCycleUsingBfs(int src, unordered_map<int, bool> &isVis){
        queue<int> q;
        unordered_map<int, int> parent;

        q.push(src);
        isVis[src] = true;
        parent[src] = -1;

        while (!q.empty())
        {
            int frontNode = q.front();
            q.pop();
            
            for(auto nbr: adjList[frontNode]){
                if(!isVis[nbr]){
                    q.push(nbr);
                    isVis[nbr] = true;
                    parent[nbr] = frontNode;
                }
                if(isVis[nbr] == true && nbr!= parent[frontNode])return true;   // Cycle Present.
            }
        }
    return false;    
    }

    bool checkCycleUsingdfs(int src, unordered_map<int, bool> &isVis, int parent){
        isVis[src] = true;

        for(auto nbr : adjList[src]){
            if(!isVis[nbr]){
                bool ans = checkCycleUsingdfs(nbr, isVis, src);
                if(ans == true) return true;
            }
            else if(isVis[nbr] == true && nbr != parent){
                return true;
            }
        }
    return false;
    }
    bool isCycle(int V){
        // Using BFS
        // unordered_map<int, bool> isVis;
        // for (int i = 0; i < V; i++)
        // {
        //     if(!isVis[i]){
        //         bool hasCycle = checkCycleUsingBfs(i, isVis);
        //         if(hasCycle == true) return true;
        //     }   
        // }

        // Using DFS
        unordered_map<int, bool> isVis;
        for (int i = 0; i < V; i++)
        {
            if(!isVis[i]){
                int parent = -1;
                bool hasCycle = checkCycleUsingdfs(i, isVis, parent);
                if(hasCycle == true) return true;
            }   
        }

    return false;
    }
};


int main(){
    
    Graph g;
    g.addEdge(0, 1, 0);
    g.addEdge(1, 2, 0);
    g.addEdge(1, 3, 0);
    g.addEdge(2, 4, 0);
    g.addEdge(3, 4, 0);
    g.addEdge(2, 5, 0);

    int noOfNodes = 5;
    bool isSrc = g.isCycle(noOfNodes);
    if(isSrc) cout<<"Cycle is present in the Graph."<<endl;
    else cout<<"Cycle is not present in the Graph."<<endl;


return 0;
}