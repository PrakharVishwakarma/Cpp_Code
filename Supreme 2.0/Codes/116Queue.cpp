#include<iostream>
#include<queue>
using namespace std;
int main(){
    queue<string>q;
    q.push("String 1");
    q.push("String 2");
    q.push("String 3");

    cout<<"Size of queue "<<q.size()<<endl;
    cout<<"Front element of queue is : "<<q.front()<<endl;
    cout<<"Last element of queue is : "<<q.back()<<endl;

    q.pop();
    cout<<"Size of queue "<<q.size()<<endl;
    cout<<"Front element of queue is : "<<q.front()<<endl;
    cout<<"Last element of queue is : "<<q.back()<<endl;

    q.pop();
    cout<<"Size of queue "<<q.size()<<endl;
    cout<<"Front element of queue is : "<<q.front()<<endl;
    cout<<"Last element of queue is : "<<q.back()<<endl;

    q.pop();
    cout<<"Size of queue is : "<<q.size()<<endl;
    if(q.empty())cout<<"Queue is empty.";
    else cout<<"Queue is not empty.";
    

return 0;
}