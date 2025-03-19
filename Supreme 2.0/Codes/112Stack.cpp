// Leetcode 735. Asteroid Collision

#include <iostream>
#include <vector>
#include <stack>

using namespace std;

/*
vector<int> asteroidCollision(vector<int>& asteroids) {
    stack<int>st;
    for(auto ast : asteroids){
        if (ast > 0){
            st.push(ast);
        }
        else{
            while (!st.empty() && st.top() > 0 && st.top() < abs(ast)){
                st.pop();
            }
            if (st.empty() || st.top() < 0){
                st.push(ast);
            }
            else if (st.top() == abs(ast)){
                st.pop();
            }
        }
    }

    vector<int>ans(st.size());
    for (int i = st.size()-1; i >= 0; i--){
        ans[i] = st.top();
        st.pop();
    }
    return ans;
}
*/
/*
vector<int> asteroidCollision(vector<int>& asteroids) {
    vector<int>st;
    for(auto ast : asteroids){
        if (ast > 0){
            st.push_back(ast);
        }
        else{
            while (!st.empty() && st.back() > 0 && st.back() < abs(ast)){
                st.pop_back();
            }
            if (st.empty() || st.back() < 0){
                st.push_back(ast);
            }
            else if (st.back() == abs(ast)){
                st.pop_back();
            }
        }
    }
    return st;
}
*/

vector<int> asteroidCollision(vector<int> &asteroids)
{

    stack<int> st;
    bool destroy = false;
    for (auto ast : asteroids)
    {
        if (ast > 0)
        {
            st.push(ast);
        }
        else
        {
            if (st.empty() || st.top() < 0)
                st.push(ast);
            else
            {
                while (!st.empty() && st.top() > 0)
                {
                    if (abs(ast) == st.top())
                    {
                        destroy = true;
                        st.pop();
                        break;
                    }
                    else if (abs(ast) > st.top())
                        st.pop();
                    else
                    {
                        destroy = true;
                        break;
                    }
                }
                if (!destroy)
                    st.push(ast);
            }
        }
    }
    vector<int> ans(st.size());
    for (int i = st.size() - 1; i >= 0; i--)
    {
        ans[i] = st.top();
        st.pop();
    }
    return ans;
}

int main()
{
    vector<int> asteroids = {5, 10, -5};
    vector<int> ans = asteroidCollision(asteroids);
    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << " ";
    }
    return 0;
}