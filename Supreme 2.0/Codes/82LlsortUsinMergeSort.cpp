// Sort Linked List using merge sort.


#include<iostream>
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

Node* findMid(Node* head){
    Node* slow = head;
    Node* fast = head->next;
    while (fast && fast->next)
    {
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}

Node* mergeList(Node* left , Node *right){
    if (left == 0)return right;
    if (right == 0)return left;
    

    Node *mptr = new Node(-1);
    Node *ans = mptr;

    while (left && right)
    {
        if (left->data <= right->data)
        {
            mptr->next = left;
            mptr = left;
            left = left->next;
        }
        else{
            mptr->next = right;
            mptr = right;
            right = right->next;
        }
    }
    if (left)
    {
        mptr->next = left;
    }
    if (right)
    {
        mptr->next = right; 
    }
        
return ans->next;
}

Node* mergeSort(Node* head){
    if (head == 0 || head->next == 0)return head;
    
    Node* midNode = findMid(head); 
    Node* leftListHead = head;
    Node* rightListHead = midNode->next;
    midNode->next = 0;

    leftListHead = mergeSort(leftListHead);
    rightListHead = mergeSort(rightListHead);

    Node* mergedLl = mergeList(leftListHead,rightListHead);
return mergedLl;
}

int main(){

    Node *first = new Node(5);
    Node *second = new Node(15);
    Node *third = new Node(75);
    Node *fourth = new Node(55);
    Node *fifth = new Node(85);
    Node *sixth = new Node(4);
    Node *seventh = new Node(50);
    Node *eighth = new Node(55);

    Node* head = first;
    Node* tail = sixth;

    head->next = second;
    second->next = third;
    third->next = fourth;
    fourth->next = fifth;
    fifth->next = sixth;
    sixth->next = seventh;
    seventh->next = eighth;
    eighth->next = NULL;

    int lengthOfLl = printLlAndGetLength(head);
    
    printLlAndGetLength(mergeSort(head));

return 0;
}