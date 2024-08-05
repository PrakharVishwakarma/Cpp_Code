#include<iostream>
#include <bits/stdc++.h>



using namespace std;

struct Node
{
    int data;
    Node* next;
    Node* random;
    Node (int x){
        data = x;
        next = NULL;
        random = NULL;
    }
};

class solution
{
    private:
        void insertAtTail(Node* &head , Node* &tail, int data){
        Node* newNode = new Node(data);
        if(head == NULL){
        head = newNode;
        tail = newNode;
        return;
        }

        else{
            tail->next = newNode;
            tail = newNode;
        }
        }

    public:
    Node*copyList(Node*head){

        // Create a closne list first :
        Node* cloneHead = NULL;
        Node* cloneTail = NULL;

        Node *temp = head;
        while(temp != NULL){
            insertAtTail(cloneHead , cloneTail , temp->data);
            temp = temp->next;
        }

        //Step 2 : creat the map.

        map<Node* ,Node*>oldToNewNode;

        Node* originalNode = head;
        Node* cloneNode = cloneHead;
        while(originalNode != NULL && cloneNode != NULL){
            oldToNewNode[originalNode] = cloneNode;
            originalNode = originalNode->next;
            cloneNode = cloneNode->next;
        }

        originalNode = head;
        cloneNode = cloneHead;   
    while(originalNode != NULL){
        cloneNode -> random = oldToNewNode[originalNode -> random];
        originalNode = originalNode->next;
        cloneNode = cloneNode ->next;
    }
    return cloneHead;
    }
};
int main(){


}


