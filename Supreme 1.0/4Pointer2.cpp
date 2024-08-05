#include<iostream>
using namespace std;

// int* solve(){
//     int a = 5;
//     int *ans = &a;
//     cout<<&a<<endl;
//     cout<<ans<<endl;
// }
int main(){

    // solve();

    // int arr[10];
    // int *ptr = arr;
    // int **ptrr = &ptr;
    
    // cout<<&arr<<endl;
    // cout<<&arr[0]<<endl;
    /* arr[i] = i[arr] = *(arr+i) */
    

    double a = 45.45;
    double *ptr = &a;
    cout<<sizeof(a)<<endl;
    cout<<sizeof(ptr)<<endl;
    cout<<sizeof(&a)<<endl;
    cout<<sizeof(&ptr)<<endl;
    cout<<ptr<<" "<<++ptr<<endl;
    return 0;
}