#include<iostream>
using namespace std;

void func(int arr[], int size){
    // for (int i = 0; i < size; i++)
    // {
    //     cout<<" "<<arr[i];
    // }cout<<endl;

    int res = arr[0];
    for (int i = 1; i < size; i++)
    {
        res = res ^ arr[i];
        cout<<res<<" ";
    }cout<<endl<<res<<endl;
    
}

int main(){
    int x = 5 , y = 6, z = 7;
    z = y++ && ++x || ++z;
    // cout<<"x : "<<x<<". y : "<<y<<". z : "<<z<<endl;

    int arr[4] = {1, 2, 3, 4};
    // for (int i = 0; i < 4; i++)
    // {
    //     cout<<" "<<arr[i];
    // }cout<<endl;

    // func(arr, 4);
    
    // for (int i = 0; i < 4; i++)
    // {
    //     cout<<" "<<arr[i];
    // }cout<<endl;

    int A[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int ans = 0;
    for(int i=0; i<10;i++)
    {
        if((A[i] & (A[i]-1))==0){
            cout<<"if met "<<ans<<" ";
            ans += 1;
            cout<<ans;
        }
        else if((A[i] & (A[i]+1))==0){
            cout<<"if else met "<<ans<<" ";
            ans = 1;
            cout<<ans;
        }
        else{
            cout<<"else met "<<ans<<" ";
            ans <<= 1;
            cout<<ans;
        }cout<<endl; 
    }



return 0;
}