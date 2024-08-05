#include <iostream>
using namespace std;

int x = 1;

int main()
{

    // cout<<x;

    /*
    int x = 4;
    cout<<x<<endl;
    cout<<::x<<endl;  // to print the global var.
    */

    /*
     ::x += 10;
     cout<<x<<endl;
    */

    /*
   int *a = new int(2);
   cout<<a<<endl;
   cout<<*a<<endl;
    delete(a);
   int b = 5;
   a = &b;
   cout<<*a;    // There is memory leakage . To prevent first delete
    */

    // Const Keyword :
    // 1. Data is constant but pointer is non const.

    const int *a = new int(2);
    // int const *a = new int(2); // Following can be written as like this.

    cout << a << endl;
    cout << *a << endl;
    /*
    *a = 20;
    cout<<*a<<endl;     throws an error because as written above, we cant change the data
    */
    int b = 20;
    a = &b;
    cout << *a << endl; // Now the data has been changed cause we can change the address due to change in address.That's why it is called const DATA non const POINTER.

    // 2. Const pointer and Non Const DATA.

    int *const ptr = new int(200);
    cout << *ptr << endl;
    *ptr = 4000;
    cout << *ptr << endl;

    // But What if we try to change the address/pointer.
    /*
    ptr = &b;
    cout<<*ptr; // Throws an error : assignment of read-only variable 'ptr'.
    */

    // 3. For const POINTER and const DATA.
    /*
        const int *const ptrr = new int(200);
        cout<<*ptrr<<endl;
        *ptrr = 4000;
        cout<<*ptrr<<endl;   //Throws an error

        ptrr = b;
        cout<<*ptrr<<endl;  //Throws an error
    */

    return 0;
}
