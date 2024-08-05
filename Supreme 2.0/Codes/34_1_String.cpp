/* Leetcode : 12. Integer to Roman
    Constraints: 1 <= num <= 3999
*/

#include <iostream>
using namespace std;

string intToRoman(int num)
{
    string romanSym[] = {"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};
    int values[] = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
    string ans = "";
/*
    for (int i = 0; i < 13; i++)
    {
        while (num >= values[i])
        {
            ans += romanSym[i];
            num -= values[i];
        }
    }
*/
    int length = 13;
    int i = 0;
    while (i < length)
    {
        if (values[i] > num)
        {
            i++;
        }
        else
        {
            num -= values[i];
            ans += romanSym[i];
        }
    }

    return ans;
}

int main()
{
    int num = 1914;
    cout << "Roman representation of number " << num << " is " << intToRoman(num);

    return 0;
}