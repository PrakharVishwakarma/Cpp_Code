#include<iostream>
#include<queue>

using namespace std;

int main(){
    // Creating Max Heap:
    priority_queue<int> pq;

    pq.push(13);
    pq.push(10);
    pq.push(30);
    pq.push(23);
    pq.push(15);
    pq.push(20);
    pq.push(5);

    cout<<"Top Element of Max heap : "<<pq.top()<<endl;
    cout<<"Size of the max heap is : "<<pq.size()<<endl;
    pq.pop();
    cout<<"After operation Pop, Top Element of Max heap : "<<pq.top()<<endl;
    cout<<"Size of the max heap is : "<<pq.size()<<endl;
    if (pq.empty())
    {
        cout<<"Max heap is empty."<<endl;
    }
    else{
        cout<<"Max heap is not empty."<<endl;
    }

    // Go through :  https://en.cppreference.com/w/cpp/container/priority_queue

    // Creating Min Heap:
    priority_queue<int, vector<int>, greater<int> >pq2;
    pq2.push(13);
    pq2.push(10);
    pq2.push(30);
    pq2.push(23);
    pq2.push(15);
    pq2.push(20);

    cout<<endl<<"Top Element of Min heap : "<<pq2.top()<<endl;
    cout<<"Size of the Min heap is : "<<pq2.size()<<endl;
    pq2.pop();
    cout<<"After operation Pop, Top Element of Min heap : "<<pq2.top()<<endl;
    cout<<"Size of the Min heap is : "<<pq2.size()<<endl;
    if (pq2.empty())
    {
        cout<<"Min heap is empty."<<endl;
    }
    else{
        cout<<"Min heap is not empty."<<endl;
    }


return 0;
}