#include<iostream> 
using namespace std;

int factorial(int n) {
    
    //base case
    if(n==0)
        return 1;

    return n *factorial(n-1);
}
int power(int n) {

    //base case 
    if(n == 0)
        return 1;

    //recursive relation
    return 2 * power(n-1);    
}


int main() {

    int n;
    cout<<"Enter n ";
    cin >> n;

    int ans1 = factorial(n);
    int ans2 = power(n);

    cout <<"Factorial of "<<n<<" is "<< ans1 << endl;
    cout <<"2 to the power "<<n<<" is"<< ans2 << endl;


    return 0;
}