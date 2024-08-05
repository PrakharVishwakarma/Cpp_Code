#include<iostream>
#include<algorithm>
using namespace std;

void reverseStr(string &str,int &s, int &e){
    if (s>= e)return;

    swap(str[s], str[e]);
    
    reverseStr(str, ++s, --e);
}
int main(){
    string str = "DVIUNSBDDIKBBK";
    int s = 0;
    int e = str.length();

    reverseStr(str, s, e);
    cout<<str;
return 0;
}