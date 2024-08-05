/*
#include<iostream>
using namespace std;

void print(int *p) {

//     cout << *p << endl; 

// }

// void update(int *p) {

//    // p = p + 1;
//    //cout << "inside "<< p <<endl;
//    *p = *p + 1;

// }

// int getSum(int *arr, int n) {

//     cout << endl << "Size : " << sizeof(arr) << endl;

//     int sum = 0;
//     for(int i=0;i<n;i++) {
//         sum += arr[i];
//     }
//     return sum;
// }

// int main() {

//     int value = 5;
//     int *p = &value;
//     print(p);
//     cout <<" Before " << *p << endl;
//     update(p);
//     cout <<" After " << *p << endl;
// }

*/


#include<iostream>
using namespace std;

int main(){
    int n;
    cout<<"Enter the value of n : ";
    cin>>n;


/*
    for (int row = 0; row < n; row++)
    {
        for (int col = 0; col < row +1 ; col++)
        {
            if(col==0 || row==col){
                cout<<col+1;
            }
            else if (row == col)
            {
                cout<<row+1;
            }
            else if (row==n-1)
            {
                cout<<col+1;
            }
            
            else {
                cout<<" ";
                }
        }
        cout<<endl;
        
    }
  */ 


/*
        for (int row = 0; row < n; row++)
        {
            for (int col = 0; col < row+1 ; col++)
            {
                cout<<"*";
            }
            cout<<endl;
        }

        for (int row = 0; row < n-1; row++)
        {
            for (int col = 0; col< (n-1)-row; col++)
            {
             cout<<"*";   
            }
            cout<<endl;
        }
*/        


/*
int start=2;
     for (int row = 0; row < n; row++)
        {
            
            for (int col = 0; col < 2*row+1 ; col++)
            {
                if (row==0)
                {
                    cout<<1;
                    
                }
                
                else if (col%2==1)
                {
                    cout<<"*";
                }
                else{
                    cout<<start;
                    start++;
                }
                
            }
            cout<<endl;
        }
        start--;
        for (int row = 0; row < n-1; row++)
        {
            for (int col = 0; col< 2*n-(2*row+1); col++)
            {
                if(start == 1){
                    cout<<1;
                }
                else if (col%2==0)
                {
                    cout<<start--;
                }
                else{
                    cout<<"*";
                }

            }
        cout<<endl;
        }
    */



   /*
   for (int row = 0; row < n; row++)
   {
        for (int col = 0; col < n; col++)
        {
          
            if(col<=row){
                cout<<"*";
            }
            else{
                cout<<" ";
            }
            
        }
 
        for (int col = 0; col < n; col++)
        {
          if (col<n-row-1)
          {
            cout<<" ";
          }
          else{
          cout<<"*";
          }
        }
    cout<<endl;
   }
    for (int row = 0; row < n; row++)
    {
        for (int col = 0; col < n; col++)
        {
            if (col<n-row-1)
            {
                cout<<"*";
            }
            else{
            cout<<" ";
            }
        }
        for ( int col = 0; col < n; col++)
        {
             if(col<=row){
                cout<<" ";
            }
            else{
                cout<<"*";
            }
        } 
    cout<<endl;
   }
*/


    for (int row = 0; row < n; row++)
        {
            for (int col = 0; col < n; col++)
            {
                if(col<n-(row)){
                    cout<<" ";
                }
                else{
                    cout<<"0";
                }
            }

            for (int col = 0; col < n; col++)
            {
                if (col<=row)
                {
                    cout<<"0";
                }
                else{
                    cout<<" ";
                }
            }

            for (int col = 0; col < n; col++)
            {
                if(col<n-(row)){
                    cout<<" ";
                }
                else{
                    cout<<"0";
                }
            }

            for (int col = 0; col < n; col++)
            {
                if (col<=row)
                {
                    cout<<"0";
                }
                else{
                    cout<<" ";
                }
            }    
        cout<<endl;
    }

    int m = 2*n;

    for (int row = 0; row < m; row++)
    {
            for (int col = 0; col < m; col++)
            {
                if (col<=row)
                {
                    cout<<" ";
                }
                else{
                    cout<<"0";
                }
            }

            for (int col = 0; col < m; col++)
            {
                if(col<m-(row)){
                    cout<<"0";
                }
                else{
                    cout<<" ";
                }
            }
        cout<<endl;
    }

    return 0;
}