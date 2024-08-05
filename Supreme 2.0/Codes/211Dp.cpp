// Leetcode : 1130. Minimum Cost Tree From Leaf Values

#include <iostream>
#include <vector>
#include <limits.h>
#include <map>

using namespace std;

int solveUsingRecursion(vector<int> &arr, map<pair<int, int>, int> &maxi, int s, int e)
{
    if (s > e)
        return 0;
    if (s == e)
        return 0;

    int ans = INT_MAX;
    for (int i = s; i < e; i++)
    {
        ans = min(ans, ((maxi[{s, i}] * maxi[{i + 1, e}]) + solveUsingRecursion(arr, maxi, s, i) + solveUsingRecursion(arr, maxi, i + 1, e)));
    }
    return ans;
}

int solveUsingMemoisation(vector<int> &arr, map<pair<int, int>, int> &maxi, int s, int e, vector<vector<int>> &dp)
{
    if (s > e)
        return 0;
    if (s == e)
        return 0;

    if (dp[s][e] != -1)
        return dp[s][e];

    int ans = INT_MAX;
    for (int i = s; i < e; i++)
    {
        ans = min(ans, ((maxi[{s, i}] * maxi[{i + 1, e}]) + solveUsingMemoisation(arr, maxi, s, i, dp) + solveUsingMemoisation(arr, maxi, i + 1, e, dp)));
    }
    dp[s][e] = ans;

    return dp[s][e];
}

int solveUsingTabulation(vector<int> &arr, map<pair<int, int>, int> &maxi)
{
    int n = arr.size();
    vector<vector<int>> dp(n + 2, vector<int>(n + 1, 0));

    for (int start_index = n; start_index >= 0; start_index--)
    {
        for (int end_index = 0; end_index <= n - 1; end_index++)
        {
            if (start_index >= end_index)
            {
                continue;
            }
            int ans = INT_MAX;
            for (int i = start_index; i < end_index; i++)
            {
                ans = min(ans, ((maxi[{start_index, i}] * maxi[{i + 1, end_index}]) + dp[start_index][i] + dp[i + 1][end_index]));
            }
            dp[start_index][end_index] = ans;
        }
    }
    return dp[0][n - 1];
}

void mctFromLeafValues(vector<int> &arr)
{
    // pre computation
    map<pair<int, int>, int> maxi;
    for (int i = 0; i < arr.size(); i++)
    {
        maxi[{i, i}] = arr[i];
        for (int j = i + 1; j < arr.size(); j++)
        {
            maxi[{i, j}] = max(arr[j], maxi[{i, j - 1}]);
        }
    }
    int n = arr.size();
    int start = 0;
    int end = n - 1;
    int ans = solveUsingRecursion(arr, maxi, start, end);
    cout << "Among all possible binary trees considered, the smallest possible sum of the values of each non-leaf node is : " << ans << endl;

    vector<vector<int>> dp(n + 1, vector<int>(n + 1, -1));
    cout << "Among all possible binary trees considered, the smallest possible sum of the values of each non-leaf node is : " << solveUsingMemoisation(arr, maxi, start, end, dp) << endl;

    cout << "Among all possible binary trees considered, the smallest possible sum of the values of each non-leaf node is : " << solveUsingTabulation(arr, maxi) << endl;
}

int main()
{
    vector<int> arr = {6, 2, 4};
    mctFromLeafValues(arr);

    return 0;
}