// Leetcode 14 : Longest common prefix.
/*
Input: strs = ["flower","flow","flight"]
Output: "fl"

*/

#include <iostream>
#include <vector>

using namespace std;

string lCprefix(vector<string> &strs, string &ans)
{
    int i = 0;
    while (true)
    {
        char curr_ch = 0;
        for (auto str : strs)
        {

            if (i >= str.size())
            {
                curr_ch = 0;
                break;
            }

            if (curr_ch == 0)
            {
                curr_ch = str[i];
            }
            else if (str[i] != curr_ch)
            {
                curr_ch = 0;
                break;
            }
        }
        if (curr_ch == 0)
        {
            break;
        }

        ans.push_back(curr_ch);
        i++;
    }
    return ans;
}

int main()
{

    vector<string> strs = {"flower", "flow", "flowcahrt"};
    string ans;
    cout << "Longest common prefix is : " << lCprefix(strs, ans);
    return 0;
}
