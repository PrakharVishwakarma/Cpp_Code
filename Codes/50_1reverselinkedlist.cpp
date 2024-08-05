#include<iostream>
using namespace std;

class Node
    {
    public:
        int data;
        Node *next;
        Node(int data)
        {
            this->data = data;
            this->next = NULL;
        }
    };

void printLinkedlist(Node* &head){

    Node* temp = head;
    while(temp != NULL){
        cout<<temp->data<<" ";
        temp = temp->next;
    }
    cout<<endl;
} 

Node* reverseLikedlist(Node* head) {
    //base call
    if(head == NULL) {
        return head;
    }
    Node *prev = NULL;
    Node *curr = head;
    Node *forward = NULL;
    while( curr != NULL ) {
        forward = curr -> next;
        curr -> next = prev;
        prev = curr;
        curr = forward;
    }
}

int main()
{

Node* head = NULL ; 

Node* node1 = new Node(10);
Node* node2 = new Node(20);
node1 -> next = node2;

Node* node3 = new Node(30);
node2 -> next = node3;
Node* node4 = new Node(40);
node3 -> next = node4;
Node* node5 = new Node(50);
node4 -> next = node5;
node5 -> next = NULL;

head = node1;

printLinkedlist(head);


}
