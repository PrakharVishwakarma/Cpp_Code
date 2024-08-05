#include<iostream>
#include<vector>
#include<unordered_map>
#include<list>
#include<queue>

using namespace std;

template <typename T>
class Graph{
public:
    unordered_map<T, list<pair<T, int>> > adjList;

    void addEdge(T u, T v, int wt, bool isdirected){
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

    void dfsTraversal(T src, unordered_map<char, bool> &isVis){
        isVis[src] = true;
        cout<<src<<" ";

        for(auto nbr : adjList[src]){
            T nbrData = nbr.first;
            if(!isVis[nbrData]){
                dfsTraversal(nbrData, isVis);
            }
        }
    }

};

int main()
{
    Graph<char> g;
    g.addEdge('a', 'b', 5, 0);
    g.addEdge('a', 'c', 10, 0);
    g.addEdge('b', 'c', 20, 0);
    g.addEdge('b', 'd', 50, 0); 
    g.addEdge('c', 'e', 25, 0); 
    g.addEdge('c', 'f', 30, 0); 
    g.addEdge('e', 'f', 35, 0); 

    unordered_map<char, bool> isVis;
    cout<<"Traversal Depth first search : ";
    for (char node = 'a'; node <= 'f'; node++)
    {
        if(!isVis[node]){
            g.dfsTraversal(node, isVis);
        }
    }

return 0;
}