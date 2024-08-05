// Reverse a Queue.

#include<iostream>
#include<stack>
#include<queue>

using namespace std;

void reverseQueue(queue<int> &q){
    stack<int>s;

    while (!q.empty())
    {
        int frontElement = q.front();
        q.pop();
        s.push(frontElement);
    }
    while (!s.empty())
    {
        int topElement = s.top();
        s.pop();
        q.push(topElement);
    }

}

void reverseUsingRecc(queue<int> &q){
    if (q.empty())return;
    
    int temp = q.front();
    q.pop();

    reverseUsingRecc(q);

    q.push(temp);

}

void reverseKEle(queue<int> &q, int k, int n){
    if(k==0 || k>n)return;
    
    stack<int>st;
    for (int i = 0; i < k; i++)
    {
        int frontElement = q.front();
        q.pop();
        st.push(frontElement);
    }
    while (!st.empty())
    {
        int topEle = st.top();
        st.pop();
        q.push(topEle);
    }
    for (int i = 0; i < (n - k); i++)
    {
        int temp = q.front();
        q.pop();
        q.push(temp);
    }
    
    
}

int main()
{
    queue<int> q;
    q.push(21);
    q.push(83);
    q.push(46);
    q.push(54);
    q.push(26);
    q.push(20);
/* Using Stack : */
    // reverseQueue(q);
/* Using recursion : */
    // reverseUsingRecc(q);
/* Reverse first K elemen*/
    int k = 3;
    int n = q.size();
    reverseKEle(q , k , n);
    while (!q.empty())
    {
        int element = q.front();
        q.pop();
        cout<<element<<" ";
    }cout<<endl;
    

return 0;
}