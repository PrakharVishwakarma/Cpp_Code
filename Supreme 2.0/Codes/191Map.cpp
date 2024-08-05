// Sum eqals to sum:

#include<iostream>
#include<unordered_map>
using namespace std;

bool (findSumPair(long long arr[], long long n)){
    unordered_map<int, bool> map;
    for (int i = 0; i < n; i++)
    {
        for (int j = i+1; j < n; j++)
        {
            int sum = arr[i] + arr[j];
            if(map.find(sum) != map.end()){
                return true;
            }
            else{
                map[sum] = true;
            }
        }
        
    }
    return false;
}

int main(){
    long long arr[] = {3, 4, 7, 1, 2, 9, 8};
    long long n = sizeof(arr)/ sizeof(int);
    if (findSumPair(arr, n))
    {
        cout<<"Pair sum found."<<endl;
    }
    else{
        cout<<"Pair Sum not Found."<<endl;
    }

return 0;
}