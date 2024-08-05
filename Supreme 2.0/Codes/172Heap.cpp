#include <iostream>
#include <vector>
#include <queue>
using namespace std;
// Leetcode 767 : Reorganize String.

class Info
{ 
public:
    char val;
    int count;

    Info(char ch, int cnt)
    {
        this->val = ch;
        this->count = cnt;
    }
};

class compare
{
public:
    bool operator()(Info a, Info b)
    {
        return a.count < b.count;
    }
};

string reorganizeString(string &s)
{
    int freq[26] = {0};
    string ans = "";
    // Firstly count the frequency of all characters in string.
    for (int i = 0; i < s.length(); i++)
    {
        freq[s[i] - 'a']++;
    }
    // Push all character in maxHeap:
    priority_queue<Info, vector<Info>, compare> maxHeap;

    for (int i = 0; i < 26; i++)
    {
        if (freq[i] > 0)
        {
            Info temp(i + 'a', freq[i]);
            maxHeap.push(temp);
        }
    }
    while (maxHeap.size() > 1)
    {
        Info first = maxHeap.top();
        maxHeap.pop();
        Info second = maxHeap.top();
        maxHeap.pop();
        ans.push_back(first.val);
        first.count--;
        ans.push_back(second.val);
        second.count--;

        if (first.count > 0)
            maxHeap.push(first);
        if (second.count > 0)
            maxHeap.push(second);
    }
    if (maxHeap.size() == 1)
    {
        Info remainingChar = maxHeap.top();
        maxHeap.pop();

        if (remainingChar.count > 1)
            return "";

        ans.push_back(remainingChar.val);
        remainingChar.count--;
    }
    return ans;
}

int main()
{
    string s = "parakphhapkpr";
    cout << reorganizeString(s);
    return 0;
}