#include<iostream>
using namespace std;

void ptrByValue(int* b){
    *b = 10;
}

void ptrByRef(int* &a){
    *a = 10;
}

int main(){
    int val = 5;
    int *a = &val;
    cout<<val<<endl;
    ptrByValue(val);
    // ptrByValue(&val);
    cout<<val<<endl;
    ptrByRef(a);
    cout<<val<<endl;
return 0;
}