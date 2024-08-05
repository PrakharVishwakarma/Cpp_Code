// Integer to English word representaion : check the vedio recursion ->week7 assignment
/*
273. Integer to English Words :  Convert a non-negative integer num to its English words representation.

Example:
Input: num = 123
Output: "One Hundred Twenty Three"

Example :
Input: num = 1234567
Output: "One Million Two Hundred Thirty Four Thousand Five Hundred Sixty Seven"
*/

#include <iostream>
#include <vector>
using namespace std;

vector<pair<int, string>> np = {
    {1000000000, "billion"}, {1000000, "million"}, {1000, "thousand"}, {100, "hundred"}, {90, "ninety"}, {80, "eighty"}, {70, "seventy"}, {60, "sixty"}, {50, "fifty"}, {40, "forty"}, {30, "thirty"}, {20, "twenty"}, {19, "nineteen"}, {18, "eighteen"}, {17, "seventeen"}, {16, "sixteen"}, {15, "fifteen"}, {14, "fourteen"}, {13, "thirteen"}, {12, "twelve"}, {11, "eleven"}, {10, "ten"}, {9, "nine"}, {8, "eight"}, {7, "seven"}, {6, "six"}, {5, "five"}, {4, "four"}, {3, "three"}, {2, "two"}, {1, "one"}
};

string numberToWords(int &num)
{
    if (num == 0)
        return "zero";

    for (auto it : np)
    {
        if (num >= it.first)
        {

            string a = "";
            int numForA = num / it.first;
            if (num >= 100)
            {
                a = numberToWords(numForA) + " ";
            }
            string b = it.second;

            string c = "";
            int numForB = num - numForA * it.first;
            if (numForB != 0)
            {
                c = " " + numberToWords(numForB);
            }
            return a + b + c;
        }
    }
return "";
}
int main()
{
    int num = 1147483647;

    cout << numberToWords(num);
    return 0;
}

/*
//Wild card matching . :  To undesrtand the problem
#include<iostream>
using namespace std;

// Base case :
bool isMatchHelper(string &s , int si , string &p , int pi ){
    if (si == s.size() && pi == p.size()) return true;

    if (s[si] == p[pi] || '?' == p[pi])return isMatchHelper(s , si+1 , p ,  pi+1);

    if (si == s.size() && pi<p.size())
    {
        while(pi<p.size())
        {
            if (p[pi] != '*')return false;
           pi++;
        }
        return true;
    }

    //recursion :

    if(p[pi] == '*'){
        // treat '*' as a null string
        bool CaseA = isMatchHelper(s , si , p ,  pi+1);
        // let '*' consume one character.
        bool CaseB = isMatchHelper(s , si+1 , p ,  pi);
        return CaseA || CaseB;
    }
    //Nahin toh character match hi nahi kar rahe hain.
return false;

}

int main(){
    string s;
    cout<<"Enter the first string : ";
    cin>>s;

    cout<<'Enter the second string : ';
    string p;
    cin>>p;
    int siterator = 0;
    int piterator = 0;

    if(isMatchHelper(s , siterator , p ,  piterator )) cout<<"successfully Wild card matching .";
    else cout<<"Wild card matching unsuccessfull.";

    return 0;
}
*/