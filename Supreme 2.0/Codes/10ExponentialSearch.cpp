// Used in large size of an array. and better than binary search when the target is near beginning.

#include <iostream>
using namespace std;

int biSearch(int *arr, int s, int e, int x)
{
    while (s <= e)
    {
        int mid = s + (e - s) / 2;
        if (arr[mid] == x)
        {
            return mid;
        }
        else if (x > arr[mid])
        {
            s = mid + 1;
        }
        else
        {
            e = mid - 1;
        }
    }
    return -1;
}

int ExpSearch(int *arr, int x, int n)
{

    if (arr[0] == x)
    {
        return 0;
    }
    int i = 1;
    while (i < n &&arr[i] <= x )    // In the infinite array there is no need to pass the end.
    {        
            i = i*2;

    }
    return biSearch(arr, i / 2, min(i, n - 1), x);
}

int main()
{
    int arr[] = {10, 15, 20, 45, 55, 67, 72, 89, 119, 152, 215, 321, 426, 500, 566, 1000};
    int x = 321;
    int size = sizeof(arr) / sizeof(int);
    int foundEleIndex = ExpSearch(arr, x, size);
    cout << foundEleIndex;
    return 0;
}