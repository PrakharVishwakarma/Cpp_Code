// Insert Element in sorted stack.
// Sort the stack 

#include<iostream>
#include<stack> 

using namespace std; 

void insertElem(stack<int> &st, int &elem){
    if(st.empty() || elem > st.top()){
        st.push(elem);
        return;
    }

    int top = st.top();
    st.pop();
    insertElem(st, elem);

    st.push(top);
}

void sortSt(stack<int> &st){
    if(st.empty())return;

    int top = st.top();
    st.pop();

    sortSt(st);

    insertElem(st, top);
}

void printStack(stack<int>&st){
    if (st.empty())return;
    
    int top = st.top();
    cout<<top<<" ";
    st.pop();
    printStack(st);
    st.push(top);
}

int main(){
    stack<int> st;
    st.push(5);
    st.push(9);
    st.push(15);
    st.push(29);
    st.push(95);

    int element = 75;
    insertElem(st, element);
    printStack(st);
    cout<<endl;
    

    stack<int> st2;
    st2.push(25);
    st2.push(92);
    st2.push(1);
    st2.push(9);
    st2.push(7);
    st2.push(57);

    printStack(st2);
    cout<<endl;

    sortSt(st2);
    printStack(st2);
    cout<<endl;
    return 0;
}