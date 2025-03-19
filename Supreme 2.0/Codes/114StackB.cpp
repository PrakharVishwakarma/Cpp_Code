#include <iostream>
#include <vector>
#include <stack>

using namespace std;

vector<int> dailyTemperatures(vector<int>& temperatures) {
    int n = temperatures.size();
    vector<int> ans(n, 0);
    stack<int> st;
    for(int i = 0; i < n; i++){
        while(!st.empty() && temperatures[i] > temperatures[st.top()] ){
            ans[st.top()] = i - st.top();
            st.pop();
        }
        st.push(i);
    }
    return ans;
}

int main(){
    vector<int> temperatures = {73,74,75,71,69,72,76,73};
    vector<int> ans = dailyTemperatures(temperatures);
    int sizeOfAns = ans.size();

    for (int i = 0; i < sizeOfAns; i++){
        cout<<"On day "<<i+1<<" it will take "<<ans[i]<<" days to get a warmer temperature than today's temperature."<<endl;
    }
    
}