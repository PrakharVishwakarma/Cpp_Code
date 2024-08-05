// Leetcode 443 : Stiring Compression.
/*
Input: chars = ["a","a","b","b","c","c","c"]
Output: Return 6, and the first 6 characters of the input array should be: ["a","2","b","2","c","3"]
*/

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int compress(vector<char> &s)
{
    int index = 0;
    char prev = s[0];
    int count = 1;

    for (int i = 1; i < s.size(); i++)
    {
        if (s[i] == prev)
        {
            count++;
        }
        else
        {
            s[index++] = prev;
            if (count > 1)
            {
                int start = index;
                while (count)
                {
                    s[index++] = count % 10 + '0';
                    count /= 10;
                }
                reverse(s.begin() + start, s.begin() + index);
            }
            prev = s[i];
            count = 1;
        }
    }

    s[index++] = prev;
    if (count > 1)
    {
        int start = index;
        while (count)
        {
            s[index++] = count % 10 + '0';
            count /= 10;
        }
        reverse(s.begin() + start, s.begin() + index);
    }
    return index;
}

int main()
{
    vector<char> chars = {'a', 'a', 'b', 'b', 'c', 'c', 'c'};
    cout << compress(chars)<<endl;
    for (int i = 0; i < chars.size(); i++)
    {
        cout<<chars[i]<<endl;
    }
    
    return 0;
}