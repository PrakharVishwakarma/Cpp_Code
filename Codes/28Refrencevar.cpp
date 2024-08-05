# include<iostream>
using namespace std;

void update1(int n){
    n++;
} 
void update2(int *p){
    *p++;
}    
void update3(int& m){
    m++;
}   

int& function(int n){
    int& number = n;
    return number; 
}
int* function2(int n){
    int *ptr = &n;
    return ptr;  
}

int main()
{
    int i = 5;
    int& j = i;         // j is refrence variable .

    cout<<"The value of i is "<< i << " and value of j is "<< j<<endl;
    i++;
    cout<<"The value of i is "<< i << "and value of j is "<< j<<endl;
    j++;
    cout<<"The value of i is "<< i << "and value of j is "<< j<<endl;

    cout<<"The value of i is "<< i<<endl;
    update1(i);                 // call by value .
    cout<<"After function call the value of i is "<<i<<endl;

    update2(&i);                 
    cout<<"After function call the value of i is "<<i<<endl;

    update3(i);                 // call by refrence .
    cout<<"After function call the value of i is "<<i<<endl;

    int a = 9;
    function(a);
    cout<<"After function call the value of a is "<<a<<endl;
    function2(a);
    cout<<"After function call the value of a is "<<a<<endl;
}
 
