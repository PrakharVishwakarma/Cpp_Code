// Problem LeetCode532 : K diff pair in an array.
/*
#include<iostream>
#include<algorithm>
#include <array>
#include<set>

using namespace std;


int main(){

    array<int, 5> arr = {1 , 3 , 1 , 5 , 4};
    sort(arr.begin(), arr.end());

    int i = 0;
    int j = 1;
    int countPair = 0;
    int targetDiff = 0;


//  To prevent redundancy use set :

    // set<pair<int, int>> ansPairSet;


    while (j< (sizeof(arr)/sizeof(int)))
    {
        if (arr[j] - arr[i] == targetDiff)
        {

            // ansPairSet.insert({arr[i] , arr[j]});

            cout<<arr[i]<<" "<<arr[j]<<endl;
            countPair++;
            i++;
            j++;
        }
        else if (arr[j] - arr[i] > targetDiff)
        {
            i++;
        }
        else{
            j++;
        }
        if (i == j) j++;
    }

    cout<<"Numbers of pairs are "<<countPair;

    return 0;
}
*/

// this question Using Binary Search :

#include <iostream>
#include <algorithm>
#include <vector>
#include <set>

using namespace std;

int BiSearch(vector<int> &v, int target, int s, int e)
{

    int mid = s + (e - s) / 2;

    while (mid > s)
    {
        if (v[mid] == target)
        {
            return mid;
        }
        else if (v[mid] < target)
        {
            e = mid - 1;
        }
        else
        {
            s = mid + 1;
        }
        return -1;
    }
}

int main()
{

    vector<int> v = {1, 3, 1, 5, 4};
    sort(v.begin(), v.end());
    int targetDiff = 2;
    set<pair<int, int>> ansPairSet;

    for (int i = 0; i < v.size(); i++)
    {
        if ((( v[i] + targetDiff) <= v[v.size()-1]) && (BiSearch(v, v[i] + targetDiff, i + 1, v.size() - 1) != -1))
        {
            ansPairSet.insert({v[i], v[i] + targetDiff});
        }
    }
    for (const auto &pair : ansPairSet)
    {
        cout << "(" << pair.first << ", " << pair.second << ")" << endl;
    }

    return 0;
}