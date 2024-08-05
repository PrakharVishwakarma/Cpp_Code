// Print all permutation of String.

#include<iostream>
#include<algorithm>
using namespace std;

void printPermutation(string &str,int i,int &permuNum){
    if (i>=str.length())
    {
        cout<<permuNum<<".)"<<str<<" ";
        permuNum++;
        return;
    }
    

    for (int j = i; j < str.length(); j++)
    {
        swap(str[i],str[j]);
        printPermutation(str,i+1,permuNum);
        swap(str[i],str[j]);
    }
    
}
int main()
{
string str = "0123";
int permuNum = 1;
printPermutation(str,0,permuNum);
}