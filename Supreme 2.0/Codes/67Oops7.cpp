#include<iostream>
using namespace std;


class Box{
    int width;    
    Box(int _width) : width(_width) {}      // Here the constructor is private but still when we call it from main, It will not generate any error.

public: 
    
    int getWidth() const{
        return width;
    }
    void setWidth(int val){
        width = val;
    }
    friend class Boxfrnd;
    //The friend keyword in C++ allows a function or another class to access the private and protected members of the class where it is declared. 
};

class Boxfrnd{
    public:
    Box getBoxWidth(int _w){
        return Box(_w);
    }
};

int main(){

    Boxfrnd bfr;
    Box b = bfr.getBoxWidth(5);
    cout<<b.getWidth();

return 0;
}

/*
Advance topic : Singleton class.

*/





