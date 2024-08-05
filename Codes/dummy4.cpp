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

    cout<<endl<<"message send by sender in the form of 0/1 :       ";
    for (int i = 0; i < lenth; i++)
    {
        cout<<arr[i]<<" ";
    }


    int count = 0;
    int pairCount = (lenth/5);

    for (int i = 0; i < resize; i++)
    {
        if(arr[i]==1){
            count++;
            if(count==5){
                count = 0;
                pairCount--;

                    for (int j = resize-pairCount; j > i-2; j--)
                    {
                        arr[j] = arr[j-1];   
                    }
                arr[i+1]=0;
            }
        }
    }
    
    
    cout<<endl<<"According to bit stuffing the message should be : ";
    for (int i = 0; i < resize-pairCount; i++)
    {
        cout<<arr[i]<<" ";
    }
}