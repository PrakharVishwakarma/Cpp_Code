// Leetcode 1047 : Remove all adjecent duplicate of a string.

#include <iostream>
#include <algorithm>
#include <stack>
using namespace std;

string removeDupliAdj(string &str)
{
    int i = 0;
    stack<char> st;
    for (auto ch : str)
    {
        if (!st.empty() && st.top() == ch)
        {
            st.pop();
        }
        else
        {
            st.push(ch);
        }
    }
    string ans;
    while (!st.empty())
    {
        ans += st.top();
        st.pop();
    }
    reverse(ans.begin(), ans.end());
    return ans;
}

int main()
{
    string str = "abbaca";
    cout << str << endl;
    cout << removeDupliAdj(str);

    return 0;
}