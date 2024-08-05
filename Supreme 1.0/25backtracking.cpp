/* 
Inversion count : In an array, , the elements at indices i and j where i<j form an inversion if arr[i]>arr[j].
In other words, inverted elements arr[i] and arr[j] are considered to be "out of order". 
To correct an inversion, we can swap adjacent elements.
Returns int: the number of inversions
*/

#include <iostream>
#include <vector>

using namespace std;

long merge(vector<int> &v, vector<int> &temp, int s, int mid, int e)
{
    int i = s;
    int j = mid+1;
    int k = s;

    long c = 0;
    while (i <= mid && j <= e)
    {
        if (v[i] <= v[j])
        {
            temp[k++] = v[i++];
        }
        else
        {
            temp[k++] = v[j++];
            c += mid - i + 1; // Calculating Inversion Count.
        }
    }

    while (i <= mid)
    {
        temp[k++] = v[i++];
    }

    while (j <= e)
    {
        temp[k++] = v[j++];
    }

    while (s <= e)
    {
        v[s] = temp[s];
        s++;
    }

    return c;
}

long mergeSort(vector<int> &v, vector<int> &temp, int s, int e)
{
    if (s >= e)
        return 0;

    int mid = s + (e - s) / 2;
    long c = 0;
    c += mergeSort(v, temp, s, mid);
    c += mergeSort(v, temp, mid + 1, e);
    c += merge(v, temp, s, mid, e);
}

long inversionCount(vector<int> v)
{
    long c = 0;
    vector<int> temp(v.size() , 0);
    c = mergeSort(v, temp, 0, v.size() - 1);
    return c;
}

int main()
{
    vector<int> v = {4, 1 , 2, 3};

    cout<<"The value of inversion count is : " << inversionCount(v);
    return 0;
}