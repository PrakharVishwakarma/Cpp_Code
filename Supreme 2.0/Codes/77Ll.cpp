// Remove Duplicates from the sorted linked list.

#include<iostream>
#include<map>
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

Node* removeDuplicate(Node* head){
    if (head == NULL){
        return head;
    }
    if (head->next == NULL){
        return head;
    }
    
    Node* temp = head;
    while(temp != NULL)
    {
        if (temp->next != NULL && temp->data == temp->next->data)
        {
            Node* nextNode = temp->next;
            temp->next = nextNode->next;
            nextNode->next = NULL;
            delete(nextNode);

        }
        else{
            temp = temp->next;
        }
    }
    return head;
}
int main()
{
    Node *first = new Node(5);
    Node *second = new Node(15);
    Node *third = new Node(25);
    Node *fourth = new Node(25);
    Node *fifth = new Node(35);
    Node *sixth = new Node(450);
    Node *seventh = new Node(450);
    Node *eighth = new Node(2555);

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
    printLlAndGetLength(removeDuplicate(head));

return 0;
}