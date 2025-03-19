// Merge two sorted Linked List
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

Node* mergetwolist(Node* left, Node* right){
    if(left == 0)return right;
    if(right == 0)return left;

    Node* ans = new Node(-1);
    Node* mptr = ans;

    while (left && right){
        if(left->data <= right->data){
            mptr->next = left;
            mptr = left;
            left = left->next;
        }
        else{
            mptr->next = right;
            mptr = right;
            right = right->next;
        }
    }
    if(left){
        mptr->next = left;
    }
    if(right){
        mptr->next = right;
    }
    
return ans->next;
}

int main (){
    Node* first1  = new Node(5); 
    Node* second1 = new Node(20); 
    Node* third1 = new Node(25); 
    Node* fourth1 = new Node(30); 
    Node* fifth1 = new Node(65);

    first1->next = second1;
    second1->next = third1;
    third1->next = fourth1;
    fourth1->next = fifth1;
    fifth1->next = NULL;

    Node* head1 = first1;
    Node* tail1 = fifth1;
    int lengthOfLl1 = printLlAndGetLength(head1);

    Node* first2  = new Node(10); 
    Node* second2 = new Node(15); 
    Node* third2 = new Node(40); 
    Node* fourth2 = new Node(50); 
    Node* fifth2 = new Node(55);
    Node* sixth2 = new Node(70);

    first2->next = second2;
    second2->next = third2;
    third2->next = fourth2;
    fourth2->next = fifth2;
    fifth2->next = sixth2;
    sixth2->next = NULL;

    Node* head2 = first2;
    Node* tail2 = sixth2;

    cout<<endl<<fifth1->data<<" "<<sixth2->data<<endl;

    int lengthOfLl2 = printLlAndGetLength(head2);
    cout<<"After merging both the Ll : ";

    Node* headOfLlMerged = mergetwolist(head1, head2);
    
    int lengthOfLlMerged = printLlAndGetLength(headOfLlMerged);
    return 0;
}