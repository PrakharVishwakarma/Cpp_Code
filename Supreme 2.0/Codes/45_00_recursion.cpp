#include <iostream>
#include <cstring>
using namespace std;

int findLastOcc(string &str, int &n, char &findLastOccOf, int i, int &ans)
{
    if (i >= n)
        return ans;

    if (str[i] == findLastOccOf)
        ans = i;

    findLastOcc(str, n, findLastOccOf, i + 1, ans);
}

void findLastOccRightToLeft(string &str, int i, char &findLastOccOf, int &ans)
{
    if (i < 0)
        return;

    if (str[i] == findLastOccOf)
    {
        ans = i;
        return;
    }

    findLastOccRightToLeft(str, --i, findLastOccOf, ans);
}
int main()
{
    string str = "abfsfdafdscfwsvd";
    char findLastOccOf = 'c';
    int ans1 = -1;
    int i = 0;
    int n = str.length();
    cout << "Last Occuranne of the character " << findLastOccOf << " in a string " << str << " is " << findLastOcc(str, n, findLastOccOf, i, ans1) << endl;

    int ans2 = -1;
    findLastOccRightToLeft(str, n, findLastOccOf, ans2);
    cout << "Last Occuranne of the character " << findLastOccOf << " in a string " << str << " is " << ans2 << endl;

    char chArr[] = "My name is Ayush";
    char* ch = strchr(str, 'a');
    cout << ch - chArr + 1;

    return 0;
}