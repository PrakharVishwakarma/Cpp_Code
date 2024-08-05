// Leetcode 354. Russian Doll Envelopes

#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;


static bool cmp(vector<int> &a,vector<int> &b){
    if(a[0] == b[0]) return a[1] > b[1];
    else return a[0] < b[0];
}
int maxEnvelopes(vector<vector<int>>& envelopes) {
    sort(envelopes.begin(), envelopes.end(), cmp);

    vector<int> ans;

    //initial state
    ans.push_back(envelopes[0][1]);
    
    for(int i=1; i<envelopes.size(); i++) {
        if(envelopes[i][1] > ans.back()) {
            ans.push_back(envelopes[i][1]);
        }
        else {
            //just bada number exist krta hai
            int index = lower_bound(ans.begin(), ans.end(), envelopes[i][1]) - ans.begin();
            // the function lower_bound returns an iterator pointing to the next smallest number just greater than or equal to that number.
            //replace 
                ans[index] = envelopes[i][1];
        }
    }
    cout<<endl;
    for (int i = 0; i < ans.size(); i++)
    {
        cout<<ans[i]<<" ";
    }cout<<endl;
    
    return ans.size();
}

int main(){
    vector<vector<int>> envelopes = {{5,4},{6,4},{6,7},{2,3}};
    cout<<"maximum number of envelopes you can Russian doll : "<<maxEnvelopes(envelopes);
return 0;
}
