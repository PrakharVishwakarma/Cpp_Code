// Check the redundand bracket in the expression

#include<iostream>
#include<stack>
using namespace std;

bool isRedundantBracket(string &str){
    stack<char>st;
    for (int i = 0; i < str.length(); i++){
        char ch = str[i];
        if(ch == '(' ||ch == '+' ||ch == '-' ||ch == '*' ||ch == '/'){
            st.push(ch);
        }else if(ch == ')'){
            int operatorCnt = 0;
            while (!st.empty() && st.top() != '('){
                char temp = st.top();
                if(temp == '+' ||temp == '-' ||temp == '*' ||temp == '/'){
                    operatorCnt++;
                }
                st.pop();
            }
            st.pop();
            if(operatorCnt == 0)return true;   
        }
    }
    return false;
}


int main(){
    string str = "((a+b)*(c+d))";

    if(isRedundantBracket(str)){
        cout<<"Expression have the redundant bracket present.";
    }else{
        cout<<"Expression don't have the redundant bracket present.";
    }

    return 0;
}