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

void solve(Node* head, int &carry){
    if(!head) return;

    solve(head->next, carry);
    int twiceOfNode = 2*(head->data) + carry;
    carry = twiceOfNode/10;
    head->data = twiceOfNode - 10*carry;
}

Node* doubleIt(Node* head) {
    int carry = 0;
    solve(head, carry);
    if(carry != 0){
        Node *newHead = new Node(carry);
        newHead->next = head;
        head = newHead;
    }
    return head;
}


int main(){
    Node *first = new Node(9);
    Node *second = new Node(4);
    Node *third = new Node(1);
    Node *fourth = new Node(9);

    Node* head = first;
    Node* tail = fourth;

    head->next = second;
    second->next = third;
    third->next = fourth;
    fourth->next = NULL;

    int lengthOfLl = printLlAndGetLength(head);
    int lengthOfTwiceLl = printLlAndGetLength(doubleIt(head));
    

    return 0;
}