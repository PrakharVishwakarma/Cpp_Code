#include<iostream>
#include<vector>
using namespace std;

int getUnique(int arr[], int n){
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        ans = ans ^ arr[i];
        // cout<<ans<<" ";
    }cout<<endl;
    return ans;
}

int main()
{
    int arr[] = {2, 10, 11, 10, 2, 13, 11};
    cout<<getUnique(arr, sizeof(arr)/sizeof(int));
    vector<int> v;
    cout<<endl<<v.size();

return 0;
}

