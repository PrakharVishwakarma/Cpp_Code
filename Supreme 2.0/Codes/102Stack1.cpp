// Implement MinStack that tracks the min element till the top element.

#include<iostream>
#include<utility>
#include<algorithm>
#include<vector>

using namespace std;

class MinStack {
public:
    vector<pair<int, int>> st; 

    MinStack() = default;

    void push(int data) {
        if (st.empty()) {
            st.push_back({data, data});
        } else {
            st.push_back({data, min(data, st.back().second)});
        }
    }

    void pop() {
        if (st.empty()) {
            cout << "Stack is empty, can't pop." << endl;
        } else {
            st.pop_back();
        }
    }

    int top() {
        if (st.empty()) {
            cout << "Stack is empty, no top element." << endl;
            return -1; 
        } else {
            return st.back().first;
        }
    }

    int getMin() {
        if (st.empty()) {
            cout << "Stack is empty, no minimum element." << endl;
            return -1; 
        } else {
            return st.back().second;
        }
    }
    ~MinStack() = default;
};

int main() {

    MinStack minStack;


    minStack.push(5);
    minStack.push(3);
    minStack.push(7);
    minStack.push(2);
    minStack.push(6);


    cout << "Current minimum: " << minStack.getMin() << endl;  

    
    cout << "Current top: " << minStack.top() << endl;  

    minStack.pop();  
    cout << "Current top after pop: " << minStack.top() << endl;  

    cout << "Current minimum after pop: " << minStack.getMin() << endl;  

    minStack.pop();  
    cout << "Current top after pop: " << minStack.top() << endl;  
    cout << "Current minimum after pop: " << minStack.getMin() << endl;  


    minStack.pop();  
    minStack.pop();  
    minStack.pop();  
    cout << "Current top after popping all elements: " << minStack.top() << endl;  
    cout << "Current minimum after popping all elements: " << minStack.getMin() << endl;  

    return 0;
}
