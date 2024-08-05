/* Maximize The Cut Segments :
N = 4
x = 2, y = 1, z = 1
Output: 4
Explanation:Total length is 4, and the cut
lengths are 2, 1 and 1.  We can make
maximum 4 segments each of length 1.
*/

#include <iostream>
#include <limits.h>
#include <algorithm>

using namespace std;

int maximizeTheCuts(int n, int x, int y, int z){
    if(n == 0)
        return 0;
    
    if (n < 0)
        return INT_MIN;     //Jab less than 0 vali condition aaye toh return maxOf me consider hi na ho 

    int countCut1 = 1+ maximizeTheCuts(n - x, x, y, z);
    int countCut2 = 1+ maximizeTheCuts(n - y, x, y, z);
    int countCut3 = 1+ maximizeTheCuts(n - z, x, y, z);

    return max(countCut1, countCut2, countCut3);
}

int main()
{
    int N = 4, x = 2, y = 1, z = 1;
    cout << maximizeTheCuts(N, x, y, z);
    return 0;
}