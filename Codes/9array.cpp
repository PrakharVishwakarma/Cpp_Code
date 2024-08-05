//Finding the maximum and minimum value of an array.
#include<iostream>
#include <limits.h>
using namespace std;

int getMax(int arr[] , int size){
    int maxi = INT_MIN;
    for(int i=0; i<size; i++){
        if(arr[i] > maxi){
            maxi=arr[i];
        }
       //  maxi = max(max,arr[i]);  : also useful . 
    }
    return maxi;
} 
int getMin(int arr[] , int size){
    int mini = INT_MAX;
    for(int i=0; i<size; i++){
        if(arr[i] < mini){
            mini=arr[i];
        }
        // mini = min(mini , arr[i]);
    }
    return min;
} 

int main() {
cout << "Minimum value of int: " << INT_MIN << std::endl;
int size;
cin>>size;

int arr[size];
for (int i = 0; i < size; i++)
{
    cin>>arr[i];
}

cout<<"maximum value of an array is "<< getMax(arr , size) <<endl;
cout<<"Minimum value of an array is "<<getMin(arr , size) <<endl;

cout << "Minimum value of int: " << unsigned INT_MIN <<endl;
    return 0;
}