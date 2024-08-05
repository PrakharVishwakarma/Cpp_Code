// 225. Implement Stack using Queues
#include<iostream>
#include<queue>
using namespace std;

class MyStack {
public:
    queue<int>q;
    MyStack() {
        
    }
    
    void push(int x) {
        q.push(x);
        for (int i = 0; i < q.size()-1; i++)
        {
            int frontElement = q.front();
            q.pop();
            q.push(frontElement);
        }
        
    }
    
    int pop() {
        int popElement = q.front();
        q.pop();
        return popElement;
    }
    
    int top() {
        return q.front();
    }
    
    bool empty() {
        return q.empty();
    }
};

int main()
{
    MyStack s1;
    s1.push(2);
    s1.push(6);
    s1.push(5);
    cout<<s1.pop();
return 0;
}