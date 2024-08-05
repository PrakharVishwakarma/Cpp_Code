// Transform to sum tree.

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

void levelOrderTraversalBfs(Node* root){
    queue<Node* >q;
    q.push(root);
    q.push(NULL);
    while (!q.empty())
    {
        Node* front = q.front();
        q.pop(); 
        if (front == NULL)
        {
            cout<<endl;
            if (!q.empty())
            {
                q.push(NULL);
            }
        }
        
        else{
            cout<<front->data<<" ";
            if (front->left)
            {
                q.push(front->left); 
            }
            
            if (front->right != NULL)
            {
                q.push(front->right); 
            }
        }
    } 
}

int sum(Node* root){
    if (!root) return 0;
    if (!root->left && !root->right)
    {
        int temp = root->data;
        root->data = 0;
        return temp;
    }
    int lSum = sum(root->left);
    int rSum = sum(root->right);
    int temp = root->data;

    root->data = lSum + rSum;
    return root->data + temp;
}

int main(){
    Node* root = createTree();
    cout<<"Level Order traversal (BFS) for the tree is : "<<endl;
    levelOrderTraversalBfs(root);cout<<endl;
    cout<<sum(root);
return 0;    
}