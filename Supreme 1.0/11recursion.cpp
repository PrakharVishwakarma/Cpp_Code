// Removing all the given substring from a string.

/*
#include<iostream>
using namespace std;

void removeSubStr(string &s , string &part){

    if(s.find(part) != string :: npos){
        // s = (s.substr(0 , s.find(part))) + (s.substr(s.find(part)+part.size() , s.size()));
        s.erase(s.find(part), s.find(part)+part.size());
        removeSubStr(s , part);
    }

    else cout<<s;
}

int main()
{
    string s;
    cout<<"Enter the string : ";
    cin>>s;
    string part;
    cout<<"Enter the part string : ";
    cin>>part;

    removeSubStr(s , part);

    return 0;
}
*/

// Print all subarray of an array.

#include<iostream>
using namespace std;

void printSubArr(int arr[], int s , int e , int size){
    if (e>=size){
        return;
    }

    for (int i = s; i <= e; i++)
    {
        cout<<arr[i];
    }
    cout<<endl;
    printSubArr(arr,s,e+1,size);
    
}

int main(){
    int arr[] = {1,2,3};
    int size = sizeof(arr)/sizeof(int);
    
    for (int s = 0; s < size; s++)
    {
        int e = s;
        printSubArr(arr,s,e,size);
    }  
}