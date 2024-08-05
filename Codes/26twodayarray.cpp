//Create two d array : 
#include<iostream>
bool isPresent(int arr[3][4], int target, int row, int col) {

  for(int row=0; row<3; row++) {
        for(int col=0; col<3; col++) {
            
            if( arr[row][col] == target) {
                return 1;
            }
            
        }
    }
    return 0;
}

using namespace std ;
int main(){

/*
    int arr[3][4];

cout << "Enter the elements " <<  endl;
    //taking input -> row wise input
    for(int row=0; row<3; row++) {
        for(int col=0; col<3; col++) {
            cin >> arr[row][col];
        }
    }


/*
//taking input -> col wise input
    for(int col=0; col<4; col++) {
        for(int row=0; row<3; row++) {
            cin >> arr[row][col];
        }
    }
*/


int arr[3][4] = {{1,11,111,1111},{2,22,222,2222},{3,33,333,3333}};

//    for(int row=0; row<3; row++) {
//         for(int col=0; col<3; col++) {
//             cout<<arr[row][col]<<" ";
//         }
//         cout<<endl;
//     }

   for(int col=0; col<3; col++) {
        for(int row=0; row<3; row++) {
            cout<<arr[col][row]<<" ";
        }
        cout<<endl;
    }
    
    int target ;
    cout<<"Enter yout target ";
    cin>>target;
    if(isPresent(arr, target, 3, 4)) {
        cout <<" Element found " << endl;
    }
    else{
        cout <<" Not Found" << endl;
    }
}