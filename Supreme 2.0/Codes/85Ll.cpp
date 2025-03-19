// Given the head of a linked list, rotate the list to the right by k places.
/*
Input: head = [1,2,3,4,5], k = 2
Output: [4,5,1,2,3]
*/

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

Node* rotateRight(Node* head, int &k, int &l) {
    int actualRotation = k%l;       // if k > l
    if(actualRotation == 0) return head;
    int newLastNodePos = l - actualRotation - 1;
    Node* newLastNode = head;
    for (int i = 0; i < newLastNodePos; i++){
        newLastNode = newLastNode->next;
    }
    Node* newHead = newLastNode->next;
    newLastNode->next = 0;
    Node* it = newHead;
    while (it->next){
        it = it->next;
    }
    it->next = head;
    return newHead;
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
    
    int k = 2;
    int lengthOfRotetedLl = printLlAndGetLength(rotateRight(head, k, lengthOfLl));
    
    lengthOfLl = printLlAndGetLength(head);

return 0;
}