#include<iostream>
using namespace std;

int main() {
int a = 4; 
int b = 6;

cout<<"a and b is " << (a&b) << endl;
cout<<"a or b is " << (a|b) << endl;
cout<<"Not of a is " << ~(a) << endl;
cout<<"a xor b is " << (a^b) << endl;

// Left and Right shift :

cout<<"17 ka ek baar leff shift "<< (17>>1) << endl; // 17 / 2 = 8 is the output.
cout<<"17 ka do baar leff shift "<< (17>>2) << endl; // 17 /(2*2) = 17/4 = 4 is the output.
cout<<"21 ka ek vari left shift "<< (21<<1) << endl; // 21 * 2 = 42 is the output.  
cout<<"21 ka do vari left shift "<< (21<<2) << endl; // 21 * (2*2) = 84 is the output.
}