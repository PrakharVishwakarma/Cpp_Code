#include<iostream>
#include<cstring>
#include<vector>
using namespace std;

void changrArray(bool arr[], int size);

void sortZeroOne(bool arr[] , int size);

void printArray(bool arr[],int size);

int main()
{

/*
string str;
cout<<"Write the regular expression .";
cin>>str;


for (int i = 0; i < str.length(); i++)
{
    if(str[i]!='a'||str[i]!='\0'){
        cout<<"Expression is not valid.";
        break;
    }
    
    else{ 
        if (i==str.length()-1){
        cout<<"Regular expression is valid";
        }
        else{
            continue;
        }   
    }
}
*/


/*
int str[15];

memset(str , 1, sizeof(int)*10);
memset(str + 10 , 5, sizeof(int)*5);
cout<<str[0];
*/

/*
vector<int>v1;

 v1.push_back(2);
// v1.push_back(4);

cout<<"Size : "<<v1.size()<<endl;
cout<<"Capacity : "<<v1.capacity()<<endl;


for (int i = 0; i < v1.size(); i++)
{
    cout<<v1[i];
}
cout<<endl;

vector<int>v2(8);

cout<<"Size : "<<v2.size()<<endl;
cout<<"Capacity : "<<v2.capacity()<<endl;
for (int i = 0; i < v2.size(); i++)
{
    cout<<v2[i]<<" ";
}
*/


/*
vector<int>v2(8,-1);
cout<<endl<<"Size : "<<v2.size()<<endl;
cout<<"Capacity : "<<v2.capacity()<<endl;
for (int i = 0; i < v2.size(); i++)
{
    cout<<v2[i]<<" ";
}
*/


/*Find duplicate of number : 
    vector<int>v3{1,2,3,4,5,6,6,5,3,2,1};

    cout<<endl<<"Size : "<<v3.size()<<endl;
    cout<<"Capacity : "<<v3.capacity()<<endl;
    for (int i = 0; i < v3.size(); i++)
    {
        cout<<v3[i]<<" ";
    }
    cout<<endl<<"Vector v3 is empty or not "<<v3.empty();
        int start = 0;
    for (int i = 0; i < v3.size(); i++)
    {

        start = start ^ v3[i];
    }
    cout<<start;
    */

    
    /*Union of two arrays :  

     vector<int>v4{1,2,3,4,5,6};
     vector<int>v5{7,8,9};
     cout<<endl<<"Size : "<<v4.size()<<endl;
     cout<<"Capacity : "<<v4.capacity()<<endl;
     cout<<endl<<"Size : "<<v5.size()<<endl;
     cout<<"Capacity : "<<v5.capacity()<<endl;

    for (int i = 0; i < v5.size(); i++)
    {
        v4.push_back(v5[i]);
    }
    for (int i = 0; i < v4.size(); i++)
    {
        cout<<v4[i]<<" ";
    }
    */


/*
   int arr[100];

   int n;
   cout<<"Enter the size of array "<<endl;
    cin>>n;
    cout<<"Enter the elements of array "<<endl;

    for (int i = 0; i < n; i++)
    {
        cin>>arr[i];
    }

    for (int i = 0; i < n; i++)
    {
        
        if(i==n-1){
            arr[n-1]=arr[0];
        }
        else{
            int k = i+1;
            arr[i]=arr[k];
        }
    }
    for (int i = 0; i < n; i++)
    {
        cout<<arr[i]<<" ";
    }
*/

/*
    vector<int>v5(5);
    cout<<"Enter the size of array : ";
    int n;
    cin>>n;
    cout<<"Enter the elements of array : ";
    for (int i = 0; i < v5.capacity(); i++)
    {
        cin>>v5[i];
    }
    
    for (auto i : v5)
    {
        cout<<i<<" ";
    }

    for (int i = 0; i < v5.size(); i++)
    {
       for(int j = 0 ; j<v5.size(); j++){
        int count = 0;
            if(v5[i]==v5[j]){
                count++;
                if (count>(v5.size())/2)
                {
        
                    cout<<v5[i];
                }
            }
        }
    }
*/
bool arr[8];
/*
 int N;
   
    for (int i = 0; i < sizeof(arr); i++)
    {
        cin>>*(arr+i);
        

    }


    for (int i = 0; i < sizeof(arr); i++)
    {
        cout<<*(arr+i)<<" ";
        cout<<(arr+i)<<endl;
    
    }
*/

/*    memset(arr , 0 , sizeof(arr));

    changrArray(arr , sizeof(arr));
    cout<<endl;
 
    for (int i = 0; i < sizeof(arr); i++)
    {
        cout<<*(arr+i)<<" "<<(arr+i)<<endl; 
    }
    cout<<sizeof(*arr+1);
*/ 
       
    for (int i = 0; i < sizeof(arr); i++)
    {
        cin>>*(arr+i);
    }

    printArray(arr , sizeof(arr));
    cout<<endl;
    sortZeroOne(arr , sizeof(arr));
    cout<<endl;
    printArray(arr , sizeof(arr));

    return 0;

}

void changrArray(bool arr[], int size){
    arr[5]=1;
    arr[6]=1;
    arr[7]=1;
    for (int i = 0; i < size; i++)
    {
        cout<<*(arr+i)<<" "<<(arr+i)<<endl; 
    }

}


void printArray(bool arr[],int size){
        for (int i = 0; i < size; i++)
    {
        cout<<*(arr+i)<<" ";
        cout<<(arr+i)<<endl;
    }
    
}