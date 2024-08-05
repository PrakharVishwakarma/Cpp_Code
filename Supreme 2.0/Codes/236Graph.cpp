#include<iostream>
#include<vector>
#include<unordered_map>
#include<list>

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
};

int main()
{
    Graph g;
    g.addEdge(0, 1, 5, 1);
    g.addEdge(1, 2, 10, 1);
    g.addEdge(1, 3, 20, 1);
    g.addEdge(2, 3, 50, 1); 

    // Graph g;
    // g.addEdge(0, 1, 5, 0);
    // g.addEdge(1, 2, 10, 0);
    // g.addEdge(1, 3, 20, 0);
    // g.addEdge(2, 3, 50, 0);
return 0;
}