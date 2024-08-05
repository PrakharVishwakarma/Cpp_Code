#include<iostream>
using namespace std;

void isChanged(int arr[]){
    arr[0]=1;
}

int main(){
    
    int arr[] = {5,456,654,35,3453,345};
    for (int i = 0; i < sizeof(arr)/sizeof(int); i++)
    {
        cout<<arr[i]<<" ";
    }cout<<endl;
    isChanged(arr);
    for (int i = 0; i < sizeof(arr)/sizeof(int); i++)
    {
        cout<<arr[i]<<" ";
    }
    
return 0;
}