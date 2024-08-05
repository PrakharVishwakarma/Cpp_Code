// leetcode : 415 ; Add Strings

#include <iostream>
#include <algorithm>
using namespace std;

void add(string &num1, string &num2, int p1, int p2, int carry, string &ans){
    if (p1 < 0 && p2 < 0){
        if (carry != 0)ans.push_back(carry + '0');
        return;
    }

    int n1 = (p1 >= 0 ? num1[p1] : '0') - '0';
    int n2 = (p2 >= 0 ? num2[p2] : '0') - '0';
    int sum = n1 + n2 + carry;
    carry = sum / 10;
    int digit = sum - (10*carry);
    ans.push_back(digit + '0');
    add(num1, num2, p1 - 1, p2 - 1, carry, ans);
}

int main()
{
    string ans = "";
    string num1 = "456", num2 = "777";
    add(num1, num2, num1.size() - 1, num2.size() - 1, 0, ans);
    reverse(ans.begin(), ans.end());
    cout << ans;
    return 0;
    ;
}