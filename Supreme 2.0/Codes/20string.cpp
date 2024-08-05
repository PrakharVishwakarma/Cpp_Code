// Leetcode 2325 : Encoding and Decoding 

#include<iostream>
using namespace std;


int main(){
    string key = "the quick brown fox jumps over the lazy dog";
    string msg = "vkbs bs t suepuv";
    char mapping[256] = {0}; 

    char start = 'a';
    // First Set the mapping from a (in mapping) with key  :
    for(auto it : key){
        if (mapping[it] == 0)
        {
            if (it ==' ')
            {
                mapping[it] = ' ';
            }
            else{
            mapping[it] = start;
            start++;
            }
        }
        
    } 

    // Decoding the message : 
    cout<<"Deconded message is : ";
    for(auto i : msg){

        cout<<mapping[i];
    }
    return 0;
}

// Leetcode : 2391. Minimum Amount of Time to Collect Garbage(solved on leetcode)

// Leetcode 791 : Custom Sort String(solved on leetcode)

// Leetcode 890. Find and Replace Pattern(solved)
