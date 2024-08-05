// LeetCode Permutation 2

/* Code for simple permutation is : */
/*
#include <iostream>
#include <vector>
using namespace std;

void simplePermutation(vector<int> &v, int s, vector<vector<int>> ans)
{

    // Base case :
    if (s >= v.size())
    {

        ans.push_back(v);
        for (int i = 0; i < ans.size(); i++)
        {
            for (int j = 0; j < ans[i].size(); j++)
            {
                cout << ans[i][j] << " ";
            }
            cout << endl;
        }

        return;
    }

    for (int i = s; i < v.size(); i++)
    {
        swap(v[i], v[s]);

        simplePermutation(v, s + 1, ans);
        // backtracking
        swap(v[i], v[s]);
    }
}

int main()
{
    vector<int> v = {1, 2, 3};
    int start = 0;
    vector<vector<int>> ans;

    simplePermutation(v, start, ans);
}
*/

#include <iostream>
#include <vector>
#include <set>
using namespace std;

void simplePermutation(vector<int> &v, int s, vector<vector<int>> ans , set<vector<int>> st)
{

    // Base case :
    if (s >= v.size())
    {

        ans.push_back(v);
        /*
        for (int i = 0; i < ans.size(); i++)
        {
            for (int j = 0; j < ans[i].size(); j++)
            {
                cout << ans[i][j] << " ";
            }
            cout << endl;
        }
        */

        // To remove duplicates :
        
        for (auto e : ans)
        {
            st.insert(e);
        }
        ans.clear();
        for (auto e : st)
        {
            ans.push_back(e);
        }
        
        for (int i = 0; i < ans.size(); i++)
        {
            for (int j = 0; j < ans[i].size(); j++)
            {
                cout << ans[i][j] << " ";
            }
            cout << endl;
        }
        return;
    }

    for (int i = s; i < v.size(); i++)
    {
        swap(v[i], v[s]);

        simplePermutation(v, s + 1, ans , st);
        // backtracking
        swap(v[i], v[s]);
    }
}

int main()
{
    vector<int> v = {1, 1, 3};
    int start = 0;
    vector<vector<int>> ans;
    set<vector<int>> st;

    simplePermutation(v, start, ans , st);

return 0;
}