// Add 1 in the linked list :
// linked list : 9->9->9  :  + 1  :  1->0->0->0  shuld be the output.

#include<iostream>
using namespace std;

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

Node* reverseLlIteratively(Node* head){
    Node* currPrev = NULL;
    Node* curr = head;
    while(curr != NULL)
    {
        Node *currNext = curr->next;
        curr->next = currPrev;
        currPrev = curr;
        curr = currNext;
    }
    return currPrev;
}

void plusOne(Node* &head){
    head = reverseLlIteratively(head);
    printLlAndGetLength(head);
    int carry = 1;     
    Node* temp = head;
    while(temp->next != NULL)
    {
        int totalSum = temp->data + carry;
        int digit = totalSum % 10;
        carry = totalSum / 10;
        temp->data = digit;
          
        temp = temp->next;
        if (carry == 0)break;
    }
    if (carry != 0)
    {
        int totalSum = temp->data + carry;
        int digit = totalSum % 10;
        carry = totalSum / 10;
        temp->data = digit;

        if (carry != 0)
        {
            Node* newNode = new Node(carry);
            temp->next = newNode;
        } 
    }
    
    head = reverseLlIteratively(head);
    printLlAndGetLength(head);
}

int main(){

    Node *first = new Node(9);
    Node *second = new Node(9);
    Node *third = new Node(9);
    Node *fourth = new Node(9);

    Node* head = first;
    Node* tail = fourth;

    head->next = second;
    second->next = third;
    third->next = fourth;
    fourth->next = NULL; 

    int lengthOfLl = printLlAndGetLength(head);
    plusOne(head);

return 0;
}