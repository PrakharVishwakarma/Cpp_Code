// 138. Copy List with Random Pointer

#include <iostream>
#include <unordered_map>

using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node *random;

    Node(int data)
    {
        this->data = data;
        this->next = NULL;
        this->random = NULL;
    }

    ~Node()
    {
        cout << "Destructor called for " << this->data << endl;
    }
};

int printLlAndGetLength(Node *head){                       // Node pass by refrence.
    Node *temp = head;  // Acchi Practice : 

    cout<<"Printing the Linked List : ";
    int length = 0;
    while (temp != NULL)
    {
        cout<<temp->data;
        if(temp->random)cout<<" (random: "<<temp->random->data<<")";
        cout<<"->";
        temp = temp->next;
        length++;
    }
    cout<<endl;  
    cout<<"Length of Linked List : "<<length<<endl;  

return length;
}


Node* helper(Node* head, unordered_map<Node*, Node*>&mp){
    if(!head)return 0;

    Node* newHead = new Node(head->data);
    mp[head] = newHead;
    newHead->next = helper(head->next, mp);

    if(head->random) newHead->random = mp[head->random];

    return newHead;
}

Node *copyRandomList(Node *head){
    unordered_map<Node*, Node*> mp;
    return helper(head, mp);
}


Node* copyRandomList2(Node* head){
    if(!head) return 0;

    Node* it = head;
    while (it){
        Node* clonedNode = new Node(it->data);
        clonedNode->next = it->next;
        it->next = clonedNode;
        it = it->next->next;
    }

    it = head;
    while (it){
        if(it->random) it->next->random = it->random->next;
        it = it->next->next;
    }

    it = head;
    Node* clonedNode = it->next;
    while (it)
    {
        Node* clonedNode = it->next;
        it->next = it->next->next;
        if(clonedNode->next) clonedNode->next = clonedNode->next->next;
        it = it->next;
    }
    
    return clonedNode;    
    
}

int main()
{
    Node *first = new Node(7);
    Node *second = new Node(13);
    Node *third = new Node(11);
    Node *fourth = new Node(10);
    Node *fifth = new Node(1);

    Node *head = first;
    Node *tail = fifth;

    head->next = second;
    second->next = third;
    second->random = first;
    third->next = fourth;
    third->random = fifth;
    fourth->next = fifth;
    fourth->random = third;
    fifth->next = NULL;
    fifth->random = first;

    int lengthOfLl = printLlAndGetLength(head);

    int lengthOfDeepCopiedLl = printLlAndGetLength(copyRandomList(head));

    int lengthOfDeepCopiedLl2 = printLlAndGetLength(copyRandomList2(head));

    return 0;
}