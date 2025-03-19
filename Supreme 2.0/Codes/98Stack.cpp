// Insert at bottom of the stack.
// Reverse the stack.

#include<iostream>
#include<stack>

using namespace std;

void printStack(stack<int>&st){
    if (st.empty())return;
    
    int top = st.top();
    cout<<top<<" ";
    st.pop();
    printStack(st);
    st.push(top);
}

void insertAtBottom(stack<int>&st, int &elementToInsert){
    if (st.empty()){
        st.push(elementToInsert);
        return;
    }

    int top = st.top();
    st.pop();    
    insertAtBottom(st, elementToInsert);
    st.push(top);
}

void reverseStack(stack<int> &st){
    if(st.empty()) return;

    int top = st.top();
    st.pop();
    reverseStack(st);

    insertAtBottom(st, top); 
}

int main(){

    stack<int> st;
    
    st.push(36);
    st.push(65);
    st.push(63);
    st.push(46);
    st.push(43);

    int elementToInsert = 70;

    printStack(st);
    cout<<endl;
    insertAtBottom(st, elementToInsert);
    printStack(st);
    cout<<endl;

    reverseStack(st);
    printStack(st);

    return 0;
}