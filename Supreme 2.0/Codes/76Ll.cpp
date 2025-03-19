//Leetcode 25 : Reverse group of k nodes in the linked list.

#include<iostream>
using namespace std;

#include<iostream>
#include<map>
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

Node* reverseKNodes(Node* head ,int k ,int lengthOfLl){
    if(head == NULL)
    {
        return head;
    }
    if (head->next == NULL)
    {
        return head;
    }
    
    
    Node* prev = NULL;
    Node* curr = head;
    Node* nextNode = curr->next;

    int pos = 0;
    if(lengthOfLl < k){
        return head;
    }
    while (pos < k)
    {
        nextNode = curr->next;
        curr->next = prev;
        prev = curr;
        curr = nextNode;
        pos++;
    }

    Node* recckaAns = NULL;
    if (nextNode != NULL)
    {
        recckaAns = reverseKNodes(nextNode , k , lengthOfLl);
        head->next = recckaAns;
    }

    return prev;    
}

int main()
{
    Node *first = new Node(5);
    Node *second = new Node(15);
    Node *third = new Node(25);
    Node *fourth = new Node(35);
    Node *fifth = new Node(55);
    Node *sixth = new Node(60);
    Node *seventh = new Node(62);
    Node *eighth = new Node(72);

    Node* head = first;
    Node* tail = eighth;

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

    printLlAndGetLength(reverseKNodes(head ,k ,lengthOfLl));

    return 0;
}
