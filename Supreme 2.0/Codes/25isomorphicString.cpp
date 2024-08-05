 // 205. Isomorphic Strings
/*
Input: s = "paper", t = "title"
Output: true

Input: s = "foo", t = "bar"
Output: false
*/
#include <iostream>

using namespace std;

bool checkIsomorphic(string &s, string &t)
{
    int hash[256] = {0};
    bool isTCharMapped[256] = {0};

    for (int i = 0; i < s.size(); i++)
    {
        if (hash[s[i]] == 0 && isTCharMapped[t[i]] == 0)
        {
            hash[s[i]] = t[i];
            isTCharMapped[t[i]] = true;
        }
    }
    for (int i = 0; i < t.size(); i++)
    {
        if (char(hash[s[i]]) != t[i])
        {
            return false;
        }
    }
    return true;
}

int main()
{
    string s = "12", t = "u0067u0067";

    if (checkIsomorphic(s, t))
        cout << "strings are Isomorphic.";
    else
        cout << "Strings are not isomorphic.";
    return 0;
}