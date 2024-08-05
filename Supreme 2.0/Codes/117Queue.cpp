// Implementation of queue using array: 

#include<iostream>
#include <bits/stdc++.h>
using namespace std;

class Queue{

public: int *arr;
    int size;
    int front;
    int rear;

    Queue(int size){
        this->size = size;
        arr = new int[size];
        fill(arr, arr+size, 0);         
        // memset(arr, 0, size*sizeof(*arr));   <-- To set all the element of an array with zero we can also use 
        front = -1;
        rear = -1;
    }

    void push(int value){
        if(rear == size - 1){
            cout<<"Can't push, Queue is overflowed."<<endl;
        return; 
        }
        else if (front == -1 && rear == -1)
        {
            front++;
            rear++;
            arr[rear] = value;
        }
        else{
            rear++;
            arr[rear] = value;
        }  
    }


    void pop(){
        if(front == -1 && rear == -1)
        {
            cout<<"Can't be popped, Stack Underflow."<<endl;
            return;
        }
        else if (front == rear)
        {
            arr[front] = -1;
            front = -1;
            rear = -1;
        }
        else{
            arr[front] = -1;
            front++;
        }

    }

    bool empty(){
        if (front == -1 && rear == -1) return true;
        else return false;
    }

    int getQSize(){
        return rear - front + 1;
    }

    int getFront(){
        if (front != -1)return arr[front];
        else {
            cout<<"No element is found in a queue."<<endl;
        return -1;
        }
    }

    int getRear(){
        if (rear != -1) return arr[rear];
        else {
            cout<<"No element is found in a queue."<<endl;
        return -1;
        }
    }

    void printQ(){
        for (int i = 0; i < size; i++)
        {
            cout<<arr[i]<<" ";
        }cout<<endl; 
    }

};

int main(){
    Queue q(5);
    cout<<q.getFront()<<endl;
    cout<<q.getRear()<<endl;
    cout<<q.getQSize()<<endl;
    q.printQ();

    cout<<"Pushing first element : ";
    q.push(5);
    cout<<q.getFront()<<endl;
    cout<<q.getRear()<<endl;
    cout<<q.getQSize()<<endl;
    q.printQ();

    cout<<"Pushing second element : ";
    q.push(15);
    cout<<q.getFront()<<endl;
    cout<<q.getRear()<<endl;
    cout<<q.getQSize()<<endl;
    q.printQ();

return 0;
}