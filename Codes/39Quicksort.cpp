#include<iostream>
using namespace std;


int partition( int arr[], int start, int end) {

    int pivot = arr[start];

    int cnt = 0;
    for(int i = start+1; i<=end; i++) {
        if(arr[i] <=pivot) {
            cnt++;
        }
    }
 
    //place pivot at right position
    int pivotIndex = start + cnt;
    swap(arr[pivotIndex], arr[start]);

    //left and right wala part smbhal lete h 
    int i = start, j = end;

    while(i < pivotIndex && j > pivotIndex) {

        while(arr[i] <= pivot) 
        {
            i++;
        }

        while(arr[j] > pivot) {
            j--;
        }

        if(i < pivotIndex && j > pivotIndex) {
            swap(arr[i++], arr[j--]);
        }

    }

    return pivotIndex;

}

void quickSort(int arr[], int start , int end) {

    //base case
    if(start >= end) 
        return ;

    //partitioon 
    int p = partition(arr, start, end);

    //sorting left part of pivotindex.
    quickSort(arr, start, p-1);

    //sorting right part of pivotindex.
    quickSort(arr, p+1, end);

}

int main() {

    int arr[10] = {2,4,1,6,9,9,9,9,9,9};
    int n = 10;

    quickSort(arr, 0, n-1);

    for(int i=0; i<n; i++) 
    {
        cout << arr[i] << " ";
    } cout << endl;


    return 0;
}