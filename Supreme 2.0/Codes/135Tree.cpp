#include<iostream>
#include<vector>
using namespace std;

// Generic Tree Node
class GTNode {
public:
    int data;
    vector<Node*> children;   // Any number of children

    GTNode(int _data) : data(_data) {}

    ~GTNode() {
        // Recursively delete all children
        for (Node* child : children) {
            delete child;
        }
    }
};

// Binary Tree Node
class Node{
public:
    int data;
    Node* left;
    Node* right;
    Node(int _data){
        this->data = _data;
        this->left = NULL;
        this->right = NULL;
    }
};

Node* createTree(){
    int data;
    cout<<"Enter the value of the node : ";
    cin>>data;
    if (data == -1)
    {
        return NULL;
    }

    Node* root = new Node(data);

    cout<<"Enter left of node "<<root->data<<endl;
    root->left = createTree();

    cout<<"Enter right of node "<<root->data<<endl;
    root->right = createTree();
return root;
}

int main(){
    Node* root = createTree();
    cout<<"The value for root node is : "<<root->data<<endl;

return 0;
}