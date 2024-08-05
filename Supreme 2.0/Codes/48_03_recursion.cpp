// Print all the subsequence of the array (by using bit manipulation)

#include <iostream>
#include <cmath>
using namespace std;

void printSubsequence(string &str)
{
    int numOfSubs = pow(2, str.size());
    for (int i = 0; i < numOfSubs; i++)
    {
        string out;
        int num = i;

        int count = 0;
        while (num)
        {
            int lastBit = (num & 1);
            if (lastBit)out.push_back(str[count]);
            count++;
            num >>= 1;
        }
        cout << out << endl;
    }
}
int main()
{
    string str = "abc";
    printSubsequence(str);
    return 0;
}