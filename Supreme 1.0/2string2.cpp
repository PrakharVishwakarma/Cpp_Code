#include <iostream>
#include <string>
using namespace std;

int main()
{

    string str = "Hello World ";
    cout << str.size() << endl;
    cout << str.capacity() << endl;

    string::iterator i = str.begin();
    cout << *i << endl;

    i = str.end();
    cout << *i << endl;

    for (auto it = str.cbegin(); it != str.cend(); ++it)
        std::cout << *it;

    cout << endl
         << "max_size: " << str.max_size() << "\n";

    str.resize(str.size() + 2, '!');
    cout << str << endl;

    cout << endl
         << str.size() << endl;
    str.resize(9);
    cout << str.size() << endl;
    cout << str.capacity() << endl;
    str.shrink_to_fit(); // Confusion in this.
    cout << str << endl;
    cout << str.size() << endl;
    cout << str.capacity() << endl;

    cout << str.front() << endl;
    cout << str.back() << endl;

    str.reserve(100);
    cout << str.capacity() << endl;

    str.clear();
    cout << endl
         << str;

    string str1 = "Namah";
    string str2 = " shivaye ";

    // // Append str2 to str1.
    // str1 += str2;
    // cout << str1 << endl; // Prints "HelloWorld"

    // str1.assign(str2);
    // Assign the value of str2 to str1.

    // cout << endl << str1 << endl; // Prints "World"

    string str3;
    getline(cin,str3);
    cout<<str3;

    
    return 0;
}

