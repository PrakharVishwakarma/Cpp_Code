#include<iostream>
#include<algorithm>
using namespace std;
int main()
{
    char ch='\0';
    cout<<"The value "<<ch<<endl<<endl;
    string s = "asd";
    s.erase(s.begin()+1);
    cout<<s;
return 0;
}