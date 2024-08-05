// Left Shift the elements of an array : 

#include<iostream>
using namespace std;


int main()
{

    int n;
    cout<<"Enter the size of an array : ";
    cin>>n;
    cout<<"Enter array ";
    int *arr = new int[n];
    for (int i = 0; i < n; i++)
    {
        cin>>arr[i];
    }

    cout<<"Array is : ";
       for (int i = 0; i < n; i++)
    {
        cout<<arr[i]<<" ";
    }

    int d;
    cout<<endl<<"give the value for array left shift iteration : ";
    cin>>d;

    for (int i = 0; i < d; i++)
    {
        if(i<d){
            arr[n-d+i]=arr[i];
            }
        
    }
    
    for (int i = 0; i < n-d; i++)
    {
        int index = (i+d)%n;
        swap(arr[i],arr[index]);
    }
      for (int i = 0; i < n; i++)
    {
        cout<<arr[i]<<" ";
    }  

}