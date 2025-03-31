// Leetcode 622 : Implement circular queue:

#include <iostream>
using namespace std;

class C_Queue
{

private:
int *arr;
int size;
int front;
int rear;

public:
    C_Queue(int size)
    {
        this->size = size;
        arr = new int[size];
        fill(arr, arr + size, 0);
        // memset(arr, 0, size*sizeof(*arr));   <-- To set all the element of an array with zero we can also use
        front = -1;
        rear = -1;
    }

    ~C_Queue()
    {
        delete[] arr;
    }

    void push(int value)
    {
        if ((front == 0 && rear == size - 1) || (rear == front - 1))
        {
            cout << "Can't push, Queue is overflowed." << endl;
            return;
        }
        else if (front == -1 && rear == -1)
        {
            front++;
            rear++;
            arr[rear] = value;
        }
        else if (rear == size - 1 && front != 0)
        {
            rear = 0;
            arr[rear] = value;
        }

        else
        {
            rear++;
            arr[rear] = value;
        }
    }

    void pop()
    {
        if (front == -1 && rear == -1)
        {
            cout << "Can't be popped, Stack Underflow." << endl;
            return;
        }
        else if (front == rear)
        {
            arr[front] = -1;
            front = -1;
            rear = -1;
        }
        else if (front == size - 1)
        {
            arr[front] = -1;
            front = 0;
        }
        else
        {
            arr[front] = -1;
            front++;
        }
    }

    void printQ()
    {
        for (int i = 0; i < size; i++)
        {
            cout << arr[i] << " ";
        }
        cout << endl;
        cout << "Value of front : " << front << " value of rear : " << rear << endl;
    }

    int getFront() {
        if(front == -1){
            cout<<"Queue is empty."<<endl;
            return -1;
        }
        return arr[front];
    }

    int getRear() {
        if(rear == -1){
            cout<<"Queue is empty."<<endl;
            return -1;
        }
        return arr[rear];
    }

    int getC_QSize(){
        if (front == -1) return 0;
        if (rear >= front) return rear - front + 1;
        return (size - front) + (rear + 1);
    }
};

int main()
{
    C_Queue cq(5);
    cq.printQ();
    cq.push(5);
    cq.printQ();
    cq.push(15);
    cq.printQ();
    cq.push(25);
    cq.push(35);
    cq.push(65);
    cq.printQ();
    cq.pop();
    cq.printQ();
    cq.push(45);
    cq.printQ();
    cq.push(42);
    cq.printQ();

    return 0;
}