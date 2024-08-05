
// First find pivot element and then Find input element in rotated and sorted array

#include <iostream>
#include <vector>

using namespace std;

int findPivotIndex(vector<int> arr, int n)
{

    int s = 0;
    int e = n - 1;
    int mid = s + (e - s) / 2;
  

    while (s <= e)
    {
        if (s == e)
            return s;

        if (arr[mid] > arr[mid + 1] && mid + 1 < n)     // Make sure mid+1 range me hai.
            return mid;
        else if (arr[mid] < arr[mid - 1] && mid - 1 > 0)
            return mid - 1;
        else if (arr[s] > arr[mid])
            e = mid - 1;
        else
            s = mid + 1;

        mid = s + (e - s) / 2;
    }
    return -1;
}

int binarySearch(vector<int> arr, int target, int s, int e)     // Make sure mid-1 range me hai.
{

    int mid = s + (e - s) / 2;

    while (s <= e)
    {
        if (arr[mid] == target)
        {
            return mid;
        }
        else if (target > arr[mid])
        {
            s = mid + 1;
        }
        else
        {
            e = mid - 1;
        }
        mid = s + (e - s) / 2;
    }
    return -1;
}

int main()
{

    vector<int> v;

    v.push_back(8);
    v.push_back(10);
    v.push_back(15);
    v.push_back(2);
    v.push_back(4);
    v.push_back(5);
    v.push_back(6);

    int n = v.size();

    int pivotIndex = findPivotIndex(v, n);

    cout << "Pivot element in rotated and sorted array is : " << pivotIndex << " and pivot element is " << v[pivotIndex] << endl;

    int inputElement;
    cout << "Enter the element you want to search in rotated and sorted array : ";
    cin >> inputElement;

    int elementIndex;

    if (inputElement >= v[0] && inputElement <= v[pivotIndex])
    {
        elementIndex = binarySearch(v, inputElement, 0, pivotIndex);
    }
    else
    {
        elementIndex = binarySearch(v, inputElement, pivotIndex + 1, n - 1);
    }
    cout << elementIndex << endl;

    if (elementIndex == -1)
    {
        cout << "Element not found.";
    }
    else
    {
        cout << "Element found at index " << elementIndex;
    }

    return 0;
}
