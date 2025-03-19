// implementation of two stacks in a single array

#include <iostream>
#include <cstring>

using namespace std;

class Stack {
public:
    int *arr;
    int capacity;
    int top1;
    int top2;

    Stack(int capacity) {
        this->capacity = capacity;
        this->arr = new int[capacity];  
        memset(this->arr, 0, capacity * sizeof(int));
        this->top1 = -1;  
        this->top2 = capacity;  
    }

    void push1(int data) {
        if (top2 - top1 <= 1) {  
            cout << "Stack 1 Overflow. Can't push the data." << endl;
        } else {
            top1++;  
            arr[top1] = data;  
        }
    }

    // Push for stack 2
    void push2(int data) {
        if (top2 - top1 <= 1) {  
            cout << "Stack 2 Overflow. Can't push the data." << endl;
        } else {
            top2--;  
            arr[top2] = data;  
        }
    }

    void pop1() {
        if (top1 == -1) {  
            cout << "Stack 1 Underflow. Can't pop the data." << endl;
        } else {
            top1--;  
        }
    }

    void pop2() {
        if (top2 == capacity) {  
            cout << "Stack 2 Underflow. Can't pop the data." << endl;
        } else {
            top2++;  
        }
    }


    int getTop1() {
        if (top1 == -1) {
            cout << "Stack 1 is empty." << endl;
            return -1;  
        } else {
            return arr[top1];  
        }
    }

    int getTop2() {
        if (top2 == capacity) {
            cout << "Stack 2 is empty." << endl;
            return -1;  
        } else {
            return arr[top2];  
        }
    }

    bool isEmpty1() {
        return top1 == -1;
    }

    bool isEmpty2() {
        return top2 == capacity;
    }

    void printArr(){
        for (int i = 0; i < capacity; i++){
            cout<<arr[i]<<" ";
        }cout<<endl;
    }

    ~Stack() {
        delete[] arr;
        cout << "Stack memory freed!" << endl;
    }
};

int main() {
    Stack s(10);  

    s.push1(10);
    s.push1(20);
    s.push1(30);
    cout << "Top of Stack 1: " << s.getTop1() << endl;
    s.pop1();
    cout << "Top of Stack 1 after pop: " << s.getTop1() << endl;

    // Test stack 2
    s.push2(40);
    s.push2(50);
    cout << "Top of Stack 2: " << s.getTop2() << endl;
    s.pop2();
    cout << "Top of Stack 2 after pop: " << s.getTop2() << endl;

    s.printArr();

    return 0;
}
