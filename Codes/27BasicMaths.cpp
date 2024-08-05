/* Findig Prime :
#include<iostream>
using namespace std;

bool isPrime(int n) {

    if(n<=1)
    return false;

    for(int i=2; i<n; i++)
    {
        if(n%i==0)
        {
            return false;
        }
    }
    return true;
}

int main() {

    int n;
    cin >> n;

    if(isPrime(n)) {
        cout << "It is a Prime Number" << endl;
    }
    else{
        cout << " It is not a Prime Number" << endl;
    }


    return 0;
}

// Leet code problem: function for finding count of prime numbers till n
/*
int countPrimes(int n){
    int count = 0;
    vector<bool> prime(n+1 , true);  // prime(n+1 , true) means make a vector of n+1 and intialize it with true .     

    prime[0]=prime[1]=false;
    for(int i = 2 ; i < n ; i++){
        if (prime[i]){
            for(int j * 2 ; j < n ; j++){
                prime[j] = 0;
            }
        }
    }
return count;
Complexity : log(log n).
}
*/

//Finding gcd :

#include<iostream>
using namespace std;

int gcd(int a, int b) {

    if(a==0)
    return b;

    if(b==0)
    return a;

    while(a != b) {

        if(a>b)
        {
            a = a-b;
            return a;
        }
        else{
            b = b-a;
            return b;
        }
    }
    return a;
}

int main() {
    
    int a,b;
    cout << "Enter the Values of a and b" << endl;
    cin >> a >> b;

    int ans = gcd(a,b);

    cout << " The GCD of " << a << " & " << b << " is: " << ans << endl;



    return 0;
}