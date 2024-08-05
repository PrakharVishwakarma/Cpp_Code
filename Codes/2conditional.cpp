#include <iostream>
using namespace std;

int main()
{
    // int n ;
    // cout << "Enter n " << endl;
    // cin >> n;

    // if (n > 0)
    // {
    //     cout << "n is positive";
    // }
    // elseif(n < 0)
    // {
    //     cout << "n is negative";
    // }
    // else{
    //     cout << "n is 0";
    // }

    /*int n, m;
    cout << "Enter n and m \n";
    cin >> n >> m;

    if (n < m)
    {
        cout << "M is greater " << endl;
    }
    else{
        cout <<"N is greater \n";
    }
    */

/*   
   int o;
    cout << "Enter o \n";
    
    o = cin.get(); // Gives the ascii value of input.
    cout << "the value of o is " << o << endl;
 */

char ch1 ;
cout<<"Enter character ";
cin>>ch1;
cout<<"character is "<<ch1<< endl;
int ch2 = ch1;
if(ch2<=90 && ch2>=65){
    cout<<"character "<<ch1<<" is upper case .";
}
else if (ch2<=122 && ch2>=97){
    cout<<"character "<<ch1<<" is lower case .";
}
else{
    cout<<"character "<<ch1<<" is alphabet.";
}
return 0;
}