//Leetcode 85: Maximal rectangle in binary matrinx : Given a rows x cols binary matrix filled with 0's and 1's, find the largest rectangle containing only 1's and return its area.


// It is solved using the 
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

int maximalRectangle(vector<vector<char>>& matrix) {
    vector<vector<int>> v;
    int n = matrix.size();
    int m = matrix[0].size();
    for(int i = 0; i < n; i++){
        vector<int> temp;
        for (int j = 0; j < m; j++){
            temp.push_back(matrix[i][j] - '0');
        }
        v.push_back(temp);
    }

    int currArea = largestRectangleArea(v[0]);
    for(int i = 1; i < n; i++){
        for (int j = 0; j < m; j++){
            if(v[i][j] == 1) v[i][j] += v[i-1][j];
            else v[i][j] = 0;
        }
        currArea = max(currArea, largestRectangleArea(v[i]));
    }
    return currArea;
}

int main(){
    vector<vector<char>> matrix = {{'1','0','1','0','0'},
                                    {'1','0','1','1','1'},
                                    {'1','1','1','1','1'},
                                    {'1','0','0','1','0'}};

    cout<<"the largest rectangle containing only 1's is :  "<<maximalRectangle(matrix)<<endl;

    return 0;
}