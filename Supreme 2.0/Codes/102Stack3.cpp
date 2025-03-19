// Leetcode : 84 : Largest Rectangle in Histogram

#include<iostream>
#include<stack>
#include<vector>
#include<limits.h>
#include<algorithm>

using namespace std;

void findJustNxtSmlr(vector<int> &v, vector<int> &ans){
    stack<int> st;
    st.push(-1);
    for (int i = v.size()-1; i >= 0; i--){
        int curr = v[i];
        while ( st.top() !=-1 && v[st.top()] >= curr ){
            st.pop();
        }
        ans[i] = st.top();
        st.push(i);
    }
}

void findjustPrevSmalr(vector<int> &v, vector<int> &ans){
    stack<int>st;
    st.push(-1);
    for (int i = 0; i < v.size(); i++){
        int curr = v[i];
        while (st.top() != -1 && v[st.top()] >= curr){
            st.pop();
        }
        ans[i] = st.top();
        st.push(i);
    }
}

int largestRectangleArea(vector<int>& heights) {
    vector<int> next(heights.size());
    findJustNxtSmlr(heights, next);
    for(int i = 0; i < next.size(); i++){
        if(next[i] == -1){
            next[i] = heights.size();  
        }
    }

    vector<int> prev(heights.size());
    findjustPrevSmalr(heights, prev);

    int maxArea = INT_MIN;
    for (int i = 0; i < heights.size(); i++){
        int currWidth = next[i] - prev[i] - 1;
        maxArea = max(maxArea, heights[i]*currWidth);     
    }
    return maxArea;
}

int main(){
    vector<int>heights = {2,1,5,6,2,3};

    cout<<"the area of the largest rectangle in the histogram : "<<largestRectangleArea(heights)<<endl;

return 0;
}