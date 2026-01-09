// Leetcode 100 : Same Tree 

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

// Leetcode 100 : Same Tree: 
bool isSameTree(Node* root1 , Node* root2){
    if(!root1 && !root2)return true;

    if(root1 && root2)
        return (root1->data == root2->data) && isSameTree(root1->left,root2->left)&&isSameTree(root1->right,root2->right);
    
return false; 
}

// Leetcode 101 : Symmetric Tree:
bool isATreeMirror(Node* root1 , Node* root2){
    if(!root1 && !root2)return true;

    if(root1 && root2)
        return (root1->data == root2->data) && isSameTree(root1->left,root2->right)&&isSameTree(root1->right,root2->left);
    
return false; 
}

int main(){
    Node* root1 = createTree();
    cout<<"The value for root node for first tree is : "<<root1->data<<endl;
    Node* root2 = createTree();
    cout<<"The value for root node for second tree is : "<<root2->data<<endl;
    if (isSameTree(root1 ,root2))
    {
        cout<<"Both th binary tree are same."<<endl;
    }
    else{
        cout<<"Both th binary tree are not same."<<endl;
    }
    Node* root3 = createTree();
    cout<<"The value for root node for second tree is : "<<root2->data<<endl;
    if (isSameTree(root3->left ,root3->right))
    {
        cout<<"Binary tree is mirror Symmetric."<<endl;
    }
    else{
        cout<<"Binary tree is not mirror Symmetric."<<endl;
    }
    
return 0;
}
