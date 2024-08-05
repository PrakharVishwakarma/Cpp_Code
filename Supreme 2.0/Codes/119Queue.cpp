//Leetcode 641 : Implement Doubly Ended Queue[Circular].

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

    void pushBack(int value){
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
        else if (rear == size - 1 && front != 0 )
        {
            rear = 0;
            arr[rear] = value;
        }
        else{
            rear++;
            arr[rear] = value;
        }  
    }

    void pushFront(){
        if (front == 0)
        {
            cout<<"Can't push, Queue is overflowed."<<endl;
        }
        else if (front == -1 && rear == -1)
        {
            front++;
            rear++;
            arr[rear] = value;
        }
        else if(front == 0 && rear != size-1){
            front = size-1;
            arr[front] = value;
        }
        else if (front == size-1)
        {
            arr[front] = -1;
            front = 0;
        }
        else{
            front--;
            arr[front] = val;
        }
        
    }

    void popFront(){
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
        else if (front == size-1)
        {
            arr[front] = -1;
            front = 0;
        }
        else{
            arr[front] = -1;
            front++;
        }
    }

    void popBack(){
        if(front == -1 && rear == -1)
        {
            cout<<"Can't be popped, Stack Underflow."<<endl;
            return;
        }
        else if (front == rear)
        {
            arr[rear] = -1;
            front = -1;
            rear = -1;
        }
        else if (rear == 0)
        {
            arr[rear] = -1;
            rear = size - 1; 
        }
        
        else{
            arr[rear] = -1;
            rear--;
        }
    }

};

int main(){


return 0;
}