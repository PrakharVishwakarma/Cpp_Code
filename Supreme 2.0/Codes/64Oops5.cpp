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

    return 0;
}


// Static polymorphism has 2 types : 
// Function Overloading , Operator overloading.