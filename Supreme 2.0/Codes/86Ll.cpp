// 2058. Find the Minimum and Maximum Number of Nodes Between Critical Points

#include<iostream>
#include<vector>
#include<limits.h>
#include<limits>

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

vector<int> nodesBetweenCriticalPoints(Node* head) {
    vector<int>ans = {-1, -1};
    Node* prev = head;
    if(!prev)return ans;
    Node* curr = head->next;
    if(!curr)return ans;
    Node* nxt = head->next->next;
    if(!nxt)return ans;

    int firstCp = -1;
    int lastCp = -1;
    int minDist = INT_MAX;
    int i = 1;
    while (nxt){
        bool isCp = ((curr->data > prev->data && curr->data > nxt->data) || (curr->data < prev->data && curr->data < nxt->data));
        if(isCp && firstCp == -1){
            firstCp = i;
            lastCp = i;
        }else if(isCp){
            minDist = min(minDist, i-lastCp);
            lastCp = i;
        }   
        
        ++i;
        prev = prev->next;
        curr = curr->next;
        nxt = nxt->next;
    }
    if(lastCp == firstCp)return ans;
    else{
        ans[0] = minDist;
        ans[1] = lastCp - firstCp;
    }
    return ans;
}

int main(){
    Node *first = new Node(5);
    Node *second = new Node(3);
    Node *third = new Node(1);
    Node *fourth = new Node(2);
    Node *fifth = new Node(5);
    Node *sixth = new Node(1);
    Node *seventh = new Node(2);

    Node* head = first;
    Node* tail = seventh;

    head->next = second;
    second->next = third;
    third->next = fourth;
    fourth->next = fifth;
    fifth->next = sixth;
    sixth->next = seventh;
    seventh->next = NULL;

    int lengthOfLl = printLlAndGetLength(head);

    vector<int>ans = nodesBetweenCriticalPoints(head);
    for (int i = 0; i < ans.size(); i++){
        cout<<ans[i]<<" ";
    }
    
    return 0;
}