// Leetcode 1776. Car Fleet II

#include <iostream>
#include <vector> 
#include <stack>

using namespace std;

vector<double> getCollisionTimes(vector<vector<int>> &cars){
    stack<int> st;
    vector<double> answer(cars.size(), -1);
    int n = cars.size();
    for (int i = n - 1; i >= 0; --i)
    {
        while (!st.empty() && cars[st.top()][1] >= cars[i][1])st.pop();

        while (!st.empty()){
            double collisionTime =(double) (double(cars[st.top()][0] - cars[i][0]) / double (cars[i][1] - cars[st.top()][1]));
            if(answer[st.top()] == -1 || collisionTime <= answer[st.top()]){
                answer[i] = collisionTime;
                break;
            } 
            st.pop();
        }
        st.push(i);
    }
    return answer;
}

int main()
{
    vector<vector<int>> cars = {{1, 2}, {2, 1}, {4, 3}, {7, 2}};
    vector<double> ans = getCollisionTimes(cars);

    for(double t : ans)cout << t << " ";
    
    return 0;
}