#include<iostream>
#include<map>
using namespace std;

class Node{
public:
    int data;
    Node *next;

    Node(){
        this->next = NULL;
    }

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

// Using Recursion : 
void kthNodeFromLast(Node* temp, int &ans, int &k){
    if(!temp) return;
    kthNodeFromLast(temp->next, ans, k);
    if(k == 0) ans = temp->data;
    k--;
}
// It can be solved using print the (LengthOfLl - k)th Node.

int main (){
    Node* first1  = new Node(5); 
    Node* second1 = new Node(20); 
    Node* third1 = new Node(25); 
    Node* fourth1 = new Node(30); 
    Node* fifth1 = new Node(95);
    Node* sixth1 = new Node(315);
    Node* seventh1 = new Node(5235);

    first1->next = second1;
    second1->next = third1;
    third1->next = fourth1;
    fourth1->next = fifth1;
    fifth1->next = sixth1;
    sixth1->next = seventh1;
    seventh1->next = nullptr;

    Node* head1 = first1;
    Node* tail1 = seventh1;
    int lengthOfLl1 = printLlAndGetLength(head1);

    int k = 3;
 
    Node* temp = head1;
    int ans = 0;
    kthNodeFromLast(temp, ans, k);
    cout<<"Kth Node from the end is : "<<ans;

return 0;
}