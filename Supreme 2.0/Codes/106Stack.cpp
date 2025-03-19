// Impement N-stacks in an array.

#include<iostream>
#include<stack>

using namespace std;

class Nstack{
    int *a, *top, *next;
    int numOfStacks; // Number of stacks.
    int sizeOfArr; // Size of an array.
    int freeSpot;
public:
    Nstack(int n, int size):numOfStacks(n),sizeOfArr(size){
        top = new int[n];   // Stores top of each (ith) stack.
        a = new int[size];
        next = new int[size];   // Initially Stores next free spot    or      can point to next elem after top elem of that particular stack(jab us particular stack ke andar kuchh hoga).

        for (int i = 0; i < n; i++)
        {
            top[i] = -1;
        }
        for (int i = 0; i < size; i++)
        {
            next[i] = i+1;
        }
        next[size-1] = -1;
    }

bool push(int x , int m){   //Push x in mth stack.
    if(freeSpot == -1){
        cout<<"Staack Overflow."<<endl;
        return -1;
    }
    // 1. Index ke liye freespot dhoondo.
    int index = freeSpot;
    // 2. Update free spot
    freeSpot = next[index];
    // 3. array me x insert karo
    a[index] = x;
    // 4. next upadte karo 
    next[index] = top[m-1];
    // 5. top bhi upadate karo
    top[m-1] = index;
return true; 
} 

int pop(int m){     //Pop from mth stack.
    if (top[m-1] == -1)
    {
        cout<<"Stack Undeflow."<<endl;
    }
    int index = top[m-1];
    top[m-1] = next[index];
    int poppedElement = a[index];
    next[index] = freeSpot;
    freeSpot = index;

return poppedElement;
}

~Nstack(){
    delete[] a;
    delete[] top;
    delete[] next;
}

};

int main(){
    
    Nstack nSt(3,6);
    cout<<nSt.push(10 , 1)<<endl;
    cout<<nSt.pop(1)<<endl;


return 0;
}