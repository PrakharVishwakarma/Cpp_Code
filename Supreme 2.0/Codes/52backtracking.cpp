// Count Dearrnagement (GFG).

#include<iostream>
using namespace std;

int countDer(int n)
{
  // Base cases
  if (n == 1) return 0;
  if (n == 2) return 1;

  // countDer(n) = (n-1)[countDer(n-1) + der(n-2)]
  return (n - 1) * (countDer(n - 1) + countDer(n - 2));
}

int main()
{
    int n = 4;
    cout << "Count of Derangements of "<<n<<" is : "<< countDer(n);
    return 0;
}





