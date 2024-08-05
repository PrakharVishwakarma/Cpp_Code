#include<iostream>
using namespace std;

void printArr(int *arr, int size) {
    for (int i = 0; i < size; ++i) {
        std::cout << arr[i] << " ";
    }cout<<endl;
    cout <<sizeof(arr) <<endl; // Print newline after the array
}
int main()
{
    int arr[2];
    0[arr]=0;
    cout<<0[arr];

    int ar[] = {1, 2, 3, 4, 5}; // Example array
    int size = sizeof(ar) / sizeof(ar[0]); // Calculate the size of the array
    printArr(ar, size); // Call the printArr function to print the array
    cout<<endl<<sizeof(ar);
    return 0;
return 0;
}

