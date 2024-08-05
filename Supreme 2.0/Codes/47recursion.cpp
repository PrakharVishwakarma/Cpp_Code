// Leetcode : 1910. Remove All Occurrences of a Substring
/*
Input: s = "daabcbaabcbc", part = "abc"
Output: "dab"
*/

#include<iostream>
using namespace std;
void remove(string &s, string &part){
    int pos = s.find(part);
    if (pos == string::npos) return;
    else{
        s.erase(pos,part.length());
        remove(s,part);
    }
}

int main(){
    string s = "daabcbaabcbc", part = "abc";
    remove(s,part);
    cout<<s;
    return 0;
}