//Alternate house robbery problem :     (Recursion - include/exclude)

#include<iostream>
#include<vector>

using namespace std;

int robbery(vector<int>&nums , int &i){

    //Base case :
    if (i>nums.size())return 0;
    
    //Recursion : 
    int robAmt1 = nums[i]+robbery(nums , ++(++i));
    int robAmt2 = 0 + robbery(nums , ++i);

    return max(robAmt1 , robAmt2);
}

int main(){

    int n;
    cout<<"What are the nuber of houses : ";
    cin>>n;
    vector<int>v;
    int money;
    cout<<"Enter the money having each house : ";
    for (int i = 0; i < n; i++)
    {
     cin>>money;
     v.push_back(money);   
    }
    cout<<"Amount having each ith house respectively : "; 
    for (int i = 0; i < v.size(); i++)
    {
        cout<<v[i]<<" ";
    }
    cout<<endl;

    int iterator = 0;
    cout<<"You can robber "<<robbery(v , iterator)<<" money.";
return 0;
}