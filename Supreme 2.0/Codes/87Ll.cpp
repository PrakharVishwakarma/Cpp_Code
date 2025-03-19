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

// Function to delete the linked list to avoid memory leaks
void deleteLinkedList(Node *&head) {
    Node *current = head;
    while (current != NULL) {
        Node *nextNode = current->next;
        delete current;  // Free the current node
        current = nextNode;
    }
    head = NULL;  // Set head to NULL after deletion
}

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

Node* mergeNodes(Node* head) {
    Node* slow = head;
    Node* fast = head->next;
    Node* newLastNode = 0;
    int sum = 0;

    while (fast){
        if(fast->data == 0){
            slow->data = sum;
            newLastNode = slow;
            slow = slow->next;
            sum = 0;
        }else{
            sum += fast->data;
        }
        fast = fast->next;
    }
    
    Node* tmp = slow;
    newLastNode->next = 0;
    while (tmp){
        Node* tmpnxt = tmp->next;
        delete tmp;
        tmp = tmpnxt;
    }
    
return head;
}

int main(){
    Node *first = new Node(0);
    Node *second = new Node(3);
    Node *third = new Node(1);
    Node *fourth = new Node(0);
    Node *fifth = new Node(5);
    Node *sixth = new Node(1);
    Node *seventh = new Node(2);
    Node *eighth = new Node(0);

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
    int lengthOfMergedLl = printLlAndGetLength(mergeNodes(head));
    

    // Delete the linked list to prevent memory leaks
    deleteLinkedList(head);


    return 0;
}