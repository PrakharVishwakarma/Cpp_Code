// Delete n nodes after m nodes.  matlab m node skip karo then n nodes delete kar do

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

void linkDelete(Node* head, int m , int n){
    if (!head)
    { 
        return;
    }

    Node* it = head;
    for (int i = 0; i < m; ++i)
    {
        if (!it)return;
        it = it->next;
    }

    if (!it)return;
    Node* mthNode = it;
    for (int i = 0; i < n; ++i)
    {
        if (!it)break;;
        Node* temp = it->next;
        delete it;
        it = temp;
    }
    mthNode->next = it;
    linkDelete(it,m,n);

}

int main()
{
    Node *first = new Node(5);
    Node *second = new Node(15);
    Node *third = new Node(25);
    Node *fourth = new Node(75);
    Node *fifth = new Node(85);
    Node *sixth = new Node(45);
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
    int m = 2;
    int n = 1;
    linkDelete(head , m , n);
    printLlAndGetLength(head);
return 0;
}