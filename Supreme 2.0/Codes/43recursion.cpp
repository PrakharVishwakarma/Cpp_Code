/*
Leetcode : 322. Coin Change : Return the fewest number of coins that you need to make up that amount.

Input: coins = [1,2,5], amount = 11
Output: 3
Explanation: 11 = 5 + 5 + 1
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <limits.h>
using namespace std;

int coinChange(vector<int> &coins, int amount)
{
    if (amount == 0)
    {
        return 0;
    }
    if (amount < 0)
    {
        return INT_MAX;
    }

    int mini = INT_MAX;

    for (int i = 0; i < coins.size(); i++)
    {
        if (coins[i] <= amount)
        {
            int recAns = coinChange(coins, amount - coins[i]);
            if (recAns != INT_MAX)
            {
                int ans = 1 + recAns;
                mini = min(mini, ans);
            }
        }
    }

    return mini;
}

int main()
{
    int amount = 25;
    vector<int> coins = {7, 8, 3};
    int finalAns = coinChange(coins, amount);
    if (finalAns == INT_MAX)
    {
        cout << "Combination are not possible.";
    }
    else
    {
        cout << "Number of minimum coins that needed to make up amount " << amount << " are " << finalAns;
    }
    return 0;
}