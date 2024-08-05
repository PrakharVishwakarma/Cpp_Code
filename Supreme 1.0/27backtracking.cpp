// Maximum Subarray:
#include <iostream>
#include <vector>
#include <limits.h>

using namespace std;

int maxSumArrayHelper(vector<int> v, int s, int e)
{
    if (s >= e)
        return v[s];

    int maxLeftBorderSum = INT_MIN;
    int maxRightBorderSum = INT_MIN;
    int mid = s + (e - s) / 2;

    int maxLeftSum = maxSumArrayHelper(v, s, mid);
    int maxRightSum = maxSumArrayHelper(v, mid + 1, e);

    // Max cross Border Sum
    int leftborderSum = 0;
    int rightBorderSum = 0;
    for (int i = mid; i >= s; i--)
    {
        leftborderSum += v[i];
        if (leftborderSum > maxLeftBorderSum)
            maxLeftBorderSum = leftborderSum;
    }
    for (int i = mid + 1; i <= e; i++)
    {
        rightBorderSum += v[i];
        if (rightBorderSum > maxRightBorderSum)
            maxRightBorderSum = rightBorderSum;
    }

    int crossBorderSum = maxLeftBorderSum + maxRightBorderSum;
    return max(crossBorderSum, max(maxLeftBorderSum, maxRightBorderSum));
}

int main()
{

    vector<int> v = {5, 4, -1, 7, 8};
    cout << maxSumArrayHelper(v, 0, v.size() - 1);

    return 0;
}

/* Search for kedan's Algorithms to get time complexity O(n) for this problem. */