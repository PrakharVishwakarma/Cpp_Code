// Implement k-queues in an array with space efficiency

#include <iostream>
using namespace std;

class KQ
{
public:
    int n, k, freeSpot;
    // n is the size of the array, k is the number of queues to be implemented in the array, and freeSpot is the index of the available free spot in the array.
    int *arr, *next, *front, *rear;
    // arr is the array that stores the elements of the queues, next is the array that stores the next index of next item for all item in the array(arr), front is the array that stores the front index of each queue, rear is the array that stores the rear index of each queue.

    KQ(int _n, int _k) : n(_n), k(_k), freeSpot(0)
    {
        arr = new int[n];
        next = new int[n];
        front = new int[k];
        rear = new int[k];

        // Array initialization:
        for (int i = 0; i < k; i++)
            front[i] = rear[i] = -1;

        for (int i = 0; i < n; i++)
            next[i] = i + 1;

        next[n - 1] = -1;
    }

    bool push(int x, int qi)
    {
        // Check Overflow:
        if (freeSpot == -1)
            return false;

        // Find first free index:
        int index = freeSpot;

        // Update the free spot:
        freeSpot = next[index];

        // Update front:
        if (front[qi] == -1)
            front[qi] = index;
        else
        {
            next[rear[qi]] = index;
        }

        next[index] = -1;

        rear[qi] = index;
        arr[index] = x;
        return true;
    }

    int pop(int qi)
    {
        // Check the underflow condition:
        if (front[qi] == -1)
            return -1;

        int index = front[qi];

        front[qi] = next[index];

        next[index] = freeSpot;

        freeSpot = index;
        return arr[index];
    }
    ~KQ()
    {
        delete[] arr;
        delete[] next;
        delete[] front;
        delete[] rear;
    }
};

int main()
{

    return 0;
}