#include<iostream>
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

Node* getIntersectionNode(Node* head1, Node* head2){
    Node* headA = head1;
    Node *headB = head2;

    while(headA->next && headB->next){
        if(headA==headB)return headA;
        headA = headA->next;
        headB = headB->next;
    }

    if(!headA->next){
        int howMuchBIsBigger = 0;
        while (headB->next){
            howMuchBIsBigger++;
            headB = headB->next;
        }
        while (howMuchBIsBigger--){
            head2 = head2->next;
        }
    }
    else {
        int howMuchAIsBigger = 0;
        while (headA->next){
            howMuchAIsBigger++;
            headA = headA->next;
        }
        while (howMuchAIsBigger--){
            head1 = head1->next;
        }
    }
    while (head1 != head2){
        head1 = head1->next;
        head2 = head2->next;
    }
    return head1;
    
}


int main(){
    Node* first1  = new Node(5); 
    Node* second1 = new Node(20); 
    Node* third1 = new Node(25); 
    Node* fourth1 = new Node(30); 
    Node* fifth1 = new Node(65);
    Node* sixth1 = new Node(70);

    first1->next = second1;
    second1->next = third1;
    third1->next = fourth1;
    fourth1->next = fifth1;
    fifth1->next = sixth1;
    sixth1->next = NULL;

    Node* head1 = first1;
    int lengthOfLl1 = printLlAndGetLength(head1);

    Node* first2  = new Node(10); 
    Node* second2 = new Node(15); 
    Node* third2 = new Node(40); 

    first2->next = second2;
    second2->next = third2;
    third2->next = second1;

    Node* head2 = first2;
    int lengthOfLl2 = printLlAndGetLength(head2);

    Node* headOf1 = head1;
    Node* headOf2 = head2;
    
    Node* intersectioNode = getIntersectionNode(headOf1, headOf2);
    cout<<"The intersection node is : "<<intersectioNode->data;
return 0;
}