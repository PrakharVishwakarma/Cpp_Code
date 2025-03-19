// Flattening a Linked List : Flatten the Link List so all the nodes appear in a single level while maintaining the sorted order.

/*
    5 -> 10 -> 19 -> 28->
    |    |     |     |
    7    20    22    35     
    |          |     |
    8          50    40    
    |                |   
    30               45
*/

#include<iostream>
using namespace std;

class Node{
public:
    int data;
    Node *next;
    Node *bottom;

    Node(int data){
        this->data = data;
        this->next = NULL;
        this->bottom = NULL;
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

Node* merge(Node* a, Node* b){
    if(!a) return b;
    if (!b) return a;

    Node* ans = 0;
    if(a->data <= b->data){
        ans = a;
        a->bottom = merge(a->bottom, b);
    }else{
        ans = b;
        b->bottom = merge(a, b->bottom);
    }
    return ans;
}

Node* flatten(Node* root){
    if(!root) return 0;

    Node* mergedLl = merge(root, flatten(root->next));

    return mergedLl;
}

int main(){
    Node *first1 = new Node(5);
    Node *second1 = new Node(7);
    Node *third1 = new Node(8);
    Node *fourth1 = new Node(30);

    Node* head1 = first1;
    Node* tail1 = fourth1;

    head1->bottom = second1;
    second1->bottom = third1;
    third1->bottom = fourth1;
    fourth1->bottom = NULL;


    Node *first2 = new Node(10);
    Node *second2 = new Node(20);

    Node* head2 = first2;
    Node* tail2 = second2;

    head2->bottom = second2;
    second2->bottom = NULL;

    head1->next = head2;


    Node *first3 = new Node(19);
    Node *second3 = new Node(22);
    Node* third3 = new Node(50);

    Node* head3 = first3;
    Node* tail3 = third3;

    head3->bottom = second3;
    second3->bottom = third3;
    third3->bottom = NULL;

    head2->next = head3;


    Node *first4 = new Node(28);
    Node *second4 = new Node(35);
    Node *third4 = new Node(40);
    Node *fourth4 = new Node(45);

    Node* head4 = first4;
    Node* tail4 = fourth4;

    head4->bottom = second4;
    second4->bottom = third4;
    third4->bottom = fourth4;
    fourth4->bottom = NULL;

    head3->next = head4;

    int mainListlength = printLlAndGetLength(head1);

    Node* flattenLlHead = flatten(head1);

    Node* temp = head1;
    while(temp){
        cout<<temp->data<<"->";
        temp = temp->bottom;
    }cout<<endl;
    

    return 0;
}