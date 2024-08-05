// Leetcode 207 : Course Schedule
#include<iostream>
#include<vector>
#include<unordered_map>
#include<queue>
#include<list>

using namespace std;

bool topoSortBfs(int n, unordered_map<int, list<int> > &adjList) {
        vector<int> ans;
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
        if(ans.size() == n){
            cout<<"the ordering of courses ";
            for (int i = 0; i < ans.size(); i++)
            {
                cout<<ans[i]<<" ";
            }
        return true;
        } 
        else {
            return false;
        }
	}

bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
    unordered_map<int, list<int> > adjList;
    for(auto task: prerequisites){
        int u = task[0];
        int v = task[1];
        adjList[v].push_back(u);
    }

    return topoSortBfs(numCourses, adjList);
}

int main(){

    // vector<vector<int>> prerequisites = {{1,0}, {0, 1}};
    vector<vector<int>> prerequisites = {{1,0},{2,0},{3,1},{3,2}};
    int numCourses = 4;
    if(canFinish(numCourses, prerequisites)) cout<<endl<<"You can finish all the courses."<<endl;
    else cout<< "You can not finish all the courses."<<endl;

return 0;
}