//  Leetcode : Return Longest pallindromic substring.
/*
    Input: s = "babad"
    Output: "bab"
*/

#include<iostream>
using namespace std;

bool checkPalindrome(string &plndrm, int i, int j)
{
    while (i < j)
    {
        if (plndrm[i] != plndrm[j]) return false;
        i++;
        j--;
    }
    return true;
}

string lngstPndrmSubStr(string &s){
    string ans = "";
    for (int i = 0; i < s.size(); i++)
    {
        for (int j = i; j < s.size(); j++)
        {
            if(checkPalindrome(s, i, j)){
                string t = s.substr( i , j-i+1);
                ans = t.size() > ans.size() ? t : ans;
            }
        } 
    }
    return ans;
}
int main(){
    string s = "ajjahaja";
    cout<<lngstPndrmSubStr(s);
    return 0;
}