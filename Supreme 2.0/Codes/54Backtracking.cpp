// Leetcode 72. Edit Distance : Given two strings word1 and word2, return the minimum number of operations required to convert word1 to word2. You have the following three operations permitted on a word:
/*
You have the following three operations permitted on a word: Insert a character , Delete a character , Replace a character.

Input: word1 = "horse", word2 = "ros"
Output: 3
Explanation:
horse -> rorse (replace 'h' with 'r')
rorse -> rose (remove 'r')
rose -> ros (remove 'e')
*/

#include <iostream>
#include <algorithm>
using namespace std;

int minDistance(string &word1, string &word2, int i, int j)
{
  if (i >= word1.length())
    return word2.length() - j;
  if (j >= word2.length())
    return word1.length() - i;

  int ans = 0;
  if(word1[i]==word2[j]){
   ans = 0 + minDistance(word1,word2,i+1,j+1); 
  }
  else{
    //Insert : 
    int option2 = 1+minDistance(word1,word2,i,j+1);
    // Remove
    int option1 = 1+minDistance(word1,word2,i+1,j);    // 1+ karn nahi bhoolna hai.
    //Replace
    int option3 = 1+minDistance(word1,word2,i+1,j+1);

    ans = min(option1 , min(option2,option3));
  }
  return ans;
}

int main(){
  string word1 = "horse", word2 = "ros";
  cout <<"the minimum number of operations required to convert "<< word1<<" to " << word2<<" : "<<minDistance(word1, word2, 0, 0);
  return 0;
}
