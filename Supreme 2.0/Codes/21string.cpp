// leetcode 242 : Valid Anagram.

#include<iostream>
using namespace std;

bool checkAnagram(string &s , string &t){
    int mapArray[256] = {0};
    for (int i = 0; i < s.size(); i++){
        mapArray[s[i]]++;
    }
    for (int i = 0; i < t.size(); i++)
    {
        mapArray[t[i]]--;
    }
    for (int i = 0; i < 256; i++)
    {
        if(mapArray[i] != 0) return false;
    }
    
    return true;
}
int main(){
    string s = "anagram";
    string t= "nagaram";

    if(checkAnagram(s , t))cout<<"Valid Anagram";
    else cout<<"Not a valid Anagram";

}

