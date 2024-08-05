// First non repeating character in a stream

#include<iostream>
#include<queue>

using namespace std;

int main(){
string str = "facfdcad";

queue<char>q;
int freqCount[26] = {0};
for (int i = 0; i < str.length(); i++)
{
    char ch = str[i];
    freqCount[ch-'a']++;
    q.push(ch);

    while (!q.empty())
    {
        char frontChar = q.front();
        if (freqCount[frontChar - 'a'] > 1)
        {
            q.pop();
        }
        else{
            cout<<frontChar<<"->";
            break;
        }
    }
    if (q.empty())
    {
        cout<<"#"<<"->";
    }
    
}


return 0;
}