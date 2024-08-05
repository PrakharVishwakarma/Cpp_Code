// Painting Fence Algorithm(GFG).
/*
Input : n = 2 k = 4
Output : 16
Explanation: We have 4 colors and 2 posts.
Ways when both posts have same color : 4
Ways when both posts have diff color :4(choices for 1st post) * 3(choices for 2nd post) = 12
*/

#include<iostream>
using namespace std;

int paintFence(int n , int k){
  if(n==1) return k;
  if(n==2) return k + k*(k-1);
  return ((k-1)*(paintFence(n-1,k)+paintFence(n-2,k)));
}

int main(){
  int numOffence = 3;
  int numOfColor = 3;
  cout<<paintFence(numOffence,numOfColor);
}
