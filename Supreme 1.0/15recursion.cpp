// Leetcode 44. Wildcard Matching
/*
Given an input string (s) and a pattern (p), implement wildcard pattern matching with support for '?' and '*' where:

'?' Matches any single character.
'*' Matches any sequence of characters (including the empty sequence).
*/

/*
#include<iostream>
using namespace std;

bool isMatch(string s, string p,int si , int pi){
    if(si>=s.size() && pi>=p.size())return true;
    
    if(si==s.size() && pi>=p.size()){
        while(pi>=p.size()){
            if (p[pi]!='*')return false;
            pi++;
        }   
    }
          
    if (s[si]==p[pi] || p[pi]=='?')return(isMatch(s,p,si+1,pi+1));
        
    if (p[pi]=='*'){
        bool caseA = isMatch(s,p,si,pi+1);
        bool caseB = isMatch(s,p,si+1,pi);
        return caseA || caseB;
    }
    return false;
}


int main(){
    string s = "abcdefg";
    string p = "ab?d*g**";
    if (isMatch(s,p,0,0))cout<<"Successfull wild card matching of strings "<<s<<" and "<<p;
    else cout<<"Wild card matching unsecessfull of strings "<<s<<" and "<<p;
    
    return 0;
}
*/


// Perfect Square problem :  for ex.  13 :  13 = 1+1+1...+1(13 bar) , 13 = 2^2++3^2  
// Toh ab minimum count find karna hai perfect s+ke sum ka ki kitne mini. perfect square lage 13 banane me.
#include<iostream>
#include<cmath>
#include<limits.h>
using namespace std;

int findPerfSqrtCoun(int n){
    if(n==0) return 1;
    if(n<0) return 0;

    int i = 1;
    int ans = INT_MAX;
    while (i<= sqrt(n))
    {
        int numOfPerftSqr = 1 + findPerfSqrtCoun(n - (i*i));
        if (numOfPerftSqr < ans) ans = numOfPerftSqr;
        ++i;
    }
    return ans;

}

int main()
{
    int n;
    cout<<"Enter the value : ";
    cin>>n;
    cout<<"Minimum number of perfect square to form "<<n<<" is "<<(findPerfSqrtCoun(n)-1);
    return 0;
}


