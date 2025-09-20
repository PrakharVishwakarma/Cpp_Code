// 225. Implement Stack using Queues
#include<iostream>
#include<queue>
using namespace std;

/*
Method 1: Using two queues. Complexty of push O(n), pop O(1), peek O(1), space O(n)
 Idea: keep the newest element at the front of q1 (so pop/top simply access q1.front()).
*/
class MyStackMeth1st {
public:
    queue<int>q1, q2;
    MyStackMeth1st() = default;
    
    void push(int x) {
        q2.push(x);
        while (!q1.empty()){
            q2.push(q1.front());
            q1.pop();
        }
        
        while (!q2.empty()){
            q1.push(q2.front());
            q2.pop();
        }
    }
    
    int pop() {
        int popElement = q1.front();
        q1.pop();
        return popElement;    
    }
    
    int top() {
        return q1.front();
    }
    
    bool empty() {
        return q1.empty();
    }
};

// Method 2: Using only single queue. Complexty of push O(n), pop O(1), peek O(1), space O(n)
class MyStackMeth2nd {
public:
    queue<int>q;
    MyStackMeth2nd() {
        
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
    MyStackMeth1st s1;
    s1.push(2);
    s1.push(6);
    s1.push(5);
    cout<<" Top element is "<<s1.top()<<endl;
    cout<<" Popped element is "<<s1.pop()<<endl;
    cout<<" Popped element is "<<s1.pop()<<endl<<endl;

    MyStackMeth2nd s2;
    s2.push(2);
    s2.push(6);
    s2.push(5);
    cout<<" Top element is "<<s2.top()<<endl;
    cout<<" Popped element is "<<s2.pop()<<endl;
    cout<<" Popped element is "<<s2.pop()<<endl<<endl;

return 0;
}