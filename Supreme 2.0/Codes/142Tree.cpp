// Left View of the tree.

#include<iostream>
#include<vector>
#include<queue>
#include<map>
#include<utility>

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

void printLeftView(Node* root, vector<int> &leftView , int currLevel){
    if (root == NULL)
    {
        return;
    }
    if (currLevel == leftView.size())
    {
        leftView.push_back(root->data);
    }
    
    printLeftView(root->left , leftView ,currLevel + 1);
    printLeftView(root->right , leftView ,currLevel + 1);
}

void printRightView(Node* root, vector<int> &rightView , int currLevel){
    if (root == NULL)
    {
        return;
    }
    if (currLevel == rightView.size())
    {
        rightView.push_back(root->data);
    }
    
    printLeftView(root->right , rightView ,currLevel + 1);
    printLeftView(root->left , rightView ,currLevel + 1);
} 

void printTopView(Node* root){
    map<int , int> hdToNodeMap;
    queue< pair<Node* , int>>q;

    q.push(make_pair(root , 0));

    while (!q.empty())
    {
        pair<Node* , int> temp = q.front();
        q.pop();

        Node* frontNode = temp.first;
        int hd = temp.second;
        
        if (hdToNodeMap.find(hd) == hdToNodeMap.end())
        {
            hdToNodeMap[hd] = frontNode->data;
        }
        
        if (frontNode->left)
        {
            q.push(make_pair(frontNode->left , hd+1));
        }
        if (frontNode->right)
        {
            q.push(make_pair(frontNode->right , hd-1));
        }
    }
    cout<<"Top view of the tree is : ";
    for(auto i : hdToNodeMap ){
        cout<<i.second<<" ";
    }
}
void printBottomView(Node* root){
    map<int , int> hdToNodeMap;
    queue< pair<Node* , int>>q;

    q.push(make_pair(root , 0));

    while (!q.empty())
    {
        pair<Node* , int> temp = q.front();
        q.pop();

        Node* frontNode = temp.first;
        int hd = temp.second;
        
        hdToNodeMap[hd] = frontNode->data;
        
        if (frontNode->left)
        {
            q.push(make_pair(frontNode->left , hd+1));
        }
        if (frontNode->right)
        {
            q.push(make_pair(frontNode->right , hd-1));
        }
    }
    cout<<"Bottom view of the tree is : ";
    for(auto i : hdToNodeMap ){
        cout<<i.second<<" ";
    }
}

// Boundary view of Binary Tree: 
void printLeftBv(Node* root){
    if (root == NULL)
        return;
    
    if (root->left == NULL && root->right == NULL)
        return;
    
    cout<<root->data<<" ";
    if (root->left != NULL)
    {
        printLeftBv(root->left);
    }
    else{
        printLeftBv(root->right);
    }   
}
void printLeafBv(Node* root){
    if (root == NULL)
        return;
    if (root->left == NULL && root->right == NULL)
    {
        cout<<root->data<<" ";
    }
    printLeftBv(root->left);
    printLeafBv(root->right);
} 
void printRightBv(Node* root){
    if (root == NULL)
        return;
    
    if (root->left == NULL && root->right == NULL)
        return;
    
    if (root->left != NULL)
    {
        printRightBv(root->right);
    }
    else{
        printRightBv(root->left);
    } 
    cout<<root->data<<" ";
}

void printBoundaryView(Node* root){
    if (root == NULL)
        return;

    cout<<root->data<<" ";
    printLeftBv(root->left);
    printLeafBv(root->left);
    printLeafBv(root->right);
    printRightBv(root->right);
}   

int main(){
    Node* root = createTree();
    cout<<"The value for root node is : "<<root->data<<endl;
    cout<<"The bfs traversal of the BT : "<<endl;
    levelOrderTraversalBfs(root);
    
    vector<int>leftView;
    cout<<endl<<"Left view of the tree is : ";
    printLeftView(root , leftView , 0);
    for (int i = 0; i < leftView.size(); i++)
    {
        cout<<leftView[i]<<" ";
    }

    vector<int>rightView;
    cout<<endl<<"right view of the tree is : ";
    printRightView(root , rightView , 0);
    for (int i = 0; i < rightView.size(); i++)
    {
        cout<<rightView[i]<<" ";
    }
    
    cout<<endl;
    printTopView(root);
    cout<<endl;
    printBottomView(root);
    cout<<endl<<"Boundary view of the Binary Tree is : ";
    printBoundaryView(root);
return 0;
}



// HomeWork : Apply level order traversing to print left view and right view.