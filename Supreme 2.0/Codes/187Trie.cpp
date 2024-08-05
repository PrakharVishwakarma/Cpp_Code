#include<iostream>
#include<vector>
using namespace std;

class TrieNode{
public:
    char value;
    TrieNode* children[26];
    bool isTerminal;
    TrieNode(char val){
        this->value = val;
        for (int i = 0; i < 26; i++)
        {
            children[i] = NULL;
        }
        this->isTerminal = false;
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

void storeString(TrieNode* root, vector<string> &ans, string input, string &prefix){
    if (root->isTerminal == true)
        ans.push_back(prefix + input);
    
    for (char i = 'a'; i <= 'z'; i++)
    {
        int index = i - 'a';
        TrieNode* next = root->children[index];
        if (next != NULL)
        {
            input.push_back(i);
            storeString(next, ans, input, prefix);
            input.pop_back();
        }
        
    }    
}
void wordsFromPrefix(TrieNode* root, string input, vector<string> &ans, string &prefix){
    if (input.length() == 0){
        TrieNode* lastChar = root;
        storeString(lastChar, ans, input, prefix);
        return;
    }

    char ch = input[0];
    int index = ch - 'a';
    TrieNode* child;

    if (root->children[index] != NULL)
        child = root->children[index];

    else return;
    wordsFromPrefix(child, input.substr(1), ans, prefix);
}

vector<vector<string>> getSuggestions(TrieNode* root, string input){
    vector<vector<string>>output;
    TrieNode* prev = root;
    string inputHelper = "";

    for (int i = 0; i < input.length(); i++)
    {
        char lastChar = input[i];
        int index = lastChar - 'a';
        TrieNode* curr = prev->children[index];

        if(curr == NULL) break;
        else{
            vector<string>nicheKaAns;
            inputHelper.push_back(lastChar);
            string dummy = "";
            storeString(curr, nicheKaAns, inputHelper, dummy);
            output.push_back(nicheKaAns);
            
            prev = curr; // Important Step
        }
    }
return output;
}
int main(){
    TrieNode* root = new TrieNode('-');

    insertWord(root, "cater");
    insertWord(root, "care");
    insertWord(root, "con");
    insertWord(root, "lover");
    insertWord(root, "loved");
    insertWord(root, "lower");
    insertWord(root, "load");
    insertWord(root, "lov");
    insertWord(root, "bat");
    insertWord(root, "cat");
    insertWord(root, "car");

    cout<<"Insertion in Trie is Done."<<endl;

    string input = "c";
    vector<string> ans;
    string prefix = input;
    wordsFromPrefix(root, input, ans, prefix);

    for (auto i:ans){
        cout<<i<<" ";
    }cout<<endl<<endl;
    
    /*
    loa: 
    l : load lov loved lover lower;
    lo : load lov loved lover lower
    loa : load
    */
    string input2 = "loa";
    vector<vector<string>>ans2 = getSuggestions(root, input2);
    for (auto i:ans2){
        for(auto ch:i){
            cout<<ch<<" ";
        }
        cout<<endl;
    }cout<<endl;

return 0;
}