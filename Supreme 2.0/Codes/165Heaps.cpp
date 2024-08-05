#include <iostream>
#include <algorithm>
using namespace std;

class Heap
{
public:
    int *arr;
    int capacity;
    int size;
    Heap(int capacity)
    {
        this->arr = new int[capacity];
        this->capacity = capacity;
        this->size = 0;
    }

    void insertInHeap(int value)
    {
        if (size == capacity)
        {
            cout << "Size of heap is full, Heap Oveflowed." << endl;
            return;
        }
        size++;
        int index = size;
        arr[index] = value;

        while (index > 1)
        {
            int parentNode = index / 2;
            if (arr[index] > arr[parentNode])
            {
                swap(arr[index], arr[parentNode]);
                index = parentNode;
            }
            else
                break;
        }
    }

    void printHeap()
    {
        for (int i = 1; i <= size; i++)
        {
            cout << arr[i] << " ";
        }
        cout << endl;
    }

    // Delete ki process : root element sabse bada hoga, jisko delete karna hai to
    // root ko replace kar do jo bfs me sabse last me aa raha hai
    // ab us replaced element ko sahi place par pahocha do.
    int deletedNode()
    {
        int answer = arr[1];
        arr[1] = size;
        size--;
        int index = 1;
        while (index < size)
        {
            int leftIndex = 2 * index;
            int rightIndex = 2 * index + 1;

            int largetKaIndex = index;

            if (leftIndex <= size && arr[largetKaIndex] < arr[leftIndex])
            {
                largetKaIndex = leftIndex;
            }
            if (largetKaIndex <= size && arr[largetKaIndex] < arr[rightIndex])
            {
                largetKaIndex = rightIndex;
            }
            if (index == largetKaIndex)
            {
                break;
            }
            else
            {
                swap(arr[index], arr[largetKaIndex]);
            }
        }
        return answer;
    }
};

void heapify(int *arr, int n, int index)
{
    int leftIndex = 2 * index;
    int rightIndex = 2 * index + 1;
    int largestKaIndex = index;

    // teno me se max lao
    if (leftIndex <= n && arr[leftIndex] > arr[largestKaIndex])
    {
        largestKaIndex = leftIndex;
    }
    if (rightIndex <= n && arr[rightIndex] > arr[largestKaIndex])
    {
        largestKaIndex = rightIndex;
    }
    // after these 2 conditions largestKaIndex will be pointing towards largest elemnt among 3
    if (index != largestKaIndex)
    {
        swap(arr[index], arr[largestKaIndex]);
        // ab recursion sambhal lega
        index = largestKaIndex;
        heapify(arr, n, index);
    }
}

void buildHeap(int arr[], int n)
{
    for (int index = n / 2; index > 0; index--)
    {
        heapify(arr, n, index);
    }
}

void heapSort(int arr[], int n)
{
    while (n != 1)
    {
        swap(arr[1], arr[n]);
        n--;
        heapify(arr, n, 1);
    }
}

int main()
{
    Heap h(20);
    h.insertInHeap(10);
    h.insertInHeap(20);
    h.insertInHeap(5);
    h.insertInHeap(11);
    h.insertInHeap(6);
    h.printHeap();

    int ans = h.deletedNode();
    cout << "Deleted node is : " << ans << endl;
    h.printHeap();

    int arr[] = {-1, 5, 10, 15, 20, 25, 12};
    int n = 6;
    buildHeap(arr, 6);

    cout << "After Building printing heap: " << endl;
    for (int i = 1; i <= 6; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    heapSort(arr, n);
    cout << "After Sorting printing heap: " << endl;
    for (int i = 1; i <= 6; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}