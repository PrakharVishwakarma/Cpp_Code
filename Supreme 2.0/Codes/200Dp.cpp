#include<iostream>
#include<vector>
using namespace std;

// Top Down:
int solveUsingMemoisation(int n, vector<int> &dp){
    if (n==0 || n==1)return n;
    
    if (dp[n] != -1)return dp[n];

    dp[n] = solveUsingMemoisation(n-1, dp) + solveUsingMemoisation(n-2, dp);

return dp[n];
}

int fib(int &n){
    vector<int> dp(n+1, -1);
    int ans = solveUsingMemoisation(n , dp);
    cout<<endl<<"Printing dp array : ";
    for (int i = 0; i < dp.size(); i++){
        cout<<dp[i]<<" ";
    }
    
return ans;
}

// Bottom Up:
solveUsingTabulation(int &n){
    vector<int> dP(n+1, -1);
    dP[0] = 0;
    if(n==0) return n;
    dP[1] = 1;

    for (int i = 2; i <=n ; i++)
    {
        dP[i] = dP[i-1] + dP[i-2];
    }
return dP[n];
}
 
// Space Optimization
solveUsingTabulationOptimization(int &n){
    if(n==0 || n == 1) return n;
    int prev = 0;
    int curr = 1;
    int ans;
    for (int i = 2; i <=n ; i++)
    {
        ans = prev + curr;
        prev = curr;
        curr = ans;
    }
return ans;
}

int main(){
    int num;
    cout<<"Enter the number to get fib: ";
    cin>>num;
    cout<<"Fibonacci of using top down memoisation approach "<<num<<" is : "<<fib(num)<<endl;
    cout<<"Fibonacci of using bottom up tabulation approach"<<num<<" is : "<<solveUsingTabulation(num)<<endl;
    cout<<"Fibonacci of using bottom up tabulation approach"<<num<<" is : "<<solveUsingTabulationOptimization(num)<<endl;

return 0;
}

// We can find the fib till num = 47, out of 47 is out of bound.