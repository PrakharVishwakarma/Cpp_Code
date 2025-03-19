// Leetcode 20 : Valid Parentheses


#include<iostream>
#include<stack>

using namespace std;

bool isValid(string &s) {
    stack<char>st;
    for (int i = 0; i < s.length(); i++){
        char ch = s[i];
        if(ch=='(' || ch=='{' || ch=='['){
            st.push(ch);
        }else{
            if(!st.empty()){
                if(ch == ')' && st.top() == '('){
                    st.pop();
                }else if (ch == '}' && st.top() == '{'){
                    st.pop();
                }else if(ch == ']' && st.top() == '['){
                    st.pop();
                }else{
                    return false;
                }
            }else{
                return false;
            }
        } 
    }
    return st.empty() ? true : false;
}


int main(){
    string s = "()[]{}";
    if(isValid(s)){
        cout<<"Input string follows valid paranthesis."<<endl;
    }else{
        cout<<"Input String doesn't follow valid paranthesis."<<endl;
    }

return 0;
}