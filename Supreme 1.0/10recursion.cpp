// Leetcode 415. Add Strings : Given two non-negative integers, num1 and num2 represented as string, return the sum of num1 and num2 as a string.
/* 
Example:
Input: num1 = "11", num2 = "123"
Output: "134"
*/

#include<iostream>
#include<algorithm>
using namespace std;

void addIntChar(string &s1 , int p1 , string s2, int p2 , string &ans, int carry){
    if (p1 < 0 && p2 < 0)
    {
        if (carry != 0)
        {
            ans.push_back(carry + '0');
        }
        return;
    }

    
    int n1 = ( p1>=0 ? s1[p1] : '0' )-'0';
    int n2 = ( p2>=0 ? s2[p2] : '0' )-'0';
    int sum = n1 + n2 + carry;

    if(sum>=10){
        carry = 1;
        sum = sum - (10*carry);
    } 
    else carry = 0;
    
    sum = sum +'0';
    

    ans.push_back(sum);

    addIntChar(s1, --p1, s2, --p2, ans, carry);

}

int main(){

    string s1;
    cout<<"Enter the string1 : ";
    cin>>s1;
    string s2;
    cout<<"Enter the string2 : ";
    cin>>s2;

    string ans = "";
    addIntChar(s1 , s1.size()-1 , s2 , s2.size()-1, ans , 0);
    reverse(ans.begin(),ans.end());
    cout<<ans;
    return 0;
}
