// Leetcode : 983 :

#include <iostream>
#include <vector>
using namespace std;

int solveUsingRecursion(vector<int> &days, vector<int> &costs, int i)
{
    if (i >= days.size())
        return 0;

    int costOfOneDayPass = costs[0] + solveUsingRecursion(days, costs, i + 1);

    int passEnd = days[i] + 7 - 1;
    int j = i;
    while (j < days.size() && days[j] <= passEnd)
    {
        j++;
    }
    int costOfSevenDayPass = costs[1] + solveUsingRecursion(days, costs, j);

    passEnd = days[i] + 30 - 1;
    j = i;
    while (j < days.size() && days[j] <= passEnd)
    {
        j++;
    }
    int costOfThirtyDayPass = costs[2] + solveUsingRecursion(days, costs, j);

    return min(costOfOneDayPass, min(costOfSevenDayPass, costOfThirtyDayPass));
}

int solveUsingMemoisation(vector<int> &days, vector<int> &costs, int i, vector<int> &dp)
{
    if (i >= days.size())
        return 0;

    if (dp[i] != -1)
        return dp[i];

    int costOfOneDayPass = costs[0] + solveUsingMemoisation(days, costs, i + 1, dp);

    int passEnd = days[i] + 7 - 1;
    int j = i;
    while (j < days.size() && days[j] <= passEnd)
    {
        j++;
    }
    int costOfSevenDayPass = costs[1] + solveUsingMemoisation(days, costs, j, dp);

    passEnd = days[i] + 30 - 1;
    j = i;
    while (j < days.size() && days[j] <= passEnd)
    {
        j++;
    }
    int costOfThirtyDayPass = costs[2] + solveUsingMemoisation(days, costs, j, dp);

    dp[i] = min(costOfOneDayPass, min(costOfSevenDayPass, costOfThirtyDayPass));
    return dp[i];
}

int solveUsingTabulation(vector<int> &days, vector<int> &costs, int i)
{
    vector<int> dp(days.size()+1, -1); 

    dp[days.size()] = 0;

    for (int i = days.size()-1; i >= 0; i--)
    {
        int costOfOneDayPass = costs[0] + dp[i + 1];

        int passEnd = days[i] + 7 - 1;
        int j = i;
        while (j < days.size() && days[j] <= passEnd)
        {
            j++;
        }
        int costOfSevenDayPass = costs[1] + dp[j];

        passEnd = days[i] + 30 - 1;
        j = i;
        while (j < days.size() && days[j] <= passEnd)
        {
            j++;
        } 
        int costOfThirtyDayPass = costs[2] + dp[j];

        dp[i] = min(costOfOneDayPass, min(costOfSevenDayPass, costOfThirtyDayPass));
    }
return dp[0];  
}

void mincostTickets(vector<int> &days, vector<int> &costs)
{

    cout << "minimum number of dollars you needed to travel every day in the given list of days is : " << solveUsingRecursion(days, costs, 0) << endl;

    vector<int> dp(days.size(), -1);
    cout << "minimum number of dollars you needed to travel every day in the given list of days is : " << solveUsingMemoisation(days, costs, 0, dp) << endl;

    cout << "minimum number of dollars you needed to travel every day in the given list of days is : " << solveUsingTabulation(days, costs, 0) << endl;
}

int main()
{
    vector<int> days = {1, 4, 6, 7, 8, 20}, costs = {2, 7, 15};
    mincostTickets(days, costs);

    return 0;
}
