// GFF : Count the reversals 
// 1963. Minimum Number of Swaps to Make the String Balanced

#include<iostream>
#include<stack>
using namespace std;

int minSwaps(string s) {
    if(s.length() & 1)return -1;

    stack<int>st;
    for(char ch : s){
        if(ch == '['){
            st.push(ch);
        }else{
            if(!st.empty() && st.top() == '['){
                st.pop();           // Valid paranthesis are poped from the stack 
            }else{
                st.push(ch);        
            }
        }
    }
    int ans = 0;            // Stack only has unvalid paranthesis till now
    while (!st.empty()){
        char a = st.top(); st.pop();
        char b = st.top(); st.pop();
        (a==b) ? ans+=1 : ans+=2;
    }
    return ans;
}



int main()
{
    string s = "]]][[[";
    cout<<"Minimum Number of Swaps to Make the String Balanced are : " <<minSwaps(s); 

return 0;
}