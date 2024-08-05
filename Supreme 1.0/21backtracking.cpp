// Generate parantheses : Given n pair of parantheses write a function to generate all parentheses of well formed parantheses.

#include<iostream>
#include<vector>
using namespace std;

void solution(int avl_CloseBr , int avl_OpenBr , int used_CloseBr , int used_OpenBr , string output , vector<string>&ans){

    if(avl_CloseBr <= 0 && avl_OpenBr <= 0){
        ans.push_back(output);
        cout<<output<<" ";
        return;
    }

    if(avl_OpenBr>0){
        //Do : 
        output.push_back('(');
        // Recusrsion : 
        solution(avl_CloseBr , avl_OpenBr-1 , used_CloseBr , used_OpenBr+1 , output , ans);
        // Backtracking : 
        output.pop_back();
    }
    
    if(avl_CloseBr> avl_OpenBr){
        //Do : 
        output.push_back(')');
        // Recusrsion : 
        solution(avl_CloseBr-1 , avl_OpenBr , used_CloseBr+1 , used_OpenBr , output , ans );
        // Backtracking : 
        output.pop_back();
    }

}

int main(){
    
    int n;
    cout<<"Eneter the nunber of available brackets : ";
    cin>>n;

    vector<string>ans;
    int avl_CloseBr = n;
    int avl_OpenBr = n;
    int used_CloseBr = 0;
    int used_OpenBr = 0;
    string output = "";

    solution(avl_CloseBr , avl_OpenBr , used_CloseBr , used_OpenBr , output , ans );
    
 return 0;
}