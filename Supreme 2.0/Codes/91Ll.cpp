/*
1171. Remove Zero Sum Consecutive Nodes from Linked List

Input : 6->3->5->-8->4->-10->2->20->NULL
Output : 2->20->NULL

*/

#include<iostream>
#include<algorithm>
#include<unordered_map>

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

int printLlAndGetLength(Node *head){           
    Node *temp = head;   

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

// Function to delete the linked list to avoid memory leaks
void deleteLinkedList(Node *&head) {
    Node *current = head;
    while (current != NULL) {
        Node *nextNode = current->next;
        delete current;  
        current = nextNode;
    }
    head = NULL;  
}

void sanitizeMapAndList(Node* curr, unordered_map<int, Node*>&mp, int cSum){
    int temp = cSum;
    Node* it = curr;
    while (true){
        temp += curr->data;
        if (temp == cSum){
            break;
        }
        mp.erase(temp);
        curr = curr->next;
    }
    

    // Node* deleteDestiny = mp[cSum];
    // while (it != deleteDestiny) {
    //     Node *nextNode = it->next;
    //     delete it;  // Free the current node
    //     it = nextNode;
    // }
}

Node* removeZeroSumSublists(Node* head) {
    if((!head) || (!head->next && head->data == 0)) return 0;
    Node* it = head;
    unordered_map<int , Node*>mp;
    int cSum = 0;
    while (it){
        cSum += it->data;
        if(cSum == 0){
            Node* temp = it->next; 
            
            // Node *current = head;
            // while (current != it) {
            //     Node *nextNode = current->next;
            //     delete current;  
            //     current = nextNode;
            // }
            head = temp;
    
            mp.clear();
        }else if(mp.find(cSum) != mp.end()){
            sanitizeMapAndList(mp[cSum]->next, mp, cSum);
            mp[cSum]->next = it->next;
        }
        mp[cSum] = it;
    it = it->next;
    }
return head;    
}

int main(){
    Node *first = new Node(6);
    Node *second = new Node(3);
    Node *third = new Node(5);
    Node *fourth = new Node(-8);
    Node *fifth = new Node(4);
    Node *sixth = new Node(-10);
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
    
    int lengthOfZListAfterZeroSumSublists = printLlAndGetLength(removeZeroSumSublists(head));



    return 0;
}

