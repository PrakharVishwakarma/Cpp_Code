// 28. Find the Index of the First Occurrence in a String
/*
Input: haystack = "sadbutsad", needle = "sad"
Output: 0
*/

#include<iostream>
using namespace std;

int strStr(string haystack, string needle) {
        for (int i = 0; i <= (haystack.size()-needle.size()); i++)
        {
            for (int j = 0; i < needle.size(); j++)
            {
                if(needle[j] != haystack[i+j])
                {
                    break;
                }
                if (j==(needle.size()-1))
                {
                    return i;
                }
            }   
        }
    return -1;
}

int main(){
    string haystack = "absadbutsad";
    string needle = "ad";
    cout<<strStr(haystack , needle);

    return 0;
}