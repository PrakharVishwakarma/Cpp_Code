// Beautiful arrangement : Leetcode 526 : (Check the code given again , Not giving the answer: )

#include<iostream>
#include<vector>

using namespace std;

void beutifulArrangement(vector<int> &v, int &n, int &ans, int currNum){

    if(currNum == n+1){
        for (int i = 1; i <= n; i++)
        {
            cout<<v[i]<<" ";
        }cout<<endl;
        ++ans;
        return;
    }

    for (int i = 1; i <= n; ++i)
    {
        if (v[i] == 0 && ((currNum % i == 0) || (i % currNum == 0)))
        {
            v[i] = currNum;

            beutifulArrangement(v, n, ans, currNum+1);

            v[i] = 0;            
        }
    }
    
}

int main()
{
    int n = 4;
    vector<int> v(n+1);
    int ans = 0;

    beutifulArrangement(v, n, ans, 1);
    cout<<" the number of the beautiful arrangements that can be constructed : "<<ans<<endl;
    
}

