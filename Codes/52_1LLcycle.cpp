#include<iostream>
#include<map>
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

void insertAtTail(Node* &tail , int data){
    Node* temp = new Node(data);
    tail->next = temp;
    tail = temp; 

}

void printLinkedlist(Node* &head){

    Node* temp = head;
    while(temp != NULL){
        cout<<temp->data<<" ";
        temp = temp->next;
    }
    cout<<endl;
}

bool detectLoop(Node* head){
    if (head == NULL){
        return false;
    }

    map<Node* , bool>visited;
    Node* temp = head;

    while (temp != NULL)
    {
        if(visited[temp]==true){
            cout<<"Cycle is present on elmemnt "<<temp->data<<endl;
            return true;
        }
        visited[temp] = true;
        temp = temp->next;
    }
return false;

}

int main(){

Node* node1 = new Node(10);
Node* head = node1;


Node* tail = head; // Initialy.
insertAtTail(tail , 15);
insertAtTail(tail , 20);
insertAtTail(tail , 25);
insertAtTail(tail , 30);
insertAtTail(tail , 35);
cout<<endl;
cout<<"head ka data "<<head->data<<endl;
cout<<"tail ka data "<<tail->data<<endl;
cout<<"node1 ka data "<<node1->data<<endl<<endl;
printLinkedlist(head);
tail->next = head -> next;

cout<<"head ka data "<<head->data<<endl;
cout<<"tail ka data "<<tail->data<<endl;
cout<<"node1 ka data "<<node1->data<<endl<<endl;

if(detectLoop(head)){
    cout<<"cycle is present in the linked list";
}

}
