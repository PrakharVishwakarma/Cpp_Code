#include<iostream>
using namespace std;


int main(){

    //  wild pointer = Uninitialized pointer : 

    int number = 50 ;
    // int* ptr;
    // cout<<*ptr<<endl;
    // cout<<&ptr<<endl;
    // cout<<ptr<<endl;

    // int *ptr = new int;
    // cout<<*ptr<<endl;
    // delete ptr;
    // cout<<*ptr<<endl;

    // int *ptr = &x;
    // cout<<ptr<<endl;
    // cout<<*ptr<<endl;


    // Void pointer : 

    // void *ptr;
    // int x = 10;
    // cout<<&x;
    // ptr = &x;
    // int *intptr = static_cast<int*>(ptr);    /*Static_cast is a castiing operator that is used to convert a value from one data type to another.*/
    // cout<<*intptr<<endl;
    // cout<<intptr<<endl;

    //Here is an example for dynamic memory allocation.
    // char *ptr = new char;
    // void *voidptr = ptr;
    // char* ptrint = static_cast<char*>(voidptr);
    // *ptrint = 'B';
    // cout<<*ptr<<endl;    
    // cout<<*ptrint<<endl;


    // Dangling pointer : 

    int *ptr = new int;
    *ptr = 42;
    delete ptr;
    cout<<*ptr<<" "<<ptr<<endl;
    
    
return 0;
}