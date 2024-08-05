#include <iostream>
#include <vector>
#include <unordered_map>
#include <list>
#include <queue>
using namespace std;

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

    bool checkCyclicUsingBfs(int src, unordered_map<int, bool> &visited){
        queue<int> q;
        unordered_map<int, int> parent;

        q.push(src);
        parent[src] = -1;
        visited[src] = true;
        while (!q.empty())
        {
            int frontNode = q.front();
            q.pop();
            for(auto nbr : adjList[frontNode]){
                if(!visited[nbr]){
                    q.push(nbr);
                    parent[nbr] = frontNode;
                    visited[nbr] = true;
                }
                else{
                    if(nbr != parent[frontNode]) return true;
                }
            }
        }
    return false;
    }

	bool checkCyclicUsingDfs(int src, unordered_map<int,bool>& visited, int parent) {
		visited[src] = true;

		for(auto nbr: adjList[src]) {
			if(!visited[nbr]) {
				bool checkAageKaAns = checkCyclicUsingDfs(nbr, visited, src);
				if(checkAageKaAns == true)
					return true;
			}
			if(visited[nbr] && nbr != parent) {
				//cycle present
				return true;
			}
		}
		return false;
	}

    bool checkCyclicDirectedGraphUsingDfs(int src, unordered_map<int,bool>& visited, unordered_map<int,bool> dfsVisited) {
		visited[src] = true;
		dfsVisited[src] = true;

		for(auto nbr: adjList[src]) {
			if(!visited[nbr]) {
				bool aageKaAnswer = checkCyclicDirectedGraphUsingDfs(nbr, visited, dfsVisited);
				if(aageKaAnswer == true)
					return true;
			}
			if(visited[nbr] == true && dfsVisited[nbr] == true) {
				return true;
			}
		}
		//yaha hi galti hoti h 
		dfsVisited[src] = false;
	return false;
	}

};

int main()
{
    Graph<int> g;
    int n = 5;
    g.addEdge(0,1,0);
    g.addEdge(1,2,0);
    g.addEdge(2,3,0);
    g.addEdge(3,4,0);
    g.addEdge(4,0,0);
    cout << endl;

    g.printAdjacencyList();

	bool ans = false;
	unordered_map<int, bool> visited;
    // run a loop to find Cycle Using Bfs corresponding to all nodes, In case of disconnected graph 
	for(int i=0; i<n; i++) {
		if(!visited[i]) {
			 ans = g.checkCyclicUsingBfs(i, visited);
			if(ans == true)
				break;
		}
	}
	if(ans == true) cout << "Cycle is Present" << endl;
	else cout << "Cycle Absent" << endl;


	bool ansDfs = false;
	unordered_map<int, bool> isVisitedDfs;
	for(int i=0; i<n; i++) {
		if(!isVisitedDfs[i]) {
			 ansDfs = g.checkCyclicUsingDfs(i, isVisitedDfs, -1);
			if(ansDfs == true)
				break;
		}
	}

	if(ansDfs == true) cout << "Cycle is Present" << endl;
	else cout << "Cycle Absent" << endl;
	cout << endl;


    Graph<int> g2;
	//n -> number of nodes in graph
	int n2 = 5;
	g2.addEdge(0,1,1);
	g2.addEdge(1,2,1);
	g2.addEdge(2,3,1);
	g2.addEdge(3,4,1);
	g2.addEdge(4,0,1);

	g2.printAdjacencyList();

	bool dfaAnsOfDirectedGraph = false;
	unordered_map<int, bool> vis;
	unordered_map<int, bool> dfsVisited;
	for(int i=0; i<n2; i++) {
		if(!vis[i] ) {
			dfaAnsOfDirectedGraph = g.checkCyclicDirectedGraphUsingDfs(i,vis,dfsVisited);
			if(dfaAnsOfDirectedGraph == true)
				break;
		}
	}

	if(dfaAnsOfDirectedGraph == true) 
		cout << "Cycle is Present" << endl;
	else
		cout << "Cycle Absent" << endl;

return 0;
}