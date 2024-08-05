#include<iostream>
#include<string>
#include<cstring>

using namespace std;

int main(int argc, char const *argv[]){
    string str1 = "World";
    char str2[10] = "Hello";
    string str3 = str1+str2;

    cout<<str3<<endl;

    const char *a = "Hello\0World";
    cout<<a<<endl;
    str1 = str1+'a';
    str1.push_back('m');
    str1.back() = '0';
    cout<<str1<<endl;
    string str4("helloIamMorris");
    cout<<str4.substr(3).substr(4)<<endl;
    cout<<str1<<endl<<strlen(str2)<<endl;

    string comp("microsoft");
    string::iterator r;
    for (auto r = comp.rbegin(); r < comp.rend(); r++)
    {
        cout<<*r;
    }
    string key("soft");
    size_t f;
    f = comp.rfind(key);
    cout<<endl<<f<<endl;
    cout<<&str2[2]<<" "<<str2+2<<0[str2]<<" "<<sizeof(str2)<<endl;
    char str5[] = {'a','b','c'};
    cout<<sizeof(str5)/sizeof(str5[0])<<endl;
    
return 0;
}