// Leetcode : 648 : Replace Words. 

#include<iostream>
using namespace std;

class TrieNode{
public:
    char value;
    bool isTerminal;
    TrieNode* children[26];

    TrieNode(char val){
        this->value = val;
        this->isTerminal = false;
        for (int i = 0; i < 26; i++)
        {
            children[i] = NULL;
        }
    }
};

void insertWord(TrieNode* root, string word){
   if (word.length() == 0){
        root->isTerminal = true;
        return;
    }
   char ch = word[0];
   int index = ch-'a';
   TrieNode* child;
   
   if (root->children[index] == NULL){
        child = new TrieNode(ch);
        root->children[index] = child;     
    }
   else{
        child = root->children[index];
    }
    insertWord(child, word.substr(1));
}

bool searchWord(TrieNode* root, string word){
    if(word.length() == 0){
        return root->isTerminal;
    }
    char ch = word[0];
    int index = ch-'a';
    TrieNode* child;

    if (root->children[index] != NULL)
        child = root->children[index];
    else
        return false;

    bool recursionKaAns = searchWord(child, word.substr(1));
    return recursionKaAns;
}

int main(){
    TrieNode* root = new TrieNode('-');


return 0;
}




// Leetcode : 208 : Implement Trie.
