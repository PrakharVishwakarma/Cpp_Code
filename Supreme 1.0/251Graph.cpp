#include <iostream>
#include <vector>
#include <unordered_map>
#include <list>
#include <queue>
using namespace std;

class WeightedGraph
{
public:
    unordered_map<int, list<pair<int, int>>> adjList;

    void addEdge(int u, int v, int weight, bool direction)
    {
        // direction = 0 -> undirected graph
        // direction = 1 -> directed graph
        // create an edge from u to v
        adjList[u].push_back({v, weight});
        if (direction == 0)
        {
            // undirected edge
            // create an edge from v to u
            adjList[v].push_back({u, weight});
        }
    }

    void printAdjacencyList()
    {
        for (auto node : adjList)
        {
            cout << node.first << "-> ";
            for (auto neighbour : node.second)
            {
                cout << "(" << neighbour.first << "," << neighbour.second << "), ";
            }
            cout << endl;
        }
    }
};

template <typename T>
class Graph
{
public:
    unordered_map<T, list<T>> adjList;

    void addEdge(T u, T v, bool direction)
    {
        // direction = 0 -> undirected graph
        // direction = 1 -> directed graph
        // create an edge from u to v
        adjList[u].push_back(v);
        if (direction == 0)
        {
            // undirected edge
            // create an edge from v to u
            adjList[v].push_back(u);
        }
    }

    void printAdjacencyList()
    {
        for (auto node : adjList)
        {
            cout << node.first << "-> ";
            for (auto neighbour : node.second)
            {
                cout << neighbour << ", ";
            }
            cout << endl;
        }
    }

    void bfs(T src, unordered_map<T, bool> &visited){
        queue<T> q;
        
        q.push(src);
        visited[src] = true;

        while (!q.empty())
        {
            T frontNode = q.front();
            q.pop();
            cout<<frontNode<<" ";
            for (auto neighbour: adjList[frontNode]){
                if(!visited[neighbour]){
                    q.push(neighbour);
                    visited[neighbour] = true;
                }
            }   
        } 
    }

    void dfs(T src, unordered_map<T, bool> &visited){
        cout<<src<<" ";
        visited[src] = true;

        for(auto neighbour: adjList[src]){
            if(!visited[neighbour]) dfs(neighbour, visited);
        }
    }

};

int main()
{
    Graph<int> g;
    int n = 5;
    g.addEdge(0,1,0);
    g.addEdge(1,3,0);
    g.addEdge(0,2,0);
    g.addEdge(2,4,0);
    cout << endl;

    g.printAdjacencyList();

    unordered_map<int, bool> visited;
    // run a loop to find dfs corresponding to all nodes, In case of disconnected graph 
    cout << "Printing BFS Traversal: ";
    for (int i = 0; i < n; i++)
    {
        if (!visited[i])g.bfs(i, visited);
    }cout<<endl;


    cout << "Printing DFS Traversal: ";
    unordered_map<int, bool> visited2;
    for (int i = 0; i < n; i++)
    {
        if (!visited2[i]) g.dfs(i, visited2);
    }cout<<endl;

    WeightedGraph g2;
    g2.addEdge(0, 1, 5, 1);
    g2.addEdge(1, 2, 8, 1);
    g2.addEdge(0, 2, 6, 1);
    cout << endl;
    g2.printAdjacencyList();

    return 0;
}