// Interleave Queue.

#include<iostream>
#include<queue>
using namespace std;

void Interleave(queue<int> &q1){
    queue<int>q2;
    int size = q1.size();
    for (int i = 0; i < size/2; i++)
    {
        int temp = q1.front();
        q1.pop();
        q2.push(temp);
    }
    for (int i = 0; i < size/2; i++)
    {
        int temp = q2.front();
        q2.pop();
        q1.push(temp);
        temp = q1.front();
        q1.pop();
        q1.push(temp);
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

    Interleave(q);

    while (!q.empty())
    {
        int element = q.front();
        q.pop();
        cout<<element<<" ";
    }cout<<endl;

return 0;
}