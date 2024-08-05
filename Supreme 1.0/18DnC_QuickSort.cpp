#include <iostream>
#include <algorithm>

using namespace std;

void easyQuickSort(int *arr, int s, int e)
{
    if (s >= e)
        return;

    int i = s - 1;
    int j = i + 1;
    int pivot = e;
    while (j < e)
    {
        if (arr[j] < arr[pivot])
        {
            ++i;
            swap(arr[i], arr[j]);
        }
        ++j;
    }
    ++i;
    swap(arr[i], arr[pivot]);

    easyQuickSort(arr, s, i - 1);
    easyQuickSort(arr, i + 1, e);
}

int partition(int arr[], int s, int e){
    int pivotInd = s;
    int pivotEle = arr[s];
    int count = 0;

    for (int i = s + 1; i < e; i++)
    {
        if (arr[i] <= pivotEle)
        {
            count++;
        }
    }

    int rightPivot = s + count;
    swap(arr[pivotInd], arr[rightPivot]);
    pivotInd = rightPivot;

    int i = s;
    int j = e;
    while (i < pivotInd && j > pivotInd)
    {
        while (arr[i] < arr[pivotInd])
        {
            i++;
        }
        while (arr[j] > arr[pivotInd])
        {
            j--;
        }
        while (i < pivotInd && j > pivotInd)
        {
            swap(arr[i], arr[j]);
        }
    }

    return pivotInd;
}

void quickSort(int arr[], int s, int e)
{
    if (s >= e)
        return;

    int pivotIndex = partition(arr, s, e);

    quickSort(arr, s, pivotIndex - 1);

    quickSort(arr, pivotIndex + 1, e);
}

int main()
{

    int arr[] = {45, 2, 5, 6, 5, 48, 35, 74, 24, 65, 3, 24};
    int sizeOfArr = 12;
    int start = 0;
    int end = sizeOfArr - 1;
    for (int i = 0; i < sizeOfArr; i++)
    {
        cout << arr[i] << " ";
    }

    quickSort(arr, start, end);

    cout << endl
         << "Sorted array is : ";
    for (int i = 0; i < sizeOfArr; i++)
    {
        cout << arr[i] << " ";
    }

    easyQuickSort(arr, start, end);

    cout << endl
         << "Sorted array is : ";
    for (int i = 0; i < sizeOfArr; i++)
    {
        cout << arr[i] << " ";
    }

return 0;
}

// Easy
