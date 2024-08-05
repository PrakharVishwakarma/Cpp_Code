#include <iostream>
using namespace std;

class abc
{
    int x;
    mutable int *y;     // Used during the debugging of the code
    // abc *this;

public:
    abc()
    {
        x = 0;
        y = new int(0);
    }
    abc(int x, int _y)
    {
        this->x = x; // This pointer is added by the compiler privately.[Line no. 8]
        y = new int(_y);
    }

    int getX() const    // this method can't ever change any of the member variable.
    { 
        return x;
    }
    void setX(int int_val) /*const*/
    {                      // If we add the const keyword, then class ke attribute var kabhi change nahi ho saktey.
        x = int_val;
    }
    int getY() const
    {
        *y = 500; // Here y is changing still the method is const declayered cause y attribute is declayered mutable int *y within the class.
        return *y;
    }
    void setY(int int_val)
    {
        *y = int_val;
    }
};

void printAbc(const abc &a)
{
    cout << a.getX() << endl;
    cout << a.getY() << endl;
}
int main()
{
    abc a(1, 5);
    printAbc(a);

    return 0;
}
