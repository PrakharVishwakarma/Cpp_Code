/* Leetcode 75
Given an array nums with n objects colored red, white, or blue,
sort them in-place so that objects of the same color are adjacent,
with the colors in the order red, white, and blue.

We will use the integers 0, 1, and 2 to represent the color red, white, and blue, respectively.
*/

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

void sortColors(vector<int> &nums)
{

    int left = 0;
    int index = 0;
    int right = nums.size() - 1;
    while (index <= right)
    {
        if (nums[index] == 0)
        {
            swap(nums[index], nums[left]);
            index++;
            left++;
        }
        else if (nums[index] == 2)
        {
            swap(nums[index], nums[right]);
            // index++; No need, because jab right se swap hoga to loop index se shuru hona chaiye na ki index+1 se
            right--;
        }
        else
        {
            index++;
        }
    }
}

int main()
{
    vector<int> nums = {2, 0, 2, 1, 1, 0};

    sortColors(nums);
    for (int i = 0; i < nums.size(); i++)
    {
        cout << nums[i] << " ";
    }
    cout << endl;
    return 0;
}