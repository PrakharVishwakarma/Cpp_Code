// Leetcode 658 : Find k closest element.

#include <iostream>
#include <vector>

using namespace std;

/*
void twoPtrMethod(vector<int> &v, int x, int k)
{
    int l = 0;
    int h = v.size() - 1;
    while ((h - l) >= k)
    {
        if ((x - v[l]) > (v[h] - x))
        {
            l++;
        }
        else
        {
            h--;
        }
    }

    for (int i = l; i <= h; i++)
    {
        cout<<v[i]<<" ";
    }
}
*/

int lowerBound(vector<int> &v, int x)
{
    int s = 0;
    int e = v.size() - 1;
    int ans = e;

    while (s <= e)
    {
        int mid = s + (e - s) / 2;
        if (v[mid] >= x)
        {
            ans = mid;
            e = mid - 1;
        }
        else if (x > v[mid])
        {
            s = mid + 1;
        }
        else
        {
            e = mid - 1;
        }

        return ans;
    }
}

void bsMethod(vector<int> &v, int x, int k)
{

    int h = lowerBound(v, x);
    int l = h - 1;

    while (k--)
    {

        if (l < 0)
        {
            h++;
        }
        else if (h > v.size())
        {
            l--;
        }

        else if (x - v[l] > v[h] - x)
        {
            h++;
        }
        else
        {
            l--;
        }
    }
    for (int i = l+1 ; i <= h-1; i++)
    {
        cout << v[i] << " ";
    }
}

int main()
{
    vector<int> v = {12, 16, 22, 30, 35, 39, 42, 45, 48, 50, 53, 55, 56};
    // int x = 33;
    int x = 32;
    // int x = 31;
    int k = 4;
    // vector<int> v = {1, 2, 3, 4, 5};
    // twoPtrMethod(v, x, k);
    bsMethod(v, x, k);

    return 0;
}
