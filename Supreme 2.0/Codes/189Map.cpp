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

Node* makeUnion(Node* head1, Node* head2){
    map<int, Node*> map;
    Node* curr = head1;
    while (curr)
    {
        map[curr->data] = curr;
        curr = curr->next;
    }
    curr = head2;
    while (curr)
    {
        map[curr->data] = curr;
        curr = curr->next;
    }
    
    Node* uL = NULL;
    curr = nullptr;
    for(auto it = map.begin(); it!= map.end(); ++it){
        if (uL == nullptr)
        {
            uL = it->second;
            curr = uL;
        }
        else{
            curr->next = it->second;
            curr = curr->next; 
        }
    }
    curr->next = nullptr;
    return uL;
}

int main(){
    Node *first = new Node(9);
    Node *second = new Node(6);
    Node *third = new Node(4);
    Node *fourth = new Node(2);
    Node *fifth = new Node(3);
    Node *sixth = new Node(8);

    Node* head1 = first;
    Node* tail1 = sixth;

    head1->next = second;
    second->next = third;
    third->next = fourth;
    fourth->next = fifth;
    fifth->next = tail1;

    Node *first2 = new Node(1);
    Node *second2 = new Node(2);
    Node *third2 = new Node(8);
    Node *fourth2 = new Node(6);
    Node *fifth2 = new Node(2);

    Node* head2 = first2;
    Node* tail2 = fifth2;

    head2->next = second2;
    second2->next = third2;
    third2->next = fourth2;
    fourth2->next = tail2;

    Node* uL = makeUnion(head1, head2);
    int lengthOfLl = printLlAndGetLength(uL);

return 0;
}