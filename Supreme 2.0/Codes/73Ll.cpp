// Leetcode 876 Find middle of the linked list.

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

Node* middleNodeIteratively(Node* head , int length){
    Node* temp = head;
    int position = (length/2)+1;

    while(position != 1){
        position--;
        temp = temp->next;
    }
    return temp;
}

// Find middle using Tortoise Algorithms : 
/*
Node* middleNodeTortoise(Node* head , int length){
    Node* slow = head;
    Node* fast = head;
    while (fast != NULL)
    {
    fast = fast->next;
        if (fast != NULL)
        {
            fast = fast->next;
            slow = slow->next;
        }
    }
    return slow;
}
// note: slow ptr tabhi 1 step aage badega jab fast 2 step aage bad raha ho
*/
Node* middleNodeTortoise(Node* head , int length){
    Node* slow = head;
    Node* fast = head;
    // while (fast != NULL)     //when postion of middle is controversial. 
    while (fast->next != NULL)
    {
    fast = fast->next;
        if (fast->next != NULL)
        {
            fast = fast->next;
            slow = slow->next;
        }
    }
    return slow;
}
Node* reverseLlRecursively(Node* currPrev, Node* curr){
    if (curr == NULL)
    {
        return currPrev;
    }
    Node *currNext = curr->next;
    curr->next = currPrev;
    currPrev = curr;
    curr = currNext;   

    return reverseLlRecursively(currPrev , curr);   
}

bool IsPallindrome(Node* head , Node* midNode){
    Node *head2 = midNode->next;
    midNode->next = NULL;
    printLlAndGetLength(head);
    // Now the linked list has devided into two diffrent parts then Reverse either first or second part. 
    Node* prev = NULL;
    Node* curr = head2;
    head2 = reverseLlRecursively(prev , head2); 
    printLlAndGetLength(head2);
    
    // Compare the elements :  
    // 2 case banenge ek same-same length ki list and dusra different length ki list  
    while (head2 != NULL ) // Kyunki head kabhi null par aayega hi nii isliye hum only (head2!= NULL) check kar rahe hain. Although kar ye bhi sakte hain : (head != NULL && head2 != NULL )
    {
        if (head->data != head2->data)
        {
            return false;
        }
        else{
            head = head->next;
            head2 = head2->next;
        }
    }
    return true;

}

int main(){
    Node *first = new Node(5);
    Node *second = new Node(15);
    Node *third = new Node(25);
    Node *fourth = new Node(25);
    Node *fifth = new Node(15);
    Node *sixth = new Node(5);

    Node* head = first;
    Node* tail = sixth;

    head->next = second;
    second->next = third;
    third->next = fourth;
    fourth->next = fifth;
    fifth->next = tail;

    int lengthOfLl = printLlAndGetLength(head);
    cout<<"Middle Node of linked list is : "<<(middleNodeIteratively(head , lengthOfLl))->data<<endl;

    Node* midNode = middleNodeTortoise(head , lengthOfLl);
    cout<<"Middle Node of linked list is using totoise algorithm : "<<midNode->data<<endl;

    // Leetcode 234 : Check Pallindrome.
    if (IsPallindrome(head , midNode))
    {
        cout<<"Valid pallindrome."<<endl;
    }
    else {
        cout<<"Invalid pallindrome."<<endl;
    }
return 0;
}