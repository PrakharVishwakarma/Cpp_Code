// Leetcode 6 : 6. Zigzag Conversion
/*
Input: s = "PAYPALISHIRING", numRows = 4
Explanation:
P     I    N
A   L S  I G
Y A   H R
P     I

Output: "PINALSIGYAHRPI"
*/

#include <iostream>
#include <vector>
using namespace std;

string convert(string s, int numRows)
{
    if (numRows == 1)return s;

    vector<string> zigZag(numRows);
    int row = 0, i = 0;
    bool direction = 1;

    while (true){
        if (direction){
            while (row < numRows && i < s.size())
            {
                zigZag[row++].push_back(s[i++]);
            }
            row = numRows - 2;
        }
        else{
            while (row >= 0 && i < s.size())
            {
                zigZag[row--].push_back(s[i++]);
            }
            row = 1;
        }

        if (i >= s.size())break;

        direction = !direction;
    }

    string ans;
    for (int i = 0; i < zigZag.size(); i++){
        ans+=zigZag[i];
        cout<<zigZag[i];
    }
    return ans;
}

int main()
{
    string s = "PAYPALISHIRING";
    int numRows = 4;
    convert(s, numRows);

    return 0;
}