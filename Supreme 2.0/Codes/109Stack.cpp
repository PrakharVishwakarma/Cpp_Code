// Leetcode 394 : Decode String:

#include<iostream>
#include<stack>
#include <sstream>
#include<string>
#include<algorithm>

using namespace std;

string decodeString(string &str){
    stack<string>st;

    for(auto ch : str){
        if(ch == ']')
        {
            string stringToRepeat = "";
            while (!st.empty() && st.top()[0] == '[')
            {
                string top = st.top();
                stringToRepeat += top;
                st.pop();
            }
            st.pop();

            string numericTime = "";
            while (!st.empty() && isdigit(st.top()[0]) )
            {
                numericTime += st.top();
                st.pop();
            }
            reverse(numericTime.begin(), numericTime.end());
            int numTimesToRepeat = stoi(numericTime);

            string currentDecodedString = "";
            while (numTimesToRepeat--)
            {
                currentDecodedString += stringToRepeat;
            }
            st.push(currentDecodedString);
        }
        else{
            string temp(1,ch);
            st.push(temp);
        }
    }
    string ans;
    while (!st.empty())
    {
        ans+=st.top();
        st.pop();
    }
    reverse(ans.begin(),ans.end());    
return ans;
}

int main(){
    string str = "3[a2[bc]]4ab";
    cout<<"Decoded String is : "<<decodeString(str);
return 0;
}