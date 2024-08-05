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
};

int main()
{
    cout << "Object a banaya : " << endl;
    abc a(2, 3);
    a.print();
    cout << endl
         << "object b banaya : " << endl;
    abc b(a);
    b.print();

    return 0;
}