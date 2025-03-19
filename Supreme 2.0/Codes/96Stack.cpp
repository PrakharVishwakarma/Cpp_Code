#include<iostream>
using namespace std;

class Stack {
public:
    int *arr;
    int capacity;
    int top;

    Stack(int capacity) {
        this->capacity = capacity;
        this->arr = new int[capacity];  
        this->top = -1;  
    }

    bool isEmpty() {
        return top == -1;
    }

    void push(int data) {
        if (top >= capacity - 1) {
            cout <<"Can't push cause Stack Overflow." << endl;
        } else {
            top++;
            arr[top] = data;
        }
    }

    int pop() {
        if (isEmpty()) {
            cout <<"Can't Pop cause stack Underflow." << endl;
            return -1;  
        } else {
            int poppedElement = arr[top];
            top--;
            return poppedElement;
        }
    }

    int getTop() {
        if (isEmpty()) {
            cout <<"Can't get top cause stack is Empty." << endl;
            return -1;  
        } else {
            return arr[top];
        }
    }

    int getSize() {
        return top + 1;
    }

    ~Stack() {
        delete[] arr;
        cout << "Stack memory freed!" << endl;
    }
};

int main() {
    Stack s(5);  

    s.push(10);
    s.push(20);
    s.push(30);

    cout << "Top element: " << s.getTop() << endl;
    cout << "Stack size: " << s.getSize() << endl;

    s.pop();
    cout << "Top element after pop: " << s.getTop() << endl;
    cout << "Stack size after pop: " << s.getSize() << endl;

    s.pop();
    s.pop();
    if(s.isEmpty()){
        cout<<"Stack is empty"<<endl;
    }else{
        cout<<"Stack is not empty"<<endl;
    }

    cout << "Now the Top element is : " << s.getTop() << endl;
    cout << "Now the Stack size is : " << s.getSize() << endl;
    
    s.pop();

    return 0;
}





 