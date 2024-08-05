#include <iostream>
using namespace std;

int main(){
    int n; 
    cout<<"Enter the value of n ";
    cin>>n;

/*
    for( int i=0; i<n;i++){

        for(int j=0; j<n; j++){
            if(i==0 || i==n-1 ){
           cout<<"*";
            }
            else if(j==0 || j==n-1){
                cout<<"*";
            }
            else{
            cout<<" ";
            }
        }
        cout<<endl;
    }

*/

/*
    for(int row = 0 ; row < n ; row++){

        
        for(int col = 0 ; col < row + 1 ; col++)
        {
            if(col==0||col==row){
                cout<<col+1;
            }
            else if(row == 0 || row == n-1){
                cout<<col+1;
            }
            else{
                cout<<" ";
            }
       
        }
         cout<<endl;    
    }

*/

/*
    for (int row = 0; row < n; row++)
    {
        for (int col = 0; col < n - row; col++)
        {
            if(row == 0 ){
                cout<<col+1;
            }
            else if(col == 0){
                cout<<row+1;
            }
            else if(col == n-(row+1)){
                cout<<n;
            }
            else{
                cout<<" ";
            }
        }
        cout<<endl;
        
    }
*/




    for(int row = 0 ; row < n ; row++)
        {
            for (int col = 0; col < n+3-row; col++){
                cout<<"*";
            }
            
            for(int col = 0; col < (2*row)+1 ; col++)
            {
                if(col%2==0 && col!=(2*row))
                {
                    cout<<"*";
                }
                else if(col%2==1){
                    cout<<row;
                }
                    
            }
        

        for (int col = 0; col < n+3-row; col++)
        {
            cout<<"*";
        }
        
    cout<<endl;
}


return 0;

    }


