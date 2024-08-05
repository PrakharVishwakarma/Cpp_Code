#include <iostream>
using namespace std;

int main()
{
    int a = 78;
    cout << "Namastey Dunia ! \n" << endl; // endl OR '\n' : New line .  "Namastey Duni \n" or "Namastey Duni" << '\n' ;
    cout << "the value of a is " << a << endl;

    int size = sizeof(a);
    cout << "The size of a is " << size << endl;

    // typecasting :
    int b = 'b';
    cout << "Now the value of b is " << b << endl;

    char c = 99;
    cout << "Now the value of c is " << c << endl;

    char ch1 = 12345;
    cout << "Now the value of ch1 is " << ch1 << endl;

    unsigned int a1 = 123;
    cout << "the value of a1 is " << a1 << endl;

    unsigned int a2 = -123;
    cout << "the value of a2 is " << a2 << endl;
}