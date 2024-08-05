#include<iostream>
#include<vector>
#include<unordered_map>
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
};

int main()
{
    Graph g;
    g.addEdge(0, 1, 1);
    g.addEdge(1, 2, 1);
    g.addEdge(1, 3, 1);
    g.addEdge(2, 3, 1);

    // Graph g;
    // g.addEdge(0, 1, 0);
    // g.addEdge(1, 2, 0);
    // g.addEdge(1, 3, 0);
    // g.addEdge(2, 3, 0);

return 0;
}