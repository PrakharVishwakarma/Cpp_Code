// Leetcode 32: Longest Valid parentheses

#include<iostream>
#include<vector>
#include<stack>
#include<algorithm>
#include<string>

using namespace std;

int longestValidParentheses(string &s) {
    int lenS = s.length();
    int maxValidLen = 0;
    stack<int> st;
    st.push(-1);
    for(int i = 0; i < lenS; i++) {
        if(s[i] == '('){
            st.push(i);
        }else{
            st.pop();
            if(st.empty()){
                st.push(i);
            }else{
                maxValidLen = max(i - st.top(), maxValidLen);
            }
        }
    }
    return maxValidLen;
} 

int main(){
    string s = "))))()";
    cout<<"the length of the longest valid (well-formed) parentheses substring is : "<<longestValidParentheses(s);
    return 0; 
}

