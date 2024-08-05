#include <iostream>
#include <typeinfo>

using namespace std;

int main() {
    int intArray[] = {1, 2, 3, 4, 5};
    double doubleArray[] = {1.1, 2.2, 3.3, 4.4, 5.5};
    char charArray[] = {'a', 'b', 'c', 'd', 'e'};

    cout << "Data type of intArray: " << typeid(intArray).name() << endl;
    cout << "Data type of doubleArray: " << typeid(doubleArray).name() << endl;
    cout << "Data type of charArray: " << typeid(charArray).name() << endl;

    cout << "Is the array a derived data type?: " << is_array<int[5]>::value << endl;

    return 0;
}

/*
the <typeinfo> header for the typeid operator which returns a compiler-specific string representation of the type, which may not be human-readable in all cases.

*/