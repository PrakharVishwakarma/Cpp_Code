#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
using namespace std;

void countPrime(int &n, vector<bool> &primeArr)
{
    if (n == 0 || n == 1)return;
    
    primeArr[0] = primeArr[1] = false;
    int answer = 0;
    for (int i = 2; i < sqrt(n); i++)
    {
        if (primeArr[i]){
            int j = i * i;
            while (j < n)
            {
                primeArr[j] = false;
                j += i;
            }
        }
    } 
}

void segmentedSeive(vector<bool> &segmentedPrimeArr, int l, int r){
    vector<int> basePrime;
    for (int i = 0; i < segmentedPrimeArr.size(); i++)if(segmentedPrimeArr[i]) basePrime.push_back(i);
    for(auto e : basePrime)cout<<e<<" ";cout<<endl;

    vector<bool> segSeive((r - l)+1, true);
    if(l == 0 || r == 0) basePrime[l] = false;

    for(auto prime : basePrime){
        int firstMultiple = (l/prime)*prime;
        if(firstMultiple<l) firstMultiple+=prime;
        int j = max(firstMultiple, prime*prime);
        while (j<=r)
        {
            segSeive[j-l] = false;
            j+=prime;
        }
    }
    for (int i = 0; i < segSeive.size(); i++)
    {
        if(segSeive[i])cout<<i+l<<" ";
    }cout<<endl;
    
}

int main(){
         
    int n = 17;
    vector<bool> primeArr(n, true);
    countPrime(n, primeArr);
    int count = 0;
    for (int i = 0; i < n; i++)
    {
        if(primeArr[i]){
            ++count;
            cout<<i<<" ";
        } 
    } 
    cout<<endl<<"Numbers of prime numbers in range of 0 to "<<n<<" are "<<count<<endl;

    int l = 1545;
    int r = 2227;
    int neededBoud = sqrt(r);
    vector<bool> segmentedPrimeArr(neededBoud, true);
    countPrime(neededBoud, segmentedPrimeArr);
    cout<<endl<<"Numbers of prime numbers in range of" <<l<<" to "<<r<<" are "<<count<<endl;
    segmentedSeive(segmentedPrimeArr, l, r);
    // cout<<"Number of prime number between "<<l<<" and "<< r<<" are : "<<segmentedSeive(l, m)<<endl;


    return 0;
}

/*

Max Size of int, double, char array is : 10^6.
bool 10^7;

If Global Array: 
Max Size of int, double, char array is : 10^7.
bool 10^8;

on 64-bit operating systems, size for a single thread can be as large as 8MB or more
*/