// Operator Overloading.

#include<iostream>
using namespace std;

class Vector {
    int x; 
    int y;
public:
    Vector(int x , int y) : x(x) , y(y) {};

    void operator+(const Vector &src){
        this->x += src.x;
        this->y += src.y;
    }
    void operator++(){
        this->x ++;
        this->y ++;
    }

    void display(){
        cout<<"x : "<<x<<" and "<<"y : "<<y;
    }

};


int main(){

    Vector v1(1,2); 
    Vector v2(4,5); 
    v1.display();
    cout<<endl;
    
    v1+v2;
    v1.display();
    cout<<endl;

    ++v2;
    v2.display();

    // Feels like v1 is destination and v2 is source v1 = v1 + v2 /Or/ v1.add(v2)

    return 0;
}

// Polymorphism has two types : Compile time(static) and run time(dynamic)
// Static polymorphism has 2 types : 
// Function Overloading , Operator overloading.