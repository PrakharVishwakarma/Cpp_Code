// Singel Source Shortest Path: 

#include<iostream>
#include<vector>
#include<unordered_map>
#include<list>
#include<stack>
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

    void topoOrderDfs(int src, stack<int> &topoOrder, unordered_map<int, bool> &isVisited){
        isVisited[src] = true;

        for(auto nbrPair: adjList[src]){
            int nbrNode = nbrPair.first;
            
            if(!isVisited[nbrNode]) topoOrderDfs(nbrNode, topoOrder, isVisited);
        }

    topoOrder.push(src);
    }

    void shortestPathUsingDfs(stack<int> &topoOrder, vector<int> &dist){

        int srcNode = topoOrder.top();
        topoOrder.pop();
        dist[srcNode] = 0;
        for(auto nbrPair: adjList[srcNode]){
            int nbrNode = nbrPair.first;
            int nbrDist = nbrPair.second;

            if(dist[srcNode] + nbrDist < dist[nbrNode]) dist[nbrNode] = dist[srcNode] + nbrDist;
        }

        while (!topoOrder.empty())
        {
            int srcNode = topoOrder.top();
            topoOrder.pop();
            
            for(auto nbrPair: adjList[srcNode]){
                int nbrNode = nbrPair.first;
                int nbrDist = nbrPair.second;

                if(dist[srcNode] + nbrDist < dist[nbrNode]) dist[nbrNode] = dist[srcNode] + nbrDist;
            }
        }
    }

};

int main()
{
    Graph g;
    g.addEdge(0, 1, 5, 1);
    g.addEdge(0, 2, 3, 1);
    g.addEdge(1, 3, 3, 1);
    g.addEdge(2, 1, 2, 1);
    g.addEdge(2, 4, 6, 1);
    g.addEdge(2, 3, 5, 1);
    g.addEdge(4, 3, 4, 1); 

    // Graph g;
    // g.addEdge(0, 1, 5, 0);
    // g.addEdge(1, 2, 10, 0);
    // g.addEdge(1, 3, 20, 0);
    // g.addEdge(2, 3, 50, 0);

    int src = 0;
    stack<int> topoOrder;
    unordered_map<int, bool> isVisited;
    g.topoOrderDfs(src, topoOrder, isVisited);

    // cout<<endl<<"Printing the stack : "<<endl;
    // while (!topoOrder.empty())
    // {
    //     cout<<topoOrder.top()<<" ";
    //     topoOrder.pop();
    // }

    int n = 5;
    vector<int> dist(n, INT_MAX);
    g.shortestPathUsingDfs(topoOrder, dist);
    cout<<endl<<"Printing the array contains shortest path : "<< endl;
    for(auto i: dist){
        cout<<i<<" ";
    }

return 0;
}