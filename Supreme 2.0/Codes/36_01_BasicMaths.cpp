// Seive of Iratosthenes to calculate the number is prime or not:

#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int fastExp(int a, int b)
{
    int ans = 1;
    while (b > 0)
    {
        if (b & 1)
        {
            ans = ans * a;
        }
        a = a * a;
        b >>= 1;
    }
    return ans;
}

/*  gcd(a,b) = gcd(abs(a-b), b) or gcd(a%b, b)*/
int gcd(int a, int b)
{
    if (a == 0)
        return b;
    if (b == 0)
        return a;
    while (a > 0 && b > 0)
    {
        if (a >= b)
            a = a - b;
        else
            b = b - a;
    }
    return a == 0 ? b : a;
}

int countPrime(int &n)
{
    if (n == 0 || n == 1)
        return 0;
    vector<bool> primeArr(n, true);
    primeArr[0] = primeArr[1] = false;
    int answer = 0;
    for (int i = 2; i < n; i++)
    {
        if (primeArr[i])
        {
            answer++;
            int j = i * 2;
            while (j < n)
            {
                primeArr[j] = false;
                j += i;
            }
        }
    }
    return answer;
}

int main()
{
    int n = 295245;
    cout << countPrime(n) << endl;

    int a = 13;
    int b = 65;
    int gcdInt = gcd(a, b);
    cout << "gcd of " << a << " and " << b << " is : " << gcdInt << endl;
    int lcmInt = (a * b) / gcdInt;
    cout << "lcm of " << a << " and " << b << " is : " << lcmInt << endl;
    
    int p = 10;
    int q = 4;
    cout << fastExp(p, q);
    return 0;
}

/*
Max size of int , double (in a function) , char is : 10^6 and bool array : 10^7.          [matlab function vali stack ka size : 8MB]
Global array : int , bool , char : 10^7 , char is : 10^8.

*/