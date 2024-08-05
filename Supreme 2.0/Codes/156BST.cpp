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


Node* insertInBst(Node* &root, int &data){
    if (root == NULL)
    {
        root = new Node(data);
        return root;
    }
    if(data > root->data){
        root->right = insertInBst(root->right,data);
    }
    else{
        root->left = insertInBst(root->left,data);
    }
    return root;
}

void createBst(Node* &root){
    int data;
    cout<<"Enter the value : ";
    cin>>data;
    while (data != -1)
    {
        root = insertInBst(root, data);
        cout<<"Enter the value : ";
        cin>>data;    
    }    
};

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

Node* minValue(Node* root){
    if (root == NULL)
    {
        cout<<"No minimum value found."<<endl;
    }
    Node* temp = root;
    while (temp->left)
    {
        temp = temp->left;
    }
    return temp;
}

Node* maxValue(Node* root){
    if (root == NULL)
    {
        cout<<"No maximum value found."<<endl;
    }
    Node* temp = root;
    while (temp->right)
    {
        temp = temp->right;
    }
    return temp;
}

bool searchInBst(Node* root , int target){
    if (root == NULL)
        return false;
    
    if (root->data == target)
        return true;
    
    bool leftAns = false;
    bool rightAns = false;
    if (target<root->data)
    {
        leftAns = searchInBst(root->left, data);
    }
    else{
        rightAns = searchInBst(root->right, data);
    }
    return leftAns||rightAns;
}

int main(){
    Node* root = NULL;
    createBst(root);

    cout<<"PreOrder traversal for the tree is : ";
    preOrder(root);cout<<endl;

    cout<<"Inorder traversal for the tree is : ";
    inOrder(root);cout<<endl;

    cout<<"PostOrder traversal for the tree is : ";
    postOrder(root);cout<<endl;

    cout<<"Level Order traversal (BFS) for the tree is : "<<endl;
    levelOrderTraversalBfs(root);cout<<endl;

    Node* minNode = minValue(root);
    if (minNode == NULL)
    {
        cout<<"Ni minimum node found."<<endl;
    }
    else{
        cout<<"Minimum value in the BST is: "<<minNode->data<<endl;
    }
    Node* maxNode = maxValue(root);
    if (maxNode == NULL)
    {
        cout<<"No maximum node found."<<endl;
    }
    else{
        cout<<"Maximum value in the BST is: "<<maxNode->data<<endl;    
    }

    int target;
    cin>>"Enter the target in to find in the BST : ";
    if (searchInBst(root,target))
    {
        cout<<"Target Found."<<endl;
    }
    else{
        cout<<"Target not found."<<endl;
    }
    

return 0;
}