// Custom Comparator : Apne accordinf increasing order or decreasing order me sort kar sakte hain.

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool myComp(int &a, int &b)
{ // By default custom comparator having bool type.
    return a < b;
    return a < b;
}

bool mycompforIndex1(vector<int> &a, vector<int> &b) {
  return a[1] > b[1]; // dsc order
  // return a[1] < b[1]; // asc order
}
void print2dVector(vector<vector<int>> v, int n)
{
    for (int i = 0; i < n; i++)
    {
        vector<int> &temp = v[i];
        int a = temp[0];
        int b = temp[1];
        cout<< a << " " << b<<endl;
    }
}

int main()
{

    /*
    vector<int>v = {12 , 5 , 20 , 32 , 45 , 50};
    for (int i = 0; i < v.size(); i++)
    {
        cout<<v[i]<<" ";
    }
    cout<<endl<<"Sorting : ";
    sort(v.begin() , v.end() , myComp);
    for (int i = 0; i < v.size(); i++)
    {
        cout<<v[i]<<" ";
    }
*/

    // Sorting in 2d vector :
    vector<vector<int>> v;
    int n;
    cout << "Enter the size of a row : ";
    cin >> n;
    cout << endl;
    for (int i = 0; i < n; i++)
    {
        int a;
        int b;
        cout << "Enter the row "<<i<<": ";
        cin >> a >> b;
        vector<int> temp;
        temp.push_back(a);
        temp.push_back(b);

        v.push_back(temp);
    }
    cout<<endl;
    print2dVector(v, n);
    cout << "Sorted by 1st index" << endl;
    sort(v.begin(), v.end(),  mycompforIndex1);
    print2dVector(v , n);
    return 0;
}


