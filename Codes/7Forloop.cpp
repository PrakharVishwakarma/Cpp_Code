#include<iostream>
using namespace std;

int main() {

    int n ;
    cout<<"Enter n" << endl;
    cin>> n;

    int a = 0;
    int b = 1;
    cout<<a <<" " <<b<<" ";
    for(int i = 1; i<=n; i++ ) {
        
        int nextNumber = a+b;
        cout<<nextNumber<<" ";

        a = b;  //Order Mattters , matlab a me b aa jaaye
        b = nextNumber;  // aur b me nextNumber aa jaaye.

        /* 
        for(int a = 0 , b =1, c = 2; a>=0 && b>=1 && c>=2; a--,b--, c-- ){
       cout<<a <<" "<< b << " "<<c << endl;
       */
    }
    return 0;
}