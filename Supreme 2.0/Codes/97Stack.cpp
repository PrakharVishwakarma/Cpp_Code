// Find Middle of the stack : 

#include<iostream>
#include<stack>

using namespace std;

int getMidPos(stack<int>&st){
    if(st.empty()){
        cout<<"Stack is Empty."<<endl;
        return -1;
    }
    
    int sizeOfSt = st.size();
    return (sizeOfSt & 1) ? (sizeOfSt/2)+1 : (sizeOfSt/2);
}

void getMid(stack<int>&st, int &pos, int &ans){
    if(pos==1){
        ans = st.top();
        return;
    }
    int top = st.top();
    st.pop();
    getMid(st, --pos, ans);
    st.push(top);
}

int main(){
    
    stack<int> st;

    st.push(52);
    st.push(54);
    st.push(63);
    st.push(10);
    st.push(44);
    st.push(55);
    st.push(53);
    st.push(46);

    int midOfSt = getMidPos(st); 
    if(midOfSt == 0){
        cout<<"Middle Element is : "<<st.top()<<endl;
    }else if (midOfSt < 0)
    {
        cout<<"Can not find the middle element."<<endl;
    }else{
        int ans = -1;
        getMid(st, midOfSt, ans);
        cout<<"Middle Element is : "<<ans<<endl;
    }
    
return 0;
}