// Leetcode 641 : Implement Doubly Ended Queue[Circular].

#include <iostream>
using namespace std;

class Queue
{

private:
    int *arr;
    int size;
    int front;
    int rear;

public:
    Queue(int size)
    {
        this->size = size;
        arr = new int[size];
        fill(arr, arr + size, 0);
        // memset(arr, 0, size*sizeof(*arr));   <-- To set all the element of an array with zero we can also use
        front = -1;
        rear = -1;
    }

    ~Queue()
    {
        delete[] arr;
    }

    void pushBack(int value)
    {
        if ((rear == size - 1 && front == 0) || (rear == front - 1))
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

    void pushFront(int value)
    {
        if ((front == 0 && rear == size - 1) || front == rear + 1)
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
        else if (front == 0 && rear != size - 1)
        {
            front = size - 1;
            arr[front] = value;
        }
        else
        {
            front--;
            arr[front] = value;
        }
    }

    void popFront()
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

    void popBack()
    {
        if (front == -1 && rear == -1)
        {
            cout << "Can't be popped, Stack Underflow." << endl;
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
        else
        {
            arr[rear] = -1;
            rear--;
        }
    }

    bool isFull()
    {
        return (rear == size - 1 && front == 0) || (rear + 1 == front);
    }

    // Check if deque is empty
    bool isEmpty()
    {
        return front == -1;
    }

    // Get the front element
    int getFront()
    {
        if (isEmpty())
        {
            cout << "Queue is empty." << endl;
            return -1;
        }
        return arr[front];
    }

    // Get the rear element
    int getRear()
    {
        if (isEmpty())
        {
            cout << "Queue is empty." << endl;
            return -1;
        }
        return arr[rear];
    }

    void printDeque()
    {
        if (isEmpty())
        {
            cout << "Queue is empty." << endl;
            return;
        }
        cout << "Deque elements: ";
        int i = front;
        while (true)
        {
            cout << arr[i] << " ";
            if (i == rear)
                break;
            i = (i + 1 == size) ? 0 : i + 1; // Move to next element without using modulo
        }
        cout << "\nFront: " << front << ", Rear: " << rear << endl;
    }
};

int main()
{

    Queue dq(5);

    dq.pushBack(10);
    dq.pushBack(20);
    dq.pushFront(5);
    dq.pushFront(1);
    dq.printDeque();

    dq.popFront();
    dq.printDeque();

    dq.pushBack(30);
    dq.pushBack(40);
    dq.printDeque();

    dq.popBack();
    dq.printDeque();

    return 0;
    return 0;
}