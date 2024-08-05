#include<iostream>
#include<limits.h>
using namespace std;

bool isSorted(int *array , int &size , int &iterator , int &mini){

    if(iterator == size) return true;
    if(array[iterator+1] < array[iterator])return false;
    


    return isSorted(array , size , ++iterator , mini );
}

int main()
{
    
    int n;
    cout<<"Enter the size of an array : ";
    cin>>n;
    int *arr = new int[n];
    int iterator = 0;
    for (int i = 0; i < n; i++)
    {
        cout<<"Enter the size "<<i<<"th element of an array : ";
        cin>>arr[i];
    }
    cout<<endl;
    for (int i = 0; i < n; i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;

    int mini = INT_MIN;
    if(isSorted(arr , n , iterator, mini)) cout<<"Array is sorted";
    else cout<<"Array is not sorted";
 
}