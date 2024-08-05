// peace of program in a program that is replaced by value... Example :
// # Define  PI 3.14
# include<iostream>
using namespace std;

int s = 50; // Called global variablr.   // It is the bad practice, because it can be change by any function .
# define PI 3.14
#define AREA(l,b) (l*b) 

int main(){

    int radius ;
    cout<<"Enter the radii ";
    cin>>radius;

    cout<<"The area of circle is "<<PI * radius *radius<<endl;

    int l1 = 9;
    int l2 = 6;
    int area = AREA(l1,l2);
    cout<<"Area of rectangle is "<<area<<endl;
    cout<<s;
}
/* INLINE FUNCTION :

# include<iostream>
using namespace std;

inline int getMax(int& a , int& b)      //  inline function : it should not be more than 3 lines.
{
    return (a>b) ? a : b;
}

int main() {
    int a;
    int b;
    cout<<"Enter a and b ";
    cin>>a>>b;

    int ans = 0;
    ans = (a>b) ? a:b;      
    cout<<ans;
    
    // if (a > b){
    //     cout<<"a is greater";
    // }
    // else{
    //     cout<<"b is grater";
    // }
    
}
*/

// Default Args :

#include<iostream>
using namespace std;

void print(int arr[], int n  , int start = 0) {   // It always start with right most start.

    for(int i = start; i<n; i++) {
        cout << arr[i] << endl;
    }

}

int main() {

    int arr[5] = {1,4,7,8,9};
    int size = 5;

    print(arr, size);
    cout << endl;
    print(arr, size, 2);


    return 0;
}
