// leetcode :121 : Best Time to Buy and Sell Stock.


#include<iostream>
#include<vector>
#include<limits.h>

using namespace std;

void maxiProfit(vector<int>& prices , int i , int &maxProfit, int &minPrice) {

    if (i>=prices.size())return;
    
    if(prices[i]<minPrice) minPrice = prices[i];

    int todayProfit = (prices[i]-minPrice);
    if(todayProfit>maxProfit) maxProfit = todayProfit;

    maxiProfit(prices , i+1 , maxProfit, minPrice);
}

int main(){
    vector<int>prices = {7,1,5,3,6,4};

    int minPrice = INT_MAX; 
    int maxProfit = INT_MIN; 
    maxiProfit(prices , 0 , maxProfit, minPrice);
    cout<<maxProfit;
    return 0;
}