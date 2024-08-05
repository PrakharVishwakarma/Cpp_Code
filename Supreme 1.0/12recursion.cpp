// Buy and sell stock :

#include<iostream>
#include<limits.h>

using namespace std;

void maxProfitRe(int arr[] , int &size, int iterator , int maxiProfit , int minPrice ){

    //Base case :
    if (iterator >= size){
        cout<<maxiProfit; 
        return ;
    }

    //Ek case :
    if(arr[iterator] < minPrice) minPrice = arr[iterator];
    int todayProfit = arr[iterator] - minPrice;
    if(todayProfit > maxiProfit) maxiProfit = todayProfit;

    //Rec.:
    maxProfit(arr , size , ++iterator , maxiProfit , minPrice);

    
}
int main(){

    int n;
    cout<<"Enter the size of an array : ";
    cin>>n;
    int *arr = new int[n];
    cout<<"Enter the element of the array : ";
    for (int i = 0; i < n; i++)
    {
        cin>>arr[i];
    }
    cout<<"Array showing the current price of stock in ith day : ";
    for (int i = 0; i < n; i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;

    maxProfitRe(arr , n , 0 , INT_MIN , INT_MAX);

    return 0;
}