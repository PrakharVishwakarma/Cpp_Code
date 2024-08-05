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

void preOrder(Node* root){
    // Base case : 
    if (root == NULL)return;

    //ek case : (N)
    cout<<root->data<<" ";
    // left : (L)
    preOrder(root->left);
    // Right : (R)
    preOrder(root->right);
}

void inOrder(Node* root){
    // Base case : 
    if (root == NULL)return;

    // left : (L)
    inOrder(root->left);
    // (N)
    cout<<root->data<<" ";
    // Right : (R)
    inOrder(root->right);
}
void postOrder(Node* root){
    // Base case : 
    if (root == NULL)return;

    // (N)
    cout<<root->data<<" ";
    // Right : (R)
    postOrder(root->right);
    // left : (L)
    postOrder(root->left);
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


int maxHeight(Node* root){
    if (root == nullptr)
    {
        return 0;
    }
    int leftSideKiHeight = maxHeight(root->left);     
    int rightSideKiHeight = maxHeight(root->right);
    int answerHeight = max(leftSideKiHeight , rightSideKiHeight);
return answerHeight;   
}

int diaMeterOfTree(Node* root){
    int option1 = diaMeterOfTree(root->left);
    int option2 = diaMeterOfTree(root->right);
    int option3 = maxHeight(root->left) + maxHeight(root->right);

return max(option1, max(option2, option3));
}

int main(){
    Node* root = createTree();
    cout<<"The value for root node is : "<<root->data<<endl;

    cout<<"PreOrder traversal for the tree is : ";
    preOrder(root);cout<<endl;

    cout<<"Inorder traversal for the tree is : ";
    inOrder(root);cout<<endl;

    cout<<"PostOrder traversal for the tree is : ";
    postOrder(root);cout<<endl;

    cout<<"Level Order traversal (BFS) for the tree is : "<<endl;
    levelOrderTraversalBfs(root);cout<<endl;

    cout<<"The height of the tree is "<<maxHeight(root)<<endl;

    
return 0;
}