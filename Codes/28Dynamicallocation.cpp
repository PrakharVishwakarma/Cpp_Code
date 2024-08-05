
#include<iostream>
using namespace std;

int getSum(int* arr , int n)
{
    int sum = 0;
    for(int i=0 ; i<n ; i++){
        sum += arr[i];
    }
    return sum;
}
int main(){
 
    int n;
    cout<<"Enter the size you want ";
    cin>>n;
    // variable size array : 

    int* arr = new int[n];
    //Static   Dynamic array of n size

    //taking input in array :
    for(int i = 0 ; i < n ; i++)
    {
        cout<<"Enter the " <<i<<"th element "<<endl;
        cin>>arr[i];   // arr[i]= *(arr + i)
    }

    int ans = getSum(arr , n);
    cout<<"Sum of array "<<ans;
}