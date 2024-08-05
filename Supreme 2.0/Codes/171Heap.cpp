#include<iostream>
#include<cmath>
#include<queue>

using namespace std;

// Leetcode 1962 : Remove Stones to minimize the total
int minStoneSum(vector<int>& piles, int k) {
    priority_queue<int> pq;
    for (int i = 0; i < piles.size(); i++)
    {
        pq.push(piles[i]);
    }
    while (k--)
    {
        int topElement = pq.top();pq.pop();
        topElement = topElement - floor(topElement/2);
        pq.push(topElement);
    }
    int sum = 0;
    while (!pq.empty())
    {
        sum += pq.top();pq.pop();
    } 
return sum ;
}

int main(){
    vector<int> piles = {5,4,9}; 
    int k = 2;
    cout<<"Minimum total after removing stones is : "<<minStoneSum(piles, k);

return 0;
}