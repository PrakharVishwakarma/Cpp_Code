#include<iostream>
using namespace std;

void impMcq(int arr[] , int size){
    cout<<"Function call : "<<arr<<"\t"<<&arr<<endl;    //yaha par arr pointer hai jisme main ke arr ka address pada hai aur &arr cout karne par arr ka address print ho jata hai.
    for (int i = 0; i < size; i++)
    {
        cout<<arr[i]<<" ";
    }
    
}

void solve(int *p){     //  pointer pass by value.
    p++;
    cout<<"Solve function: "<<*p<<endl;
}

int main(){
    int arr[5] = {45 , 50 , 24 , 40 , 65};
    int (*ptr)[5] = &arr; // Puri aaray ka address &arr  // Pointer to an array , ptr is an array of pointers.
    cout<<(*ptr)[0]<<endl;
    cout<<sizeof(ptr)<<endl;

    cout<<"Main Function  : "<<arr<<"\t"<<&arr<<endl;
    impMcq(arr,5);
    
    int a = 50;

    cout<<endl<<"Main function : "<<a<<endl;
    int *p = &a;
    solve(p);
    cout<<"Main function : "<<a<<endl;
    
    return 0; 
}