// Doubly Linked List.

#include<iostream>
using namespace std;

class Node{
public:
    int data;
    Node* prev ;
    Node* next ;

    Node(int data){
        this->data = data;
        this->prev = NULL;
        this->next = NULL;
    }
    ~Node(){
        cout<<"Destructor called."<<endl;
    }
};

int printAndGetLength(Node* head){
    Node* temp = head;
    int getLength = 0;
    while (temp != NULL)
    {
        cout<<temp->data<<"->";
        temp = temp->next;
        getLength++;
    }
    cout<<endl<<"Length of the linked list is : "<<getLength<<endl;

    return getLength;
}

void insertAtHead(Node* &head , Node* &tail , int data){
    if (head == nullptr)
    {
        Node* newNode = new Node(data);
        head = newNode;
        tail = newNode;
    }
    else{
        Node* newNode = new Node(data);
        newNode->next = head;
        head->prev = newNode;
        head = newNode;
    }
}

void insertAtTail(Node* &head , Node* &tail , int data){
    if (head == NULL)
    {
        Node* newNode = new Node(data);
        head = newNode;
        tail = newNode;
    }
    else{
        Node* newNode = new Node(data);
        tail->next = newNode;
        newNode->prev = tail;
        tail = newNode;
    }
}

void insertAtPosition(Node* &head , Node* &tail , int data , int position , int length){
    if(position <= 1)
    {
        insertAtHead(head , tail , data);
    }
    else if (position > length)
    {
        insertAtTail(head , tail , data);
    }
    else{
        Node* newNode = new Node(data);
        Node* prevNode = NULL;
        Node* currNode = head;
        while (position != 1)
        {
            position--;
            prevNode = currNode;
            currNode = currNode->next;
        }
        newNode->prev = prevNode;
        prevNode->next = newNode;
        currNode->prev = newNode;
        newNode->next = currNode;
    }
     
}

void deleteNode(Node* &head , Node* &tail, int length ,int position){
    if (head == NULL){
        cout<<"Linked list is empty.";
        return;
    }
    else if (head == tail)
    {
        Node *temp = head;
        delete(temp);
        head = NULL;
        tail = NULL;
    }
    else if (position == 1)
    {
        Node *temp = head;
        head = head->next;
        temp->next = NULL;
        head->prev = NULL;
        delete(temp);
    }
    else if (position == length)
    {
        Node *temp = tail;
        tail = tail->prev;
        tail->next = NULL;
        temp->prev = NULL;
        delete(temp);
    }
    else{
        // Deletion from any position.
        Node* prevNode = NULL;
        Node* currNode = head;
        while (position != 1)
        {
            position--;
            prevNode = currNode;
            currNode = currNode->next;
        }
        Node* nextNode = currNode->next;
        currNode->prev = NULL;
        prevNode->next = nextNode;
        currNode->next = NULL;
        nextNode->prev = prevNode;

        delete(currNode);
    }

}

int main(){
    Node * head = NULL;
    Node * tail= NULL;
    insertAtHead(head , tail , 25);
    insertAtHead(head , tail , 20);
    insertAtHead(head , tail , 15);
    insertAtHead(head , tail , 10);
    insertAtHead(head , tail , 5);
    int lengthOfLl = printAndGetLength(head);

    // Insert at tail :
    insertAtTail(head , tail , 30);
    insertAtTail(head , tail , 35);
    lengthOfLl = printAndGetLength(head);

    // Insert at any postion : 
    insertAtPosition(head , tail , 22 , 5 , lengthOfLl);
    lengthOfLl = printAndGetLength(head);
    
    cout<<"*************************************************"<<endl;
    deleteNode(head ,tail , lengthOfLl, 1);
    lengthOfLl = printAndGetLength(head);
    cout<<endl;
    deleteNode(head ,tail , lengthOfLl, 7);
    lengthOfLl = printAndGetLength(head);
    cout<<endl;
    deleteNode(head ,tail , lengthOfLl, 3);
    lengthOfLl = printAndGetLength(head);
    cout<<endl;
    
return 0;
}

