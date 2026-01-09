// Leetcode 110 : Balanced Binary Tree : According to Leetcode, a balanced binary tree is a binary tree in which the left and right subtrees of every node differ in height by no more than 1.

#include<iostream>
#include<algorithm>

using namespace std;

class Node{
public:
    int data;
    Node* left;
    Node* right;
    Node(int _data) : data(_data), left(NULL), right(NULL) {}
       
    ~Node(){
        delete left;
        delete right;
    }
};

Node* createTree(){
    int data;
    cout<<"Enter the value of the node : ";
    cin>>data;

    // if data is -1 than return null 
    if (data == -1) return NULL;
    

    Node* root = new Node(data);

    cout<<"Enter left of node "<<root->data<<endl;
    root->left = createTree();

    cout<<"Enter right of node "<<root->data<<endl;
    root->right = createTree();
return root;
}


int height(Node* root){
    if (root == nullptr) return 0;

    return max(height(root->left), height(root->right)) + 1;
}

bool isBalancedTree(Node* root){
    if (root == nullptr) return true;
    
    bool isDiffrencce = abs(height(root->left)- height(root->right)) <= 1 ? true : false;
    bool isLeftBalanced = isBalancedTree(root->left); 
    bool isRightBalanced = isBalancedTree(root->right);

return (isDiffrencce && isLeftBalanced && isRightBalanced);
}

int main(){
    Node* root = createTree();
    cout<<"The value for root node is : "<<root->data<<endl;
    if (isBalancedTree(root)){
        cout<<" Binary Tree is balanced."<<endl;
    }
    else{
        cout<<" Binary Tree is not balanced."<<endl;
    }
    

return 0;
}