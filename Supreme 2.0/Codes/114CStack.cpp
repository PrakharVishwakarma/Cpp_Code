// Leetcode 402 Remove K Digits

#include <iostream>
#include <stack>
#include <algorithm>

using namespace std;

string removeKdigits(string &num, int k)
{
    stack<char> st;

    for (char digit : num)
    {
        if (k > 0)
        {
            while (!st.empty() && st.top() > digit)
            {
                st.pop();
                k--;
                if (k == 0)
                    break;
            }
        }
        st.push(digit);
    }

    if (k > 0)
    {
        while (!st.empty() && k)
        {
            st.pop();
            k--;
        }
    }

    string result = "";
    while (!st.empty())
    {
        result.push_back(st.top());
        st.pop();
    }

    while (result.size() > 0 && result.back() == '0') result.pop_back();
    
    reverse(result.begin(), result.end());
    return result == "" ? "0" : result;
}

int main()
{
    string num = "1432219";
    int k = 3;

    cout << "The smallest possible integer after removing " << k << " digits from " << num << " is " << removeKdigits(num, k) << endl;
    return 0;
}