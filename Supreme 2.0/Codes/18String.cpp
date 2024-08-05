#include<iostream>
using namespace std;

int main(){
    char charr[20];
    cout<<"Enter the character array : ";
    cin.getline(charr , 20);
    cout<<charr<<endl;
    
    int temp = 0;
    int i = 0;
    while (i<(sizeof(charr)/sizeof(char)))
    {
        temp = (int)charr[i];
        cout<<"At index "<<i<<" ascii value corresponding to "<<charr[i]<<" character is : "<<temp<<endl;
        i++;
    }
    cout<<"I";
    char ch = (int)11;  // It is printing vertical tab (endl).
    cout<<ch;
    cout<<"am";

    return 0;

}