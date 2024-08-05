// Largest Subarray with zero sum

#include<iostream>
#include<vector>
#include<unordered_map>

using namespace std;

int maxLen(vector<int> &v, int n){
    unordered_map<int, int> map;
    int csum = 0;
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        csum += v[i];
        if (csum == 0)
        {
            ans = max(ans, i+1);
        }
        else if (map.find(csum) == map.end())
        {
            map[csum] = i;
        }
        else{
            ans = max(ans, i - map[csum]);
        }
    }
return ans;
}

int maxLenOfZeroOne(vector<int> &v, int n){
    unordered_map<int, int> map;
    int csum = 0;
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        int val = v[i] == 0 ? -1 : 1; 
        csum += val;
        if (csum == 0)
        {
            ans = max(ans, i+1);
        }
        else if (map.find(csum) == map.end())
        {
            map[csum] = i;
        }
        else{
            ans = max(ans, i - map[csum]);
        }
    }
return ans;
}

int main(){
    vector<int> v = {15, -2, 2, -8, 1, 7, 10, 23};
    int n = v.size();
    cout<<"The length of Largest subarray with sum 0 will be : "<<maxLen(v, n)<<endl;

    // Largest subarray of having  equal number of zeros and one.
    vector<int> v2 = {0, 1, 0, 1};
    int n2 = v2.size();
    cout<<"The length of Largest subarray with equal number of zeros and one : "<<maxLenOfZeroOne(v2, n2)<<endl;

return 0;
}