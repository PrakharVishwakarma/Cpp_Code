#include <iostream>
#include <limits.h>
#include <algorithm>
#include <queue>
using namespace std;

int kthSmallest(int *arr, int n, int k)
{
    priority_queue<int> pq;
    for (int i = 0; i < k; i++)
    {
        pq.push(arr[i]);
    }
    for (int i = k; i < n; i++)
    {
        if (arr[i] < pq.top())
        {
            pq.pop();
            pq.push(arr[i]);
        }
    }
    return pq.top();
}

int kthGreatest(int *arr, int n, int k)
{
    priority_queue<int, vector<int>, greater<int> > pq;
    for (int i = 0; i < k; i++)
    {
        pq.push(arr[i]);
    }
    for (int i = k; i < n; i++)
    {
        if (arr[i] > pq.top())
        {
            pq.pop();
            pq.push(arr[i]);
        }
    }
    return pq.top();
}

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

class Info{
public:
    int maxVal;
    bool isHeap;
    Info(){
        this->maxVal = INT_MIN;
        this->isHeap = false;
    }
};
Info checkMaxHeap(Node* root){
    if (root == NULL)
    {
        Info temp;
        temp.maxVal = INT_MIN;
        temp.isHeap = true; 
        return temp;
    }
    
    if (root->left == NULL && root->right == NULL)
    {
        Info temp;
        temp.maxVal = root->data;
        temp.isHeap = true;
        return temp;
    }
    
    Info leftAns = checkMaxHeap(root->left);
    Info rightAns = checkMaxHeap(root->right);
    if (root->data > leftAns.maxVal && root->data > rightAns.maxVal && leftAns.isHeap && rightAns.isHeap )
    {
        Info ans;
        ans.maxVal = root->data;
        ans.isHeap = true;
        return ans;
    }
    else{
        Info ans;
        ans.maxVal = max(max(leftAns.maxVal, rightAns.maxVal),root->data);
        ans.isHeap = false;
        return ans;
    }
}

bool isCbt(Node* root){
    // Using level order traversal:
    queue<Node*> q;
    q.push(root);
    bool nullFound = false;
    while (!q.empty())
    {
        Node* front = q.front();
        q.pop();
        if (front != NULL)
        {
            if (nullFound)return false;
            q.push(front->left);
            q.push(front->right);
        }
        else {
            nullFound = true;
        }
    }
    return true;
}

void inorder(Node* root,vector<int> &inOrder){
    if (root == NULL) return;

    inorder(root->left, inOrder);
    inOrder.push_back(root->data);
    inorder(root->right, inOrder);
}
void replaceUsingPostOrder(Node* root, vector<int> inOrder, int &i){
    if (root == NULL) return;
    
    replaceUsingPostOrder(root->left, inOrder, i);
    replaceUsingPostOrder(root->right, inOrder, i);
    root->data = inOrder[i];
    i++;
    
}
Node* cbstIntoMaxHeap(Node* root){
    vector<int> inOrder;
    inorder(root, inOrder);
    int index = 0;
    replaceUsingPostOrder(root, inOrder, index);
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

int main(){
    // Find the kth smallest element:
    int arr[] = {3, 5, 4, 6, 9, 8, 7};
    int size = sizeof(arr) / sizeof(int);
    int k = 4;
    cout << k << "th smallest elemtent is " << kthSmallest(arr, size, k) << endl;
    k = 6;
    cout << k << "th greatest elemtent is " << kthGreatest(arr, size, k) << endl;

    // Check the Complete Binary tree is max heap or not.
    // Create the Complete Binary tree:
    Node* root = createTree();
    cout<<"Printing the tree : "<<endl;levelOrderTraversalBfs(root);
    /*
    cout<<"The value for root node is : "<<root->data<<endl;
    Info checkMaxHeapContainer = checkMaxHeap(root);
    if(checkMaxHeapContainer.isHeap)
        cout<<"Complete Binary Tree is Max heap"<<endl;
    else cout<<"Complete Binary Tree is not a Max heap"<<endl;
    
    // Check the tree is Complete Binary Tree: 
    if(isCbt(root))
        cout<<"The tree is Complete Binary Tree"<<endl;
    else cout<<"The tree is not a Complete Binary Tree"<<endl;
    // Convert the Complete Binary search tree into Max heap;
    */
    Node* maxHeapRoot = cbstIntoMaxHeap(root);
    cout<<"Printing Max Heap : "<<endl;levelOrderTraversalBfs(maxHeapRoot);

    return 0;
}

