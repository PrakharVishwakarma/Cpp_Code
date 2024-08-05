// Leetcode 110 : Balanced Binary Tree : Balanced binary tree ka matlab har node par
// ja kar ke check karna hai left and right subtree ki height ka diffrencce <= 1 hona chaiye

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


int height(Node* root){
    if (root == nullptr)
        return 0;
    
    int leftSubTreeHei = height(root->left);
    int rightSubTreeHei = height(root->right);

return max(leftSubTreeHei, rightSubTreeHei) + 1;
}

bool isBalancedTree(Node* root){
    if (root == nullptr)
        return true;
    
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