// Check the Given Binary tree is a max heap.
// Preorder Traversal : 
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
            
            if (front->right)
            {
                q.push(front->right); 
            }
        }
    }
    
}

int nodeCount(Node* root){
    if (!root)return 0;
    int leftSideNodeCount = nodeCount(root->left);
    int rightSideNodeCount = nodeCount(root->right);
return 1+leftSideNodeCount+rightSideNodeCount;
}
bool isCbt(Node* root, int i, int &n){
    if (!root) return true;
    if (i>n) return false;
    return isCbt(root->left, 2*i, n) && isCbt(root->right, 2*i+1 , n);
}
bool isMaxProperty(Node* root){
    if(!root) return true;
    int l = isMaxProperty(root->left);
    int r = isMaxProperty(root->right);
    int ans = false;
    if(!root->left && !root->right) ans = true; 
    else if(root->left && !root->right) ans = root->data > root->left->data;
    else ans = root->data > root->left->data && root->data > root->right->data;

return ans;
}
bool isMaxHeap(Node* root){
    int n = nodeCount(root);
    int i = 1;
    return isCbt(root, i, n) && isMaxProperty(root);
}
int main(){
    Node* root = createTree();
    cout<<"The value for root node is : "<<root->data<<endl;

    cout<<"Level Order traversal (BFS) for the tree is : "<<endl;
    levelOrderTraversalBfs(root);cout<<endl;
    if (isMaxHeap(root))
    {
        cout<<"The tree follows Max Heap Order."<<endl;
    }
    else cout<<"The tree does not follow Max Heap Order."<<endl;
    
    
return 0;
}