// Print all the subsquence of a string.

#include<iostream>
using namespace std;

void prntSubs(string &s , string output, int index){
    if (index >= s.size()){
        cout<<"=> "<<output<<endl;
        return;
    }
    
    // exclude : 
    prntSubs(s , output , index+1);

    //include : 
    char ch = s[index];
    output.push_back(ch);
    prntSubs(s , output , index+1);

}

int main()
{
    string s = "abc";
    string output = "";
    prntSubs(s , output , 0);
}


/*
void prntSubs(string &s , string output, int index){
    if (index >= s.size()){
        cout<<output<<endl;
        return;
    }
    

    //include : 
    char ch = s[index];
    output.push_back(ch);
    prntSubs(s , output , index+1);
    output.pop_back();

    // exclude : 
    prntSubs(s , output , index+1);
}
*/