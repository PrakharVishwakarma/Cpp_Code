//Print all the permutation of a string : 

#include<iostream>
using namespace std;

void printPermutation(string &s, int i){
    if (i>=s.length())
    {
        cout<<s<<" ";
        return;
    }
    
    for (int j = i; j < s.length() ; j++)
    {
        swap(s[i],s[j]);

        printPermutation(s, i+1);   //Recursion 

        swap(s[i],s[j]);            //Backtracking
    }
    

}
int main(){

    string s = "abc";
    int i = 0;
    printPermutation(s , i);

    return 0;
}

// Another approach.


/*
//Print all the permutation of a string : 

#include<iostream>
using namespace std;

void printPermutation(string s, int i){     // Passing without refrnce 
    if (i>=s.length())
    {
        cout<<s<<" ";
        return;
    }
    
    for (int j = i; j < s.length() ; j++)
    {
        swap(s[i],s[j]);

        printPermutation(s, i+1);   //Recursion 

        // swap(s[i],s[j]);            //Backtracking
    }
    

}
int main(){

    string s = "abc";
    int i = 0;
    printPermutation(s , i);

    return 0;
}
 
*/