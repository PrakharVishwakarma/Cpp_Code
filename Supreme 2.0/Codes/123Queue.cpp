// First Negative integer in each sliding window of size k.

#include<iostream>
#include<queue>
#include<deque>

using namespace std;

void printFirstNeg(int *arr, int size, int k){

    deque<int>dq;
    for (int i = 0; i < k; i++)
    {
        int element = arr[i];
        if (element < 0) 
        {
            dq.push_back(i);
        }    
    } 
    
    for (int i = k; i < size ; i++)
    {
        if (dq.empty())cout<<" 0 ";
        else cout<<arr[dq.front()]<<" "; 

        if (i - dq.front() >= k)
        {
            dq.pop_front();
        }
        if (arr[i] < 0)
        {
            dq.push_back(i);
        }   
    }
    if (dq.empty())cout<<" 0 ";
    else cout<<arr[dq.front()]<<" ";  
    
}

int main()
{
    int arr[] = {2 , -5 , 4 , -1 , -2 , 0 , 5};
    int n = sizeof(arr)/sizeof(int);
    int k = 3;
    printFirstNeg(arr , n , k);

return 0;
}

