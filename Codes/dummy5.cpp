// Bit stuffing : 

#include<iostream>
using namespace std;


int main(){

    int lenth;
    cout<<"Enter the lenth of message send by sender : ";
    cin>>lenth;
    int resize = lenth + (lenth/5);

    int *arr  = new int[resize];    //Initializing the array of size bigger than lenth so that the message message can be derefrence.

    cout<<"Enter the 0/1 message send by sender : "<<endl; 
    for (int i = 0; i < lenth; i++)
    {
        cin>>arr[i];
    }

    cout<<endl<<"message send by sender in the form of 0/1 : ";
    for (int i = 0; i < lenth; i++)
    {
        cout<<arr[i]<<" ";
    }

    int count = 0;
    int pairCount = (lenth/5);

    for (int j = resize-1; j>=0 ; j--)
    {
        if(arr[j]==1){
            count++;

            if(count=5){
                count = 0;
                pairCount++;
                
                arr[j+6] = arr[j+5];
            }
            arr[j+5]=0;
        }
    }
    cout<<endl<<"According to bit stuffing the message should be : ";
    for (int i = 0; i < resize-pairCount; i++)
    {
        cout<<arr[i]<<" ";
    }
    
}