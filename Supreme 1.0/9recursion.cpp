// Last occusrence of a character in a string.

#include<iostream>
using namespace std;

void lastOcc(string &s , char x , int size , int iterator){
    if (iterator < 0)
    {
        return ;
    }
    
    if (s[iterator] == x)
    {
        cout<<"Element found at index "<<iterator;
        return;
    }
    
    
    lastOcc(s , x , size , --iterator);
    
}


int main(){

    string s;
    cout<<"Enter the string : ";
    cin>>s;
    cout<<"Enter the string character : ";
    char x; 
    cin>>x;

    // lastOcc(s , x , s.size() , (s.size()-1));
    
    return 0;
}
// One more way is there which is left to right traversal.
