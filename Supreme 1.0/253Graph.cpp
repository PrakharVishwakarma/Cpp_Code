#include <iostream>
#include <vector>
#include <unordered_map>
#include <list>
#include <stack>
#include <queue>
using namespace std;

template <typename T>
class Graph

{
public:
    unordered_map<int, list<int>> adjList;

    void addEdge(int u, int v, bool direction)
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

    void topologicalSortUsingDfs(int src, unordered_map<int, bool> &visited, stack<int> &s){
        visited[src] = true;

        for(auto nbr: adjList[src]){
            if(!visited[nbr]) topologicalSortUsingDfs(nbr, visited, s);
        }

        s.push(src);
    }
    // Topological Sorting for a graph is not possible if the graph is not a DAG.

    void topoSortBfs(int n, vector<int>& ans) {
		queue<int> q;
		unordered_map<int, int> indegree;

		//indegree calculate
		for(auto i: adjList ) {
			int src = i.first;
			for(auto nbr:i.second) {
				indegree[nbr]++;
			}
		}

		//put all nodes inside queue, which has indegree=0
		for(int i=0; i<n; i++) {
			if(indegree[i] == 0) {
				q.push(i);
			}
		}

		//bfs logic
		while(!q.empty()) {
			int fNode = q.front();
			q.pop();

			ans.push_back(fNode);
			//or we can do count++

			for(auto nbr: adjList[fNode]) {
				indegree[nbr]--;
				//check for zero again
				if(indegree[nbr] == 0) {
					q.push(nbr);
				}	
			}
			
		}
		
	}

};

int main()
{
    Graph<int> g;
    int n = 8;
    g.addEdge(0,1,1);
    g.addEdge(1,2,1);
    g.addEdge(2,3,1);
    g.addEdge(3,4,1);
    g.addEdge(3,5,1);
    g.addEdge(5,6,1);
    g.addEdge(4,6,1);
    g.addEdge(6,7,1);
    int numberOfNodes = 8;
    cout << endl;

    g.printAdjacencyList();
    cout<<endl;

    unordered_map<int, bool> visited;
    stack<int> ans;
    for (int i = 0; i < numberOfNodes; i++)
    {
        if(!visited[i]) 
            g.topologicalSortUsingDfs(i, visited, ans);    
    }
    cout<<"Printing Topological Sort : ";
    while (!ans.empty())
    {
        cout<<ans.top()<<" ";
        ans.pop();
    }
    
    vector<int> ans2;
	g.topoSortBfs(numberOfNodes, ans2);
    cout <<endl<<"Printing Topological Sort using BFS : ";
    for (int i = 0; i < ans2.size(); i++)
    {
        cout<<ans2[i]<<" ";
    }
    if (ans2.size() == numberOfNodes)
    {
        cout<<endl<<"Valid topological sort."<<endl;
    }
    else{
        cout<<endl<<"InValid topological sort that's why Cycle is present in the Graph."<<endl;
    }
    


return 0;
}