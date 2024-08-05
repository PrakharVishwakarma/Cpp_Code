// Leetcode : 236. Lowest Common Ancestor of a Binary Tree.

#include<iostream>
using namespace std;


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

Node* lowestCommonAncestor(Node* root, Node* p, Node* q) {
    if (root == NULL)
    {
        return NULL;
    }
    if (root == p)
    {
        return p;
    }
    if (root == q)
    {
        return q;
    }

    Node* leftAns = lowestCommonAncestor(root->left , p , q);    
    Node* rightAns = lowestCommonAncestor(root->right , p , q);   

    if (leftAns == NULL && rightAns == NULL)return NULL;
    if (leftAns != NULL && rightAns == NULL)return leftAns;
    if (rightAns != NULL && leftAns == NULL)return rightAns;
    else return root; 
}

int main(){
    Node* root = createTree();
    cout<<"The value for root node is : "<<root->data<<endl;
    Node* p = root->left;
    Node* q = root->right;
    cout<<"The value of lowest common encestor is : "<<lowestCommonAncestor(root , p , q)->data<<endl;
return 0;
}