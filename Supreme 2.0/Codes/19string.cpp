
#include <iostream>
using namespace std;

/*  Leetcode 1047 : Remove all adjecent duplicates in string.*/ /*
 string removeAllDuplicate(string str){
     string ans = "";
     int index = 0;
     while (index < str.length()){
        if (ans.length() > 0 && str[index] == ans[ans.length() - 1]) ans.pop_back();
        else ans.push_back(str[index]);
     index++;
     }
    return ans;
 }
*/

/*  Leetcode 1910: Remove all substring occurance from a string */ /*
 string removeOcc(string &s, string &part)
 {
     while (s.find(part) != string::npos){
        s.erase(s.find(part), part.length());
     }
     return s;
 }
 */

/* Leetcode 680 : valid pallindome check. (removing one element is allowed.)*/
/*
bool checkPalindrome(string &plndrm, int i, int j)
{
    while (i <= j)
    {
        if (plndrm[i] != plndrm[j]) return false;
        i++;
        j--;
    }
    return true;
}
bool validPalindrom(string &plndrm)
{
    int i = 0;
    int j = plndrm.length() - 1;

    while (i <= j)
    {
        if (plndrm[i] == plndrm[j])
        {
            i++;
            j--;
        }
        else
        {
            bool chkWithoutIth = checkPalindrome(plndrm, i + 1, j);
            bool chkWithoutJth = checkPalindrome(plndrm, i, j - 1);

            return (chkWithoutIth || chkWithoutJth);
        }
    }
    return true;
}
*/

// Leetcode 647 :  Pallindromic substring. (Print count of all the pallindromic substring in a string.)
int expand(string s, int i, int j)
{
    int count = 0;
    while (i >= 0 && j < s.length() && s[i] == s[j])
    {
        count++;
        i--;
        j++;
    }
    return count;
}

int countAllSubstrPalindrome(string s)
{
    int totalCount = 0;
    for (int i = 0; i < s.length(); i++)
    {
        // Odd
        int j = i;
        int oddKaAns = expand(s, i, j);

        // Even
        j = i + 1;
        int evenKaAns = expand(s, i, j);
        totalCount = totalCount + oddKaAns + evenKaAns;
    }
    return totalCount;
}

int main()
{

    /*
    string str = "abbaca";
    cout<<removeAllDuplicate(str);
    */

    /*
     string s = "daabcbaabcbc", part = "abc";
     cout<<removeOcc(s, part);
    */

    /*
     string plndrm = "abcbda";
     if(validPalindrom(plndrm)) cout<<"Valid Palindrome.";
     else cout<<"Invalid";
    */

    string s = "dabcbe";
    cout<<countAllSubstrPalindrome(s);

    return 0;
}
