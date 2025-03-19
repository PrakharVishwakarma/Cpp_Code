// Leetcode 1019 : Next greater node in the linked list.
/*
 2->7->4->3->5

*/

#include<iostream>
#include<vector>
#include<stack>
using namespace std;

class Node{
public:
    int data;
    Node *next;

    Node(int data){
        this->data = data;
        this->next = NULL;
    }

    ~Node(){
        cout<<"Destructor called for "<<this->data<<endl;
        delete next;
    }

};

int printLlAndGetLength(Node *head){                       // Node pass by refrence.
    Node *temp = head;  // Acchi Practice : 

    cout<<"Printing the Linked List : ";
    int length = 0;
    while (temp != NULL)
    {
        cout<<temp->data<<"->";
        temp = temp->next;
        length++;
    }
    cout<<endl;  
    cout<<"Length of Linked List : "<<length<<endl;  

return length;
}

vector<int> nextLargerNodes(Node* head) {
    vector<int>ll;
    Node* temp = head;
    while(temp){
        ll.push_back(temp->data);
        temp = temp->next;
    }
    stack<int> st;
    for (int i = 0; i < ll.size(); i++){
        while (!st.empty() && ll[i] > ll[st.top()]){
            ll[st.top()] = ll[i];
            st.pop();
        }               
        st.push(i);     
    }
    while (!st.empty()){ 
            ll[st.top()] = 0; 
            st.pop();
        }
    ll[ll.size()-1] = 0;
    return ll;
}


int main(){
    Node *first = new Node(2);
    Node *second = new Node(7);
    Node *third = new Node(4);
    Node *fourth = new Node(3);
    Node *fifth = new Node(5);

    Node* head = first;
    Node* tail = fifth;

    head->next = second;
    second->next = third;
    third->next = fourth;
    fourth->next = fifth;
    fifth->next = NULL;

    int lengthOfLl = printLlAndGetLength(head);

    vector<int>ans = nextLargerNodes(head);

    for (int i = 0; i < ans.size(); i++){
        cout<<ans[i]<<" ";
    }

    return 0;
}

/*
#include<iostream>
#include<vector>
#include<stack>
using namespace std;
    
vector<int> nextLargerNode(int *arr , int &n){
    vector<int>ans(n);
    stack<int>st;

    for (int i = 0; i < n; i++){
        while (!st.empty() && arr[i] > arr[st.top()])
        {
            int kids = st.top();
            st.pop();
            ans[kids] = arr[i];
        }
        st.push(i);
    }
    
return ans;
} 


int main(){
 
    int arr[] = {2, 7, 4, 3, 5};
    int size = sizeof(arr)/sizeof(int);
    for (int i = 0; i < size; i++){
        cout<<arr[i]<<" ";
    }cout<<endl;

    vector<int>ans = nextLargerNode(arr , size);
    for (int i = 0; i < ans.size(); i++){
        cout<<ans[i]<<" ";
    }
    

return 0;
}
*/