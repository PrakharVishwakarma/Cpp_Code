// Leetcode : 345 : Reverse Vowels of a String
/*
Input: s = "leetcode"
Output: "leotcede"
*/

#include<iostream>
using namespace std;

bool isVowel(char &ch) {
  switch (tolower(ch)) {
    case 'a':
    case 'e':
    case 'i':
    case 'o':
    case 'u':
      return true;
    default:
      return false;
  }
}

string reverseVowel(string &s){
    int l = 0;
    int h = s.size() - 1;
    while(l<h)
    {
        if(isVowel(s[l]) && isVowel(s[h]))
        {
            swap(s[l] , s[h]);
            l++;
            h--;
        }
        else if(!isVowel(s[l])) l++;
        else h--;
    }
    return s;
}

int main()
{
    string s = "leetcode";
    cout<<reverseVowel(s);
}
