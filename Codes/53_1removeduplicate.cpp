// Remove duplicates from sorted array.

#include<iostream>
using namespace std;

class Node 
    {
        public:
        int data;
        Node* next;
        Node(int data) 
        {
            this->data = data;
            this->next = NULL;
        }
};

Node * uniqueSortedList(Node * head) {
   	//empty List
    if(head == NULL)
        return NULL;
    
    //non empty list
    Node* curr = head;
    
    while(curr != NULL) {
        
        if( (curr -> next != NULL) && curr -> data == curr -> next -> data) {
            Node* next_next = curr ->next -> next;
            Node* nodeToDelete = curr -> next;
            delete(nodeToDelete);
            curr -> next = next_next;
        }
        else //not equal
        {
            curr = curr -> next;
        }   
    }
return head; 

}

// Remove duplicates from unsorted array.




