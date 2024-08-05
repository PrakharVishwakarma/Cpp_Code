// Print all the subarrays : 

#include<iostream>
#include<vector>
using namespace std;

void printSubArrUtil(vector<int>&v , int start , int end){

    if (end >= v.size())return;
    
    for (int i = start; i <= end; i++){
        cout<<v[i]<<" ";
    }
    cout<<endl;
    printSubArrUtil(v , start , end+1);
}
int main(){
    vector<int>v = {1,2,3,4,5};
    
    for (int start = 0; start < v.size() ; start++)
    {
        int end = start;
        printSubArrUtil(v , start , end);
        cout<<endl;
    }
    
    return 0;
}