// Leetcode 232: Implement Queue using Stacks

#include<iostream>
#include<stack>
using namespace std;

class MyQueueMeth1st {
public:
    stack<int>s1,s2;
    MyQueue() {
        
    }
    
    void push(int x) {
        s1.push(x);
    }
    
    int pop() {
        int popElement = -1;
        if (s2.empty())
        {
            while (!s1.empty())
            {
                s2.push(s1.top());
                s1.pop();
            }
            popElement = s2.top();          
        }
        else {
            popElement = s2.top();
        }
        s2.pop();
        return popElement;
    }
    
    int peek() {
        int peekElement = -1;
        if (s2.empty())
        {
            while (!s1.empty())
            {
                s2.push(s1.top());
                s1.pop();
            }
            peekElement = s2.top();          
        }
        else {
            peekElement = s2.top();
        }
        return peekElement;
        
    }
    
    bool empty() {
        return s1.empty() && s2.empty(); 
    }
};

class MyQueueMeth2nd {
public:
    stack<int>s1,s2;
    MyQueue() {
        
    }
    
    void push(int x) {
        if (s1.empty()) {
            s1.push(x);
        }

        else{
            while (!s1.empty())
            {
                s2.push(s1.top());
                s1.pop();
            }
            s1.push(x);
            while (!s2.empty())
            {
                s1.push(s2.top());
                s2.pop();
            }
            
        }
    }

    int pop() {
        int popElement = s1.top();
        s1.pop();
    }
    
    int peek() {
        return s1.top();
    }
    
    bool empty() {
        return s1.empty();
    }
};

int main()
{
/*
    MyQueueMeth1st q1;
    q1.push(20);
    q1.push(21);
    q1.push(22);
    cout<<q1.pop()<<endl;
    cout<<q1.peek()<<endl;
    cout<<q1.pop()<<endl;
    cout<<q1.peek()<<endl;
*/
    MyQueueMeth2nd q2;
    q2.push(20);
    cout<<q2.peek()<<endl;
    q2.push(21);
    cout<<q2.pop();


return 0;
}