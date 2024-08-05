#include <iostream>
#include <vector>
#include <unordered_map>
#include <list>
#include <queue>
#include <algorithm>
#include <stack>
#include <set>
#include <limits.h>

using namespace std;

class WeightedGraph
{
public:
    unordered_map<int, list<pair<int, int>>> adjList;

    void addEdge(int u, int v, int weight, bool isdirected)
    {
        // direction = 0 -> undirected graph
        // direction = 1 -> directed graph
        // create an edge from u to v
        if(isdirected){
            adjList[u].push_back(make_pair(v, weight));
        }
        else{
            adjList[u].push_back({v, weight});
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
    shortestPathBfs(int src, int dest){
        queue<int> q;
        unordered_map<int, int> parent;
        unordered_map<int, bool> visited;

        q.push(src);
        parent[src] = -1;
        visited[src] = true;
        while (!q.empty())
        {
            int frontNode = q.front();
            q.pop();
            for(auto nbr : adjList[frontNode]){
                if(!visited[nbr.first]){
                    q.push(nbr.first);
                    visited[nbr.first] = true;
                    parent[nbr.first] = frontNode;
                 }
            }
        }

        cout<<"Printing the shortest path : ";
        vector<int>ans;
        while (dest != -1)
        {
            ans.push_back(dest);
            dest = parent[dest];
        }
        reverse(ans.begin(), ans.end());
        for(auto i: ans)cout<<i<<" ";
        cout<<endl;
    }

    void topologicalSortUsingDfs(int src, unordered_map<int, bool> &visited, stack<int> &s){
        visited[src] = true;

        for(auto nbr: adjList[src]){
            if(!visited[nbr.first]) topologicalSortUsingDfs(nbr.first, visited, s);
        }

        s.push(src);

    }

    void shortestPathDfs(int n, stack<int> topoOrder, int dest){
        vector<int> dist(n, INT_MAX);

        int src = topoOrder.top();
        topoOrder.pop();
        dist[src] = 0;

        for(auto nbr: adjList[0]){
            if(dist[0] + nbr.second < dist[nbr.first]) dist[nbr.first] = dist[0] + nbr.second;
        }

        while (!topoOrder.empty())
        {
            int node = topoOrder.top();
            topoOrder.pop();

            if(dist[node] != INT_MAX){
                for(auto nbr: adjList[node]){
                    if(dist[node] + nbr.second < dist[nbr.first]) dist[nbr.first] = dist[node] + nbr.second;
                }
            }
        }

        cout<<endl<<"Printtng the distance array : ";
        for (int i = 0; i < n; i++)
        {
            cout<<dist[i]<<" ";
        }cout<<endl;
        
    }

void shortestDistDijkstra(int src, int n) {
		vector<int> dist(n,INT_MAX);
		set<pair<int,int> > st;
		//intiial steps
		dist[src] = 0;
		st.insert(make_pair(0,src));

		while(!st.empty() ) {
			//fetch the smallest or first eklement from set
			auto topElement = *(st.begin());
			int nodeDistance = topElement.first;
			int node = topElement.second;

			//pop from set
			st.erase(st.begin());

				//neighbour traverse
			for(auto nbr: adjList[node]) {
				if(nodeDistance + nbr.second < dist[nbr.first]) {
					//mujhe distance update krna h 
					//finding entry in set
					auto result = st.find(make_pair(dist[nbr.first], nbr.first));
					//if found, then remove
					if(result != st.end()) {
						st.erase(result);
					}
					//updation in dist array and set
					dist[nbr.first] = nodeDistance + nbr.second;
					st.insert(make_pair(dist[nbr.first], nbr.first));
				}
			}
			
		}

		cout << "printing ans:" << endl;
		for(int i=0; i<n; i++) {
			cout << dist[i] <<", ";
		}cout << endl;
		
	}

};

int main(){
    WeightedGraph g;
    g.addEdge(0, 1, 5, 0);
    g.addEdge(0, 2, 3, 0);
    g.addEdge(2, 1, 2, 2);
    g.addEdge(2, 3, 5, 0);
    g.addEdge(2, 4, 6, 0);
    g.addEdge(3, 1, 3, 0);
    g.addEdge(4, 3, 1, 0);
    int n = 5;

    g.printAdjacencyList();

    int src = 0;
    int dest = 4;

    g.shortestPathBfs(src, dest);

    stack<int> topoOrder;
    unordered_map<int, bool> visited;
    g.topologicalSortUsingDfs(0, visited, topoOrder); 
    // cout<<endl<<"Printing the topological sort order :" ;
    // while (!topoOrder.empty())
    // {
    //     cout<<topoOrder.top()<<" ";
    //     topoOrder.pop();
    // }

    g.shortestPathDfs(n, topoOrder, 5);

    WeightedGraph g2;
    g2.addEdge(6, 3, 2, 0);
    g2.addEdge(6, 1, 14, 0);
    g2.addEdge(3, 1, 9, 0);
    g2.addEdge(3, 2, 10, 0);
    g2.addEdge(1, 2, 7, 0);
    g2.addEdge(2, 4, 15, 0);
    g2.addEdge(4, 3, 11, 0);
    g2.addEdge(6, 5, 9, 0);
    g2.addEdge(4, 5, 6, 0);

    g2.printAdjacencyList();

    g2.shortestDistDijkstra(6, 7);
return 0;
}