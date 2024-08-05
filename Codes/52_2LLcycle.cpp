// Floyd Cycle detection .

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

Node* floydDetectLoop(Node* head) {

    if(head == NULL)
        return NULL;

    Node* slow = head;
    Node* fast = head;

    while(slow != NULL && fast !=NULL) {
        
        fast = fast -> next;
        if(fast != NULL) {
            fast = fast -> next;
        }

        slow = slow -> next;

        if(slow == fast) {
            cout<<"cycle is present and slow and fasr are meetinga at "<<slow->data;
            cout<<endl;
            return slow;
        }
    }

    return NULL;
}

Node* getStartingNode(Node* head) {

    if(head == NULL) 
        return NULL;

    Node* intersection = floydDetectLoop(head);
    
    if(intersection == NULL)
        return NULL;
    
    Node* slow = head;

    while(slow != intersection) {
        slow = slow -> next;
        intersection = intersection -> next;
    }  

    return slow;
} 

Node *removeLoop(Node *head)
{
    if( head == NULL)
        return NULL;

    Node* startOfLoop = getStartingNode(head);
    
    if(startOfLoop == NULL)
        return head;
    
    Node* temp = startOfLoop;

    while(temp -> next != startOfLoop) {
        temp = temp -> next;
    } 

    temp -> next = NULL;
    return head;
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

if(floydDetectLoop(head) != NULL){
    cout<<"Cycle is present "<<endl;
}
else{
    cout<<"Cycle is not present. "<<endl;
}
Node* startingLoop = getStartingNode(head);

cout<<"Loop is starting from "<<startingLoop->data<<endl;

removeLoop(head);
printLinkedlist(head);

}