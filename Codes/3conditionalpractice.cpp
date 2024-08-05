#include <iostream>
using namespace std;

int main()
{
    /*
     int a = 2;
    int b = a + 1;
    if ((a=3) == b){
        cout<<"The value of a is "<< a;
    }
    else if ( a > 0){
        cout<<"a is psitive";
    }
    else{
        cout << b;
    }
    */

    char ch;
    cout << "Enter character ";
    cin >> ch;

    if (ch > 'a' && ch < 'z')
    {
        cout << "character " << ch << " is lowecase \n";
    }
    else if(ch > 'A' && ch < 'Z')
    {
        cout << "character " << ch << " is upper case \n";
    }
    else
    {
        cout << " a is numeric ";
    }
}