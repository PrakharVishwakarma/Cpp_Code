
// Reverse a singly linked list.[ Leetcode 206 : ]
#include<iostream>
using namespace std;

class Node{
public:
    int data;
    Node *next;

    Node(){
        this->next = NULL;
    }

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

Node* reverseLlIteratively(Node* head){
    Node* currPrev = NULL;
    Node* curr = head;
    while(curr != NULL)
    {
        Node *currNext = curr->next;
        curr->next = currPrev;
        currPrev = curr;
        curr = currNext;
    }
    return currPrev;
}
// Time Complexity = O(n)

Node* reverseLlRecursively(Node* currPrev, Node* curr){
    if (curr == NULL){
        return currPrev;
    }
    Node *currNext = curr->next;
    curr->next = currPrev;
    currPrev = curr;
    curr = currNext;   

    return reverseLlRecursively(currPrev , curr);   
}

int main(){
    Node *first = new Node(5);
    Node *second = new Node(15);
    Node *third = new Node(25);
    Node *fourth = new Node(35);
    Node *fifth = new Node(45);

    Node* head = first;
    Node* tail = fifth;

    head->next = second;
    second->next = third;
    third->next = fourth;
    fourth->next = tail;

    int lengthOfLl = printLlAndGetLength(head);
    // lengthOfLl = printLlAndGetLength(reverseLlIteratively(head));

    Node* curr = head;
    Node* currPrev = NULL;
    lengthOfLl = printLlAndGetLength(reverseLlRecursively(currPrev,curr));
    

return 0;
}