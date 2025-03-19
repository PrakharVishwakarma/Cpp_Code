#include <iostream>
using namespace std;

class abc
{

public:
    int x;
    int *y;

    abc(int _x, int _y) : x(_x), y(new int(_y)) {}

    //  By default Shallow copy :
    /*
        abc(const abc &obj){
            x = obj.x;
            y = obj.y;
        }
    */

    // Deep copy (khud se karna padegi)
    abc(const abc &obj)
    {
        x = obj.x;
        y = new int(*obj.y); // Jis se ki a instance ka y and b instance ka y same address par point na kare, bas value same hona chiye;
    }

    void print()
    { 
        cout << "X ki value : " << x << endl
             << "y ki value : " << *y << endl
             << "y ka address : " << y;
    }

    ~abc(){
        delete y;
    }
};

int main()
{
    cout<<"Object a banaya : " << endl;
    abc a(2, 3);
    a.print();
    cout<<endl<< "object b banaya : " << endl;
    abc b(a);
    b.print();
    cout << endl;

    abc *c = new abc(20, 30); 
    abc d = *c;
    delete c;
    d.print(); 

    return 0;
}