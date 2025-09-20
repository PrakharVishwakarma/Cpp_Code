// Leetcode 232: Implement Queue using Stacks

#include <iostream>
#include <stack>
using namespace std;

// Method 1: Complexty of push O(1), pop O(n), peek O(n), space O(n)
class MyQueueMeth1st
{
private:
    stack<int> s1, s2;
public:
    MyQueueMeth1st() {}

    void push(int x)
    {
        s1.push(x);
    }

    int pop()
    {
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
        else
        {
            popElement = s2.top();
        }
        s2.pop();
        return popElement;
    }

    int peek()
    {
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
        else
        {
            peekElement = s2.top();
        }
        return peekElement;
    }

    bool empty()
    {
        return s1.empty() && s2.empty();
    }
};

// Method 2: Complexty of push O(n), pop O(1), peek O(1), space O(n)
class MyQueueMeth2nd
{
private:
    stack<int> s1, s2;

public:
    MyQueueMeth2nd() {}

    // Push element into queue
    void push(int x)
    {
        // Move all elements from s1 -> s2
        while (!s1.empty())
        {
            s2.push(s1.top());
            s1.pop();
        }

        // Push new element into s1
        s1.push(x);

        // Move everything back to s1
        while (!s2.empty())
        {
            s1.push(s2.top());
            s2.pop();
        }
    }

    // Pop element (O(1))
    int pop()
    {
        if (s1.empty())
        {
            cout << "Queue is empty!\n";
            return -1;
        }
        int val = s1.top();
        s1.pop();
        return val;
    }

    // Peek element (O(1))
    int peek()
    {
        if (s1.empty())
        {
            cout << "Queue is empty!\n";
            return -1;
        }
        return s1.top();
    }

    // Check if empty
    bool empty()
    {
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
    cout << q2.peek() << endl;
    q2.push(21);
    cout << q2.pop();

    return 0;
}