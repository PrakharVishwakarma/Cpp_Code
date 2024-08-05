#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

/* Merge Sort : */
/*
void merge(vector<int> &v, vector<int> &temp, int s, int mid, int e)
{
    int i = s;
    int j = mid + 1;
    int k = s;

    while (i <= mid && j <= e)
    {
        if (v[i] <= v[j])
            temp[k++] = v[i++];
        else
            temp[k++] = v[j++];
    }

    while(i <= mid){
        temp[k++] = v[i++];
    }


    while (j <= e){
        temp[k++] = v[j++];
    }

    while (s <= e){
        v[s] = temp[s];
        s++;
    }
}

void mergeSort(vector<int> &v, vector<int> &temp, int s, int e)
{
    if (s >= e)
        return ;

    int mid = s + (e - s) / 2;
    mergeSort(v, temp, s, mid);
    mergeSort(v, temp, mid + 1, e);
    merge(v, temp, s, mid, e);
}

int main()
{
    vector<int> v = {4, 1, 2, 3};
    vector<int> temp(v.size() , 0);
    mergeSort(v , temp , 0 ,v.size()-1 );
    for (int i = 0; i < v.size(); i++)
    {
       cout<<v[i]<<" ";
    }

    return 0;
}
*/

/* IN place merge sort . */ /*Best way to sort the array.*/
void mergeTwoArrInplace(vector<int> &v1, vector<int> &v2, int s, int e)
{

    int n = v1.size();
    int m = v2.size();

    int totalLength = n + m;
    int gap = (totalLength / 2) + (totalLength % 2);
    while (gap > 0)
    {
        int i = s;
        int j = s + gap;
        while (j <= totalLength)
        {
            if (j < n && v1[i] > v1[j])
            {
                swap(v1[i], v1[j]);
            }
            else if (j >= n && i < n && v1[i] > v2[j - n])
            {
                swap(v1[i], v2[j - n]);
            }
            else if (j >= n && i >= n && v2[i - n] > v2[j - n])
            {
                swap(v1[i - n], v2[j - n]);
            }

            ++i;
            ++j;
        }
        gap = gap <= 1 ? 0 : (gap / 2) + (gap % 2);
    }
}
void mergeSortTwoArr(vector<int> &v1, vector<int> &v2, int s, int e)
{
    if (s >= e)
        return;

    int mid = s + (e - s) / 2;
    mergeSortTwoArr(v1, v2, s, mid);
    mergeSortTwoArr(v1, v2, mid + 1, e);
    mergeTwoArrInplace(v1, v2, s, e);
}


void mergeInplace(vector<int> &v, int s, int e)
{
    int totalLength = e - s + 1;
    int gap = (totalLength / 2) + (totalLength % 2);
    while (gap > 0)
    {
        int i = s;
        int j = s + gap;
        while (j <= e)
        {
            if (v[i] > v[j])
            {
                swap(v[i], v[j]);
            }
            ++i;
            ++j;
        }
        gap = gap <= 1 ? 0 : (gap / 2) + (gap % 2);
    }
}

void mergeSort(vector<int> &v, int s, int e)
{
    if (s >= e)
        return;

    int mid = s + (e - s) / 2;
    mergeSort(v, s, mid);
    mergeSort(v, mid + 1, e);
    mergeInplace(v, s, e);
}

int main()
{
    vector<int> v1 = {4, 1, 2, 3};
    vector<int> v2 = {5, 10, 20, 23 , 30};

    mergeSort(v1, 0, v1.size() - 1);
    for (int i = 0; i < v1.size(); i++)
    {
        cout << v1[i] << " ";
    }

    return 0;
}
