#include<iostream>
#include<unordered_map>

using namespace std;

string isSubset(int a1[], int n, int a2[], int m){
    unordered_map<int, int> map;
    for (int i = 0; i < n; i++)
    {
        map[a1[i]]++;
    }
    for (int i = 0; i < m; i++)
    {
        if (map.find(a2[i]) == map.end()){
            return "No";
            break;
            }
        else{
            if (map[a2[i]] <= 0)
            {
                return "No";
                break;
            }
            else{
                map[a2[i]]--;
            }
            
        }
    }
    return "Yes";
}

int main(){
    int a1[] = {11, 1, 13, 21, 3, 7};
    int n = sizeof(a1)/sizeof(int);
    int a2[] = {11, 3, 7, 1};
    int m = sizeof(a2)/sizeof(int);

    cout<<"Array a1 is the subset of a2 : "<<isSubset(a1, n, a2, m);
return 0;
}