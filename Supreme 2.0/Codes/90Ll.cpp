#include<iostream>
#include<algorithm>

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


Node* swapNodes(Node* head, int &k, int &len) {
    if(!head || !head->next)return head;

    int lpos = k;
    int rpos = len - k + 1;

    if(lpos > rpos) swap(lpos, rpos);

    if(lpos == rpos) return head;

    if(len == 2){
        Node* newHead = head->next;
        newHead->next = head;
        head->next = NULL;
        head = newHead; 
        return head;
    }

    if(lpos == 1){
        Node* ln = head;
        Node* rp = head;
        for (int i = 0; i < rpos-2; i++)rp = rp->next;
        Node* rn = rp->next;

        rn->next = ln->next;
        rp->next = ln;
        ln->next = NULL;
        head = rn;
        return head;  
    }

    if(rpos-lpos-1 == 0){
        Node* lp = head;
        for (int i = 0; i < lpos-2; i++)lp = lp->next;
        Node* ln = lp->next;
        Node* rp = head;
        for (int i = 0; i < rpos-2; i++)rp = rp->next;
        Node* rn = rp->next;
        Node* rSave = rn->next;

        lp->next = rp->next;
        rn->next = rp;
        rp->next = rSave;
        return head; 
    }else{
        Node* lp = head;
        for (int i = 0; i < lpos-2; i++)lp = lp->next;
        Node* ln = lp->next;
        Node* rp = head;
        for (int i = 0; i < rpos-2; i++)rp = rp->next;
        Node* rn = rp->next;
        Node* rSave = rn->next;

        lp->next = rn;
        rn->next = ln->next;
        rp->next = ln;
        ln->next = rSave;
        return head;
    } 

}

int main(){
        Node *first = new Node(6);
    Node *second = new Node(3);
    Node *third = new Node(5);
    Node *fourth = new Node(9);
    Node *fifth = new Node(5);
    Node *sixth = new Node(4);
    Node *seventh = new Node(2);
    Node *eighth = new Node(20);

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
    
    int k = 3;
    int lengthOfSwapedLl = printLlAndGetLength(swapNodes(head, k, lengthOfLl));

    return 0;
}