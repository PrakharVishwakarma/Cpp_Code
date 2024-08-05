// Code for the conversion of decimal to binary .

#include <iostream>
#include <math.h>
using namespace std;

int main()
{
/*
    int n;
    cout << "Enter n ";
    cin >> n;

    int answer = 0;
    int i = 0;
    while (n != 0)
    {
        int bit = n & 1; // Let XXXX is the binary conversaion of n so  to get the LSB we do n & i.
        answer = (bit * pow(10, i)) + answer;
        n = n >> 1; // Right shiftig n.
        i++;
    }
    cout << "Binary Conversion of " << n << " is " << answer;
*/
    // Code for conversion of binary to decimal.

/*
        int n;
        cout << "Enter n ";
        cin >> n;
        int answer = 0;
        int i = 0;
        while (n != 0)
        {
            int digit = n % 10; // Let XX is the decimal conversion of n , so to grt lab of n we do n % 10. 
            if (digit = 1)
            {
                answer = answer + pow(2, i);
            }
            n = n / 10;
            i++;
        }
        cout << "Decimal converaion of " << n << " is " << answer;
 
*/

    int n;
        cout << "Enter n ";
        cin >> n;
        int m = n;
        int mask = 0;
        
        if(n == 0){
            return 1;
        }
        else{
        while( m!=0) {
            mask = (mask << 1) | 1;
            m = m >> 1;
        }
        
        int ans = (~n) & mask;
    cout << ans;
    }

}