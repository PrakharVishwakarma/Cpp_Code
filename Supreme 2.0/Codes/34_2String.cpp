/*
 Leetcode : 1209. Remove All Adjacent Duplicates in String II
    Input: s = "deeedbbcccbdaa", k = 3
    Output: "aa"
*/

#include<iostream>
#include<vector>

using namespace std;

bool areLastK_1thSame(string &ans, char &newCh, int k_1){
    int it = ans.size()-1;
    for (int i = 0; i < k_1; i++)
    {
        if(newCh != ans[it]) return false;
        it--;
    }
    return true;
}
string removeDuplicates(string &s, int k) {
    string ans;
    int lengthOfS = s.length();

    for (int i = 0; i < lengthOfS; i++){
        char &newCh = s[i];   
        if(ans.size() < k-1)ans.push_back(newCh);
        else{
            if(areLastK_1thSame(ans, newCh, k-1)){
                for (int j = 0; j < k-1; j++) ans.pop_back();
            }
            else{
                ans.push_back(newCh);
            }
        }
    }
    return ans;
}

string removeDuplicatesUsingTwoPointer(string &s, int k) {
    int i = 0, j = 0;
    int sLen = s.length();
    vector<int> count(sLen);
    while(j<sLen)
    {
        s[i] = s[j];
        count[i] = 1;
        if(i>0 && s[i] == s[i-1])count[i] += count[i-1];
        
        if(count[i] == k)i-=k; 
        i++,j++;
    }
    return s.substr(0, i);
}   

int main(){

    string s = "deeedbbcccbdaa";
    int k = 3;
    cout<<"string after all such duplicate removals have been made : "<<removeDuplicates(s, k)<<endl;

    cout<<"string after all such duplicate removals have been made : "<<removeDuplicatesUsingTwoPointer(s, k)<<endl;


return 0;
}
