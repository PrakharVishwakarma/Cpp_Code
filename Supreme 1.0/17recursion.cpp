//Leetcode 1155 : Number of dice roll with targer sum , where n is the number of dice , k is the number of faces and t is the target.
/*
Example 1:

Input: n = 1, k = 6, target = 3
Output: 1
Explanation: You throw one die with 6 faces.
There is only one way to get a sum of 3.


*/


#include<iostream>
using namespace std;

int numRollsToTarget(int n, int k, int target) {
    if(n == 0 &&target == 0) return 1;
    if(n != 0 && target == 0) return 0;
    if(n == 0 && target != 0) return 0;
    if(target < 0) return 0;
    int numOfWays = 0;
    for (int i = 1; i <= k; i++)
    {
        numOfWays = numOfWays + numRollsToTarget(n - 1,k,target - i);
    }
    return numOfWays;
}

int main(){
    int n = 2;
    int k = 6;
    int target = 7;    
    cout<<"Number of dice possible roll with targer sum "<<target<<" are : "<<numRollsToTarget(n,k,target);

    return 0;
}