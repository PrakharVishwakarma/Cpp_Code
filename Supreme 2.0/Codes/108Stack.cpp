// Leetcode 1033 : Check if word is valid after substitutaion.

#include<iostream>
#include<stack>

using namespace std;

bool isValid(string str){
    if (str.size() == 0)return true;

    int found = str.find("abc");
    if (found != string::npos)
    {
        string tLeft = str.substr(0, found); 
        string tRight = str.substr(found+3 , str.size());
    return isValid(tLeft + tRight);
    }
    
return false;
}
// Following solution takes 0(n^2);

bool isValidUsingStack(string str){
    if (str[0] != 'a')return false;

    stack<char>st;
    for(auto ch : str){
        if (ch == 'a')
        {
            st.push(ch);
        }
        else if (ch == 'b')
        {
            if (!st.empty() && st.top() == 'a')
            {
                st.push(ch);
            }
            else{
                return false;
            }
        }
        else{
            if (!st.empty() && st.top() == 'b'){
            st.pop();
                if (!st.empty() && st.top() == 'a')
                {
                    st.pop();
                }
                else{
                    return false;
                }
            }
            else{
                return false;
            }
        }   
    }

return st.empty();
}

int main(){
    string str = "aabcbc";
    if (isValid(str))
    {
        cout<<"word is valid after substitutaion."<<endl;
    }else{
        cout<<"word is not valid after substitutaion."<<endl;
    }

    if (isValidUsingStack(str))
    {
        cout<<"word is valid after substitutaion."<<endl;
    }
    else{
        cout<<"word is not valid after substitutaion."<<endl;
    }
    
return 0;
}