// Leetcode : 8 :string to integer(similar to C/C++'s atoi function).


#include<iostream>
#include<algorithm>
#include<limits.h>
using namespace std;

int myAtoi(string &s){
    int num = 0 , sign = 1, i=0;
    while(s[i]==' ') 
    {
        i++;
    }
    if(i < s.size() && (s[i] == '-' ||s[i] == '+')){
        sign = s[i] =='+' ? 1 : -1;
        ++i;
    }
    while (i<s.size() && isdigit(s[i]))
    {
            if(num>INT_MAX/10  || (num == INT_MAX / 10 && s[i]>'7')){
                return sign == -1 ? INT_MIN : INT_MAX;
            }
        num = num * 10 + (s[i]-'0');
        i++;
    }
    return sign*num;

}

int main(){

    string s = "   -42";
    int sToInt = myAtoi(s);
    cout<<sToInt;
return 0;
}

