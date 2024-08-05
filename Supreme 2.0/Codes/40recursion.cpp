// Array is sorted or not using recursion.

#include <iostream>
using namespace std;

bool isSorted(int arr[], int size, int index)
{
    if (index >= size)
        return true;
    if (arr[index] > arr[index - 1]) 
        return isSorted(arr, size, index + 1);
    else
        return false;
}

int main()
{
    int arr[] = {10, 20, 50, 60, 780, 10};
    int size = sizeof(arr) / sizeof(int);
    if(isSorted(arr, size, 1))
        cout << "Array is sorted.";
    else
        cout << "Array is not sorted.";

    return 0;
}



