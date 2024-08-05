// Leetcode 112. Path Sum : Given the root of a binary tree and an integer targetSum, return true if the tree has a root-to-leaf path such that adding up all the values along the path equals targetSum.


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

bool solve(Node* root, int targetSum, int sum){
    if (root == NULL)
        return false;
        
    sum += root->data;
    if (root->left == NULL && root->right == NULL)
    {
        if(sum == targetSum)return true;
        else return false;
    }
    
    bool leftKaAns = solve(root->left , targetSum , sum);
    bool rightKaAns = solve(root->right , targetSum , sum);

return leftKaAns||rightKaAns;
}

bool hasPathSum(Node* root, int targetSum) {
    int sum = 0;
    return solve(root, targetSum , sum);
}

int main(){
    Node* root = createTree();
    cout<<"The value for root node is : "<<root->data<<endl;
    if (hasPathSum(root , 22))cout<<"Target sum Confirmed"<<endl;
    else cout<<"Target Sum does not match."<<endl;
    
return 0;
}