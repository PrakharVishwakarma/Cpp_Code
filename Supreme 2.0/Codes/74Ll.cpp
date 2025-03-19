// Detect cycle in a linked list : 

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


// Using map: 
bool hasCycle(Node* head){
    map<Node* , bool>table;     
    Node* temp = head;
    while (temp != NULL)
    {
        if (table[temp] == false)
        {
            table[temp] = true;
        }
        else{
            return true;
        }  
        temp = temp->next;
    }
    return false;   
}

// Using Slow fast(tortoise algorithms)
bool hasCycleTortoise(Node* &head){
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
        if (fast == slow)
        {
            return true;
        }
    }

return false;
}

Node* findStartOfLoop(Node* &head){
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
        if (fast == slow)
        {
            break;
        }
    }
    slow = head;
    while (fast != slow) 
    {
        slow = slow->next;
        fast = fast->next;
    }

    return slow; // or return fast;
}

void removeLoop(Node* head){
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
        if (fast == slow)
        {
            break;
        }
    }
    slow = head;
    Node* temp = fast;      // for keeping track of fast:
    while (fast != slow)
    {
        slow = slow->next;
        fast = fast->next;
    }

    Node* startPoint = slow;

    while (temp->next != startPoint)
    {
        temp = temp->next;
    }
    temp->next = NULL;
    /*Logic is since we have starting point of cycle, toh ek pointer starting of loop pe rakho(startPoint) and dusre pointer(temp) ko starting of cycle se le tab tak traverse karao jab tak temp-> next!=startpoint of loop. once we got it then temp->next == NULL */
}

int main(){
    Node *first = new Node(5);
    Node *second = new Node(15);
    Node *third = new Node(25);
    Node *fourth = new Node(35);
    Node *fifth = new Node(45);
    Node *sixth = new Node(50);

    Node* head = first;
    Node* tail = sixth;

    head->next = second;
    second->next = third;
    third->next = fourth;
    fourth->next = fifth;  // Cycle Present
    fifth->next = sixth;
    sixth->next = second;

    // int lengthOfLl = printLlAndGetLength(head);
    // if(hasCycle(head))
    // {
    //     cout<<"Cyclle is detected in the linked list."<<endl;
    // }
    // else{
    //     cout<<" NO Cyclle is detected in the linked list."<<endl;
    // }

    if(hasCycleTortoise(head))
    {
        cout<<"Cycle is detected in the linked list."<<endl;
    }
    else{
        cout<<" NO... Cycle is detected in the linked list."<<endl;
    }
    
    // Find the starting point of the loop in the linked list.
    cout<<"Starting point of the cycle is : "<<findStartOfLoop(head)->data<<endl;

    // Removal of cycle.
    cout<<"After removing the cycle from linked list, ";
    removeLoop(head);
    int lengthOfLl = printLlAndGetLength(head);

return 0;
}