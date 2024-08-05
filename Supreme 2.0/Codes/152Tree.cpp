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

pair<int, int> getMaxSum_helper(Node* root){
    if (root == NULL)
    {
        return {0,0}
    }
    auto left = getMaxSum_helper(root->left);
    auto right = getMaxSum_helper(root->right);
    
    int a = root->data + left.second + right.second;

    int b = max(left.first, left.second) + max(left.second , right.second);
    return {a,b};
}

int getMaxSum(Node* root){
    auto ans = getMaxSum_helper(root);
    return max(ans.first, ans.second);
}

int main(){
    Node* root = createTree();
    cout<<"The value for root node is : "<<root->data<<endl;

return 0;
}
