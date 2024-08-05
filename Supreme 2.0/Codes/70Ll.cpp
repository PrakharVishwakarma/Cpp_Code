// Linkled list creation and Insertion : 

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

void insertAtFirst(Node* &head ,Node* &tail , int data){
    if (head == NULL)
    {
        Node * newNode = new Node(data);
        head = newNode;    
        tail = newNode;
    }
    
    Node * newNode = new Node(data);
    newNode->next = head;
    head = newNode; 

}

void insertAtTail(Node* &head ,Node* &tail , int data){
    if (head == NULL)
    {
        Node * newNode = new Node(data);
        head = newNode;    
        tail = newNode;
    }
    
    Node * newNode = new Node(data);
    tail->next = newNode;
    tail = newNode;
}

void insertAtPosition(Node* &head ,Node* &tail , int data , int &length, int position){
    if (position <= 1)
    {
        insertAtFirst(head , tail , data);   
        return;
    }
    else if (position > length)
    {
        insertAtTail(head , tail , data);  
        return;
    }

    Node *newNode = new Node(data); 
    Node *curr = head;
    Node *prev = NULL;
    while (position != 1)
    {
        prev = curr;
        curr = curr->next;
        position--;
    }
    
    prev->next = newNode;
    newNode->next = curr;
    
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
        delete(temp);
    }
    
    else if (position == length)
    {
        Node *prev = head;
        while (prev->next != tail)
        {
            prev = prev->next;
        }

        prev->next = NULL;
        delete(tail);
        tail = prev; 
    }
    
    else{
    Node *curr = head;
    Node *prev = NULL;
    while (position != 1)
    {
        prev = curr;
        curr = curr->next;
        position--;
    }
    prev->next = curr->next;
    curr->next = NULL;
    delete(curr);

    }
    
}

int main(){
    Node *first = new Node(5);
    Node *second = new Node(15);
    Node *third = new Node(25);
    Node *fourth = new Node(35);
    Node *fifth = new Node(45);

    Node* head = first;
    Node* tail = fifth;

    head->next = second;
    second->next = third;
    third->next = fourth;
    fourth->next = tail;
    
    int lengthOfLl = printLlAndGetLength(head);

    // Insert at first in Linked List : 
    cout<<"After inserting at first : ";
    insertAtFirst(head , tail , 2);
    lengthOfLl = printLlAndGetLength(head);

    // Insert at last in the linked list : 
    cout<<"After inserting at Last : ";
    insertAtTail(head,tail,50);
    lengthOfLl = printLlAndGetLength(head);

    //Insert at position;
    cout<<"After inserting at postion : ";
    insertAtPosition(head ,tail , 20 , lengthOfLl, 4);
    lengthOfLl = printLlAndGetLength(head);

    cout<<"******************************************************************************"<<endl;

    // Deletion of Node in Linked List : 
    deleteNode(head ,tail , lengthOfLl, 1);
    lengthOfLl = printLlAndGetLength(head);
    cout<<endl;
    deleteNode(head ,tail , lengthOfLl, 7);
    lengthOfLl = printLlAndGetLength(head);
    cout<<endl;
    deleteNode(head ,tail , lengthOfLl, 3);
    lengthOfLl = printLlAndGetLength(head);
    cout<<endl;
    

    return 0;
}

// ?
// Use case of linked list.
// Make sure All Test cases of question from linked list must be pass in online interview. 


