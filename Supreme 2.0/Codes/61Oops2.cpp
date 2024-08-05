#include <iostream>
using namespace std;

class abc
{
    int x;
    int *y;

public:
    abc()
    {
        x = 0;
        y = new int(0);
    }
    /*
        abc(int _x, int _y){
            x = _x;
            y = new int(_y);
        }
    */

    // One more way to write the Constructor is intialization list.
    abc(int _x, int _y) : x(_x), y(new int(_y)){};

    int getX() const
    { // Declaring const to the metod means this method can't ever change or set any of the member variable.
        return x;
    }
    void setX(int int_val) /*const*/
    {                      // If we add the const keyword, then class ke attribute var kabhi change nahi ho saktey.
        x = int_val;
    }
    int getY() const
    { //
        return *y;
    }
    void setY(int int_val)
    {
        *y = int_val;
    }
};

void printAbc(const abc &a)
{ // (const abc &a): if we are using const, then we can't access such a method in the function which is non const.
    cout << a.getX() << endl;
    cout << a.getY() << endl;
}
int main()
{
    abc a(1, 5);
    printAbc(a);

    return 0;
}
