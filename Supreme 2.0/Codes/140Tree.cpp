/* Leetcode : 113. Path Sum II
Given the root of a binary tree and an integer targetSum, return all root-to-leaf paths where the sum of the node values in the path equals targetSum. Each path should be returned as a list of the node values, not node references. */

#include<iostream>
#include<vector>
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

void solve(Node* root, int targetSum ,int sum, vector<int>temp, vector<vector<int>> &ans) {
    if (root == NULL) return;

    sum += root->data;
    temp.push_back(root->data);

    if (root->left == NULL && root->right == NULL)
    {
        if(sum == targetSum)ans.push_back(temp);
        else return;
        /*
        only when ans is passed by reference 
        else {
            temp.pop_back();
            return;
        };
        */
    }
    solve (root->left , targetSum , sum , temp , ans);
    solve (root->right , targetSum , sum , temp , ans);  

    // temp.pop_back(); // only when ans is passed by reference
}

vector<vector<int>> pathSum(Node* root, int targetSum) {
    int sum = 0;
    vector<vector<int>> ans;
    vector<int>temp;
    solve (root , targetSum , sum , temp , ans);
return ans;
}

int main(){
    Node* root = createTree();
    cout<<"The value for root node is : "<<root->data<<endl;

return 0;
}

// HomeWork : Kth Ancestor of node in Binary Tree.