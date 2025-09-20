// Leetcode 134 : Gas Station :

#include <iostream>
#include <vector>
using namespace std;

int canCompleteCircleI(vector<int> &gas, vector<int> &cost)
{
    int balance = 0;
    int deficit = 0;
    int start = 0;
    for (int i = 0; i < gas.size(); i++)
    {
        balance = balance + gas[i] - cost[i];
        if (balance < 0)
        {
            deficit += abs(balance);
            start = i + 1;
            balance = 0;
        }
    }
    if (balance - deficit >= 0)
    {
        return start;
    }
    else
    {
        return -1;
    }
}

int main()
{
    vector<int> gas = {1, 2, 3, 4, 5};
    vector<int> cost = {3, 4, 5, 1, 2};
    cout << canCompleteCircleI(gas, cost) << endl;

    return 0;
}