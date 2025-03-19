// Find just next smaller element and just previous smaller element of each element in an array.

#include<iostream>
#include<stack>
#include<vector>

using namespace std;

void findJustNxtSmlr(vector<int> &v, vector<int> &ans){
    stack<int> st;
    st.push(-1);
    for (int i = v.size()-1; i >= 0; i--){
        int curr = v[i];
        while (st.top() >= curr){
            st.pop();
        }
        ans[i] = st.top();
        st.push(curr);
    }
}

void findjustPrevSmalr(vector<int> &v, vector<int> &ans){
    stack<int>st;
    st.push(-1);
    for (int i = 0; i < v.size(); i++){
        int curr = v[i];
        while (st.top() >= curr){
            st.pop();
        }
        ans[i] = st.top();
        st.push(curr);
    }
}


int main(){
    vector<int> v = {10, 5, 3, 8, 6};

    vector<int> ans1(v.size());

    findJustNxtSmlr(v, ans1);

    for(int i = 0; i<v.size(); i++){
        cout<<"Just Next smaller element for "<<v[i]<<" is "<<ans1[i]<<endl;
    }cout<<endl;

    vector<int> ans2(v.size());
    findjustPrevSmalr(v, ans2);
    for(int i = 0; i < v.size(); i++){
        cout<<"Just prev smaller element for "<<v[i]<<" is "<<ans2[i]<<endl;
    }cout<<endl;


return 0;
}