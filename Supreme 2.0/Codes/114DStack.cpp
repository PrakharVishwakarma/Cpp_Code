// Leetcode 921. Minimum Add to Make Parentheses Valid

#include<iostream>
#include<stack>

using namespace std;

int minAddToMakeValid(string &s) {
    int ans = 0;
    stack<char> st;
    for(char ch : s){
        if(ch == '('){
            ++ans;
            st.push(ch);
        }else{
            if(!st.empty()){
                --ans;
                st.pop();
            }else{
                ans++;
            }
        }
    } 
    return ans;
}

int main(){
    string s = "())";
    cout<<"the minimum number of moves required to make string : "<< s<<", valid is : "<<minAddToMakeValid(s)<<endl;

    return 0;
}