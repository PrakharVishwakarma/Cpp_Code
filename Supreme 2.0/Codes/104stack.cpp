// GFG : Celebrity Problem : 

#include<iostream>
#include<stack>
#include<vector>
using namespace std;

int findCelebrity(vector<vector<int> >&v , int n){

    // Push all the person in the stack.
    stack<int>st;
    for (int i = 0; i < n; i++)
    {
        st.push(i);
    }

    // Discard method to get the person might be celebrity
    while (st.size() != 1)
    {
        int a = st.top(); st.pop();
        int b = st.top(); st.pop();
        if (v[a][b] == 1)
        {
            st.push(b);
        }
        else{
            st.push(a);
        }
    }
     
    int mightBeCelebrity = st.top();
    // Now check whether st.top is a celebrity or not.
    for (int i = 0; i < n; i++)
    {
        if (v[mightBeCelebrity][i] == 1)return -1;
        if (v[i][mightBeCelebrity] == 0 && i != mightBeCelebrity) return -1;
    }
    
return mightBeCelebrity;
}

int main()
{
    vector<vector<int> >v = {
        {0 , 1 , 1 , 1},
        {0 , 0 , 1 , 1},
        {0 , 0 , 0 , 0},
        {1 , 1 , 1 , 0}
    };

    int numberOfPerson = 4;    // numberOfPerson = number of rows in the vector.
    cout<<"Person number "<<findCelebrity(v , numberOfPerson)<<" is celebrity."<<endl;
    
return 0;
}



/*
    int celebrity(vector<vector<int> >& mat) {
        int n = mat[0].size();
        stack<int>st;
        
        for(int i = 0; i < n; i++) st.push(i);
        
        while(st.size() != 1){
            int a = st.top(); st.pop();
            int b = st.top(); st.pop();
            (mat[a][b] == 1) ? st.push(b) : st.push(a);
        } 
        
        int mightBeCelebrity = st.top();
        for (int i = 0; i < n; i++){
            if (mat[mightBeCelebrity][i] == 1)return -1;
            if (mat[i][mightBeCelebrity] == 0 && i != mightBeCelebrity) return -1;
        }
        
        return mightBeCelebrity;
    }
*/