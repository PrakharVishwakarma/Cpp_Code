#include<iostream>
using namespace std;

class ABC{
public:
    static int x;       // Static means that var is going to share the memory with all of the class instance(object).
    static int y;

    /* static */ void print() const{     // If this function is being static then x and y must be static. *A static member function shall not be declared const, volatile, or const volatile(so we have to comment const). There is no instance of class being passed into this method/function.
        cout<<x<<" "<<y<<endl;
    }

};

int ABC::x; // x and y class ke kisi instance ka nahi hai, balki khud hi class ka hai.  
int ABC::y;

int main(){
    ABC a;
    a.x = 1;
    a.y = 2;
    a.print();

    ABC b ;
    b.x = 10;
    b.y = 20;
    a.print();
    b.print();

    // ABC::print();    //if the function is static

return 0;
}


// Static member function : There is no instance of that class being passed into that method.  