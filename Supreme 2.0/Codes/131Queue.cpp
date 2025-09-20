// Leetcode 933. Number of Recent Calls

#include<iostream>
#include<queue>

using namespace std;

class RecentCounter {
public:
    queue<int> q;
    RecentCounter() {
        
    }
    
    int ping(int t) {
        q.push(t);
        while(!q.empty() && q.front() < t -3000)
            q.pop();
        
        return q.size();
    }
};

int main(){

    return 0;
}