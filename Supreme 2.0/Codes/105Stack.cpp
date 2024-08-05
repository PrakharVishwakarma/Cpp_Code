// Leetcode 1019 : Next greater node in the linked list.
/*
 2->7->4->3->5

*/
#include<iostream>
#include<vector>
#include<stack>
using namespace std;
    
vector<int> nextLargerNode(int *arr , int &n){
    vector<int>ans(n);
    stack<int>st;

    for (int i = 0; i < n; i++){
        while (!st.empty() && arr[i] > arr[st.top()])
        {
            int kids = st.top();
            st.pop();
            ans[kids] = arr[i];
        }
        st.push(i);
    }
    
return ans;
} 


int main(){
 
    int arr[] = {2, 7, 4, 3, 5};
    int size = sizeof(arr)/sizeof(int);
    for (int i = 0; i < size; i++)
    {
        cout<<arr[i]<<" ";
    }cout<<endl;
    vector<int>ans = nextLargerNode(arr , size);
    for (int i = 0; i < ans.size(); i++)
    {
        cout<<ans[i]<<" ";
    }
    

return 0;
}