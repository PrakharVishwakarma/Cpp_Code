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
    else cout<<"Queue is not empty."<<endl;


    queue<int> q2;
    q2.push(1);
    q2.push(22);
    q2.push(35);
    q2.push(64);
    
    cout<<"Size of the Queue is : "<<q2.size()<<endl;
    cout<<"Front element of queue is : "<<q2.front()<<endl;
    cout<<"Last/Rear element of queue is : "<<q2.back()<<endl;

    // Swapping two queues
    queue<int> q3;
    q3.push(100);
    q3.push(200);

    cout << "\nBefore swap, q3 front: " << q3.front() << endl;
    q2.swap(q3);
    cout << "After swap, q3 front: " << q3.front() << endl;


    // Understanding the emplace operation in queue : constructs an element in place, directly within the container, avoiding unnecessary copies or moves. 
    q3.emplace(40);
    cout << "\nAfter emplace(40):" << endl;
    cout << "Front element: " << q3.front() << endl;
    cout << "Back element: " << q3.back() << endl;

return 0;
}