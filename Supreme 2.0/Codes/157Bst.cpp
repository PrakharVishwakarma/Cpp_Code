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

Node* deleteNode(Node* root, int target){
    if (root == NULL)
        return NULL;
    
    if (target == root->data)
    {
        // 4 Case Bante hain.
        // 1) root node is Leaf node:
        if (root->left == NULL && root->right == NULL)
        {
            delete root;
            return nullptr;
        }
        // 2) root ke left me kuch toh hai par right me nii hai.
        if (root->left && !root->right)
        {
            Node* childNode = root->left;
            delete root;
            return childNode;
        }
        // 3) root ke right me kuch toh hai par left me nii hai.
        if (root->right && !root->left)
        {
            Node* childNode = root->right;
            delete root;
            return childNode;
        }
        // 4) root ke left and right dono me kuchh na kuchh toh hai hi.
        
        else{ 
            // Sabse pehle toh left subtree ki maximum value lekar aao.
            Node* leftSubTMax = maxValue(root->left);

            root->data = leftSubTMax->data;
            root->left = deleteNode(root->left, leftSubTMax->data); 
            return root;
        }
        /* case (4) me left ke maxi ke jagah right ka mini bhi le sakte hain*/
    }
    else if (target < root->data)
    {
        root->left = deleteNode(root->left, target);
    }
    else{
        root->right = deleteNode(root->right, target);
    }
return root;
}

int main(){
    Node* root = NULL;
    createBst(root);

    int target;
    cout<<"Enter the value of the target node which should be deleted : ";
    cin>>target;
    while (target != -1)
    {
        root = deleteNode(root, target);
        cout<<endl<<"Level order traversal : "<<endl;
        levelOrderTraversalBfs(root);
        cout<<"Enter the value of the target node which should be deleted : ";
        cin>>target;
    }
    
return 0;
}

