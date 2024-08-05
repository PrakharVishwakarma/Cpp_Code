

#include<iostream>
#include<vector>
#include<unordered_map>
#include<list>
#include<set>
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

    void dijkstraShortestDistance(int n, int src, int dest) {
		vector<int> dist(n+1, INT_MAX);
		set<pair<int,int> > st;

		//INTIAL STATE -> (0,src)
		st.insert({0,src});
		dist[src] = 0;

		//distance updation logic 
		while(!st.empty()) {
			auto topElement = st.begin();
			pair<int, int> topPair = *topElement;
			int topDist = topPair.first;
			int topNode = topPair.second;
			//remove the topNode
			st.erase(st.begin());

			//update distance of nbr
			for(pair<int,int> nbrPair: adjList[topNode]) {
				int nbrNode = nbrPair.first;
				int nbrDist = nbrPair.second;
				if(topDist + nbrDist < dist[nbrNode]) {
					//found a new shorter distnace
					//now update: 
					
					// -> set ki entry
					//find previousEntry and delete it
					auto previousEntry = st.find({dist[nbrNode], nbrNode});
					if(previousEntry != st.end()) {
						// entry present in set
						st.erase(previousEntry);
					}
					// -> dist ka array
					dist[nbrNode] = topDist + nbrDist;
					//create a new entry in the set for new distance
					st.insert({dist[nbrNode], nbrNode});
				}
			}
		}
		cout << "Shortest Distance from " << src << " Node to " << dest << " Node: " << dist[dest] << endl;
    }
};

int main()
{
    Graph g;
    g.addEdge(1, 2, 7, 0);
    g.addEdge(1, 3, 9, 0);
    g.addEdge(1, 6, 14, 0);
    g.addEdge(2, 3, 10, 0);
    g.addEdge(2, 4, 15, 0);
    g.addEdge(3, 4, 11, 0);
    g.addEdge(6, 3, 2, 0);
    g.addEdge(6, 5, 9, 0);
    g.addEdge(5, 4, 6, 0);

    g.dijkstraShortestDistance(6, 6, 4);

return 0;
}