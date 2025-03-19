// 328. Odd Even Linked List

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
    cout<<"NULL"<<endl;  
    cout<<"Length of Linked List : "<<length<<endl;  

return length;
}

Node* oddEvenList(Node* head) {
    Node* oddH = head;
    Node* evenH = head->next;
    Node* evenH2 = evenH;

    while (evenH && evenH->next){
        oddH->next = evenH->next;
        evenH->next = evenH->next->next;
        oddH = oddH->next;
        evenH = evenH->next;
    }
    oddH->next = evenH2;
    return head;
}

int main(){
        Node *first = new Node(6);
    Node *second = new Node(3);
    Node *third = new Node(1);
    Node *fourth = new Node(9);
    Node *fifth = new Node(5);
    Node *sixth = new Node(1);
    Node *seventh = new Node(2);
    Node *eighth = new Node(20);

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
    int lengthOfOddEvenLl = printLlAndGetLength(oddEvenList(head));


    return 0;
}