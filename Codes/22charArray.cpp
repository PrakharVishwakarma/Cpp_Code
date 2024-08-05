#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

bool compare(char x , char y){
    return x > y;
}

int main(){
    
    string str = "shubh";
    cout<<str.size()<<endl; 
    cout<<str<<endl;

    sort(str.begin() , str.end(), );

    cout<<str;

 return 0;
}



