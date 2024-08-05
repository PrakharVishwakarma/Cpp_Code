// 767. Reorganize String
/*

Input: s = "aab"
Output: "aba"

Input: s = "aaab"
Output: ""

*/

#include<iostream>
#include<limits.h>
#include<vector>
using namespace std;

string reorganizeString(string s)
{
        int hash[26]= {0};

        for (int i = 0; i < s.size(); i++){
            hash[s[i] - 'a']++;
        }
        // Find the most frequent character : 
        char mostFrqChar;
        int maxFreq = INT_MIN;
        for (int i = 0; i < 26; i++){
            if(hash[i]>maxFreq)
            {
                maxFreq = hash[i];
                mostFrqChar = i+'a';
            }
        }
        int index = 0;
        while (index<s.size() && maxFreq > 0){
            s[index] = mostFrqChar;
            maxFreq--;
            index+=2;
        }
        if(maxFreq != 0) return "";
        hash[mostFrqChar - 'a'] =0;
        //Lets place the rest of character : 
        for (int i = 0; i < 26; i++){
            while(hash[i]>0){
                index = index>=s.size() ? 1 : index;
                s[index] = i + 'a';
                hash[i]--;
                index +=2;
            }   
        }
    return s; 
}

int main(){
    string s = "aab";
    cout<<reorganizeString(s);

    return 0;
}