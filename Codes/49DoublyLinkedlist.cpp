#include<iostream>
using namespace std;

class Node {
    public:
    int data;
    Node* prev;
    Node* next;

    //constructor
    Node(int d ) {
        this-> data = d;
        this->prev = NULL;
        this->next = NULL;
    }

    ~Node() {
        int val = this -> data;
        if(next != NULL) {
            delete next;
            next = NULL;
        }
        cout << "memory free for node with data "<< val << endl;
    }
};

//traversing a linked list
void print(Node* head) {
    Node* temp  = head ;

    while(temp != NULL) {
        cout << temp -> data << " ";
        temp  = temp -> next;
    }
    cout << endl;
}

//gives length of Linked List
int getLength(Node* head) {
    int len = 0;
    Node* temp  = head ;

    while(temp != NULL) {
        len++;
        temp  = temp -> next;
    }

    return len;
}
void insertAtHead(Node* &tail, Node* &head, int d) {

    //empty list
    if(head == NULL) {
        Node* temp = new Node(d);
        head = temp;
        tail = temp;
    }
    else{
        Node* temp = new Node(d);
        temp -> next = head;
        head -> prev = temp;
        head = temp;
    }

}


void insertAtTail(Node* &tail,Node* &head, int d) {
    if(tail == NULL) {
        Node* temp = new Node(d);
        tail = temp;
        head = temp;
    }
    else{
        Node* temp = new Node(d);
        tail -> next  = temp;
        temp -> prev = tail;
        tail = temp;
    }

}

void insertAtPosition(Node* & tail, Node* &head, int position, int d) {
    
    //insert at Start
    if(position == 1) {
        insertAtHead(tail,head, d);
        return;
    }

    Node* temp  = head;
    int cnt = 1;

    while(cnt < position-1) {
        temp = temp->next;
        cnt++;
    }

    //inserting at Last Position
    if(temp -> next == NULL) {
        insertAtTail(tail,head,d);
        return ;
    }

    //creating a node for d
    Node* nodeToInsert = new Node(d);

    nodeToInsert ->next = temp -> next;
    temp -> next -> prev = nodeToInsert;
    temp -> next = nodeToInsert;
    nodeToInsert -> prev = temp;
}

void deleteNode(int position, Node* & head) { 

    //deleting first or start node
    if(position == 1) {
        Node* temp = head;
        temp -> next -> prev = NULL;
        head = temp ->next;
        temp -> next = NULL;
        delete temp;
    }
    else
    {
        //deleting any middle node or last node
        Node* curr = head;
        Node* prev = NULL;

        int cnt = 1;
        while(cnt < position) {
            prev = curr;
            curr = curr -> next;
            cnt++;
        }

        curr -> prev = NULL;
        prev -> next = curr -> next;
        curr -> next = NULL;


        delete curr;

    }
}
int main()
{
    Node* head = NULL;
    Node* tail = NULL;

    print(head);
    cout<<"Lenth of linked list is "<<getLength(head)<<endl;

cout<<"Inserting at First *******************************************"<<endl;
    insertAtHead(tail , head , 40);
    print(head);
    cout<<"Lenth of linked list is "<<getLength(head)<<endl;
    insertAtHead(tail , head , 30);
    print(head);
    cout<<"Lenth of linked list is "<<getLength(head)<<endl<<endl;

cout<<"Inserting at Last "<<endl;
    insertAtTail(tail ,head , 50);
    print(head);
    cout<<"Lenth of linked list is "<<getLength(head)<<endl<<endl;
    insertAtTail(tail ,head , 60);
    print(head);
    cout<<"Lenth of linked list is "<<getLength(head)<<endl<<endl;

cout<<"Inserting at any position "<< endl;

    insertAtPosition(tail , head , 3 , 45);
    print(head);
    cout<<"Lenth of linked list is "<<getLength(head)<<endl<<endl;
    insertAtPosition(tail , head , 5 , 55);
    print(head);
    cout<<"Lenth of linked list is "<<getLength(head)<<endl<<endl;
    insertAtPosition(tail , head , 1 , 25);
    print(head);
    cout<<"Lenth of linked list is "<<getLength(head)<<endl<<endl;
    insertAtPosition(tail , head , 8 , 65);
    print(head);
    cout<<"Lenth of linked list is "<<getLength(head)<<endl<<endl;

cout<<"Deleting nodes****************************************************"<< endl;
    deleteNode(1,head);
    print(head);
    cout<<"Lenth of linked list is "<<getLength(head)<<endl<<endl;
    deleteNode(3,head);
    print(head);
    cout<<"Lenth of linked list is "<<getLength(head)<<endl<<endl;
    deleteNode(6,head);
    print(head);
    cout<<"Lenth of linked list is "<<getLength(head)<<endl<<endl;

    return 0;
}