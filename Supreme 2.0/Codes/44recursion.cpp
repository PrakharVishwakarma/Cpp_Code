// Leetcode 198 : House Robber : TLE marega kyunki DP ka sawal hai.
/*
Input: nums = [1,2,3,1]
Output: 4
Explanation: Rob house 1 (money = 1) and then rob house 3 (money = 3).
Total amount you can rob = 1 + 3 = 4.
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int houseRobber(vector<int> &lootInHouses, int index){
    if (index >= lootInHouses.size())
        return 0;
    
    int isGharKichoriKaro = lootInHouses[index] + houseRobber(lootInHouses, index + 2);
    int isGharKichoriNiKaro = 0 + houseRobber(lootInHouses, index + 1);
return max(isGharKichoriKaro, isGharKichoriNiKaro);
}

int main()
{
    vector<int> lootInHouses = {1, 2, 3, 1};
    cout << houseRobber(lootInHouses, 0);

    return 0;
}