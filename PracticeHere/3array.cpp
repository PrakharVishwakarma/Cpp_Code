#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    const int size = 10;
    int arr[size];

    int valueAtEachIndex;
    cout<<"Give the initial value at each index : ";
    cin>>valueAtEachIndex;

    // Initialize the array with value  at each index
    fill(arr, arr + size, valueAtEachIndex);

    // Print the array elements
    cout << "Array elements: ";
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}