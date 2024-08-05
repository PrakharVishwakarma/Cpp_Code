#include<iostream>
#include<queue>
#include<vector>
#include<unordered_set>
using namespace std;

int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
    queue<pair<string, int> > q;
    q.push({beginWord, 1});

    unordered_set<string> st(wordList.begin(), wordList.end());

    st.erase(beginWord);

    while (!q.empty())
    {
        pair<string, int> fNode = q.front();
        q.pop();

        string currString = fNode.first; 
        int currCount = fNode.second; 

        if(currString == endWord) return currCount;

        for (int i = 0; i < currString.length(); i++)
        {
            char orginalChar = currString[i];
            for(char ch = 'a'; ch <= 'z'; ch++){
                currString[i] = ch;
                if(st.find(currString) != st.end()){
                    q.push({currString, currCount+1});
                    st.erase(currString);
                }
            }
            currString[i] = orginalChar;
        }
    }

return 0;
} 

int main(){
    string beginWord = "hit", endWord = "cog";
    vector<string> wordList = {"hot","dot","dog","lot","log","cog"};

    cout<<"the number of words in the shortest transformation sequence from beginWord to endWord : "<<ladderLength(beginWord, endWord, wordList)<<endl;

return 0;
}