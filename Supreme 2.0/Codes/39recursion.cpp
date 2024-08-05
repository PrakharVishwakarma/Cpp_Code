// Leetcode : 70. Climbing Stairs
/*
Example 1:

Input: n = 2
Output: 2
Explanation: There are two ways to climb to the top.
1. 1 step + 1 step.
2. 2 steps.

*/
#include <iostream>
using namespace std;

    int climbStairs(int n){
        if (n<=1) return 1;
        return climbStairs(n-1) + climbStairs(n-2);
    }

int main(){

    int n;
    cout<<"Enter the nth stair : ";
    cin>>n;
    cout<<climbStairs(n)<<" distinct ways you can climb to the top.";
    return 0;
}


/*
    If the base case is not writtene in the recursion function then staack overflowed, The default stack size for x64 machines is 1 MB.

*/

 