// Leetcode 437 : Pathsum 3
#include<iostream>
#include<queue>
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

int ans = 0;
void pathFromOneRoot(Node* root, long long sum){
    if (!root)
        return;
    if (sum == root->data) ++ans;
    pathFromOneRoot(root->left, sum-root->data);
    pathFromOneRoot(root->right, sum-root->data);   
}

int pathSum(Node* root, long long pathSum){
    if (root)
    {
        pathFromOneRoot(root , pathSum);
        pathFromOneRoot(root->left , pathSum);
        pathFromOneRoot(root->right , pathSum);
    }
    return ans;
}

int main(){
    Node* root = createTree();
    cout<<"The value for root node is : "<<root->data<<endl;
    cout<<pathSum(root,8);
return 0;
}