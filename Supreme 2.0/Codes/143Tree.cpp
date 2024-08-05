

#include<iostream>
#include<algorithm>
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

// Fast way to find the diameter of the tree
int diaMeter = 0;

int height(Node* root){
    if (root == NULL)
        return 0;
    
    int lH = height(root->left);
    int rH = height(root->right);

    int currDiaMeter = lH + rH;
    diaMeter = max(currDiaMeter , diaMeter);
    
    return max(lH, rH) + 1;
}

int findDiameter(Node* root){
    height(root);
    return diaMeter;
}

// Fast way to find the Height Balanced Tree:
bool isBalanced = true;
int height2(Node* root){
    if (!root)
        return 0;
    
    int lH = height2(root->left);
    int rH = height2(root->right);
    
    if (isBalanced && abs(lH-rH) > 1)isBalanced = false;
    

    return max(lH , rH) + 1;
}

bool isBalancedTree(Node* root){
    height(root);
    return isBalanced;
}
int main(){
    Node* root = createTree();
    cout<<"The value for root node is : "<<root->data<<endl;
    cout<<"Diameter of the tree is "<<findDiameter(root)<<endl;
    if(isBalancedTree(root)){
        cout<<"Binary Tree is balanced."<<endl;
    }
    else{
        cout<<"Binary tree is not balanced."<<endl;
    }
return 0;
}