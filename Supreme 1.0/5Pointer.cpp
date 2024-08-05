#include<iostream>
using namespace std;


int main(){
    int arr[10] = {1,5,6,10,85,5,9,3,4,7};

    int (*ptr)[10];


    cout<<&arr[0]<<endl;
    cout<<&arr[1]<<endl;
    cout<<&arr[2]<<endl;
    cout<<&arr[3]<<endl;

    cout<<endl<<ptr[0]<<endl;
    cout<<ptr[1]<<endl;
    cout<<ptr[2]<<endl;
    cout<<ptr[3]<<endl;

    cout<<endl<<(*ptr)[0]<<endl;
    cout<<(*ptr)[1]<<endl;
    cout<<(*ptr)[2]<<endl;
    cout<<(*ptr)[3]<<endl;


return 0;
}