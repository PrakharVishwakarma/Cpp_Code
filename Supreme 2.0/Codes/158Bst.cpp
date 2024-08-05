#include<iostream>
#include<vector>
#include<queue>
#include<limits.h>
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

// BST ka inorder hamesha increasing order me sorted rehta hai.
Node* createBstUsingInorder(int inorder[], int s, int e){
    if (s>e)return NULL;

    int mid = (s+e)/2;
    int element = inorder[mid];
    Node* root = new Node(element);
    
    root->left = createBstUsingInorder(inorder, s, mid-1);
    root->right =  createBstUsingInorder(inorder, mid+1, e);

return root;
}

// Leetcode : 98: Validate Binary search Tree 
bool isBst(Node* root, long long int lowerBound,long long int upperBound){
    if (root == nullptr){
        return true;
    }
    bool cond1 = (root->data > lowerBound);
    bool cond2 = (root->data < upperBound);
    bool isLeftSubTreeBst = isBst(root->left, lowerBound, root->data);
    bool isRightSubTreeBst = isBst(root->right, root->data, upperBound);

return cond1 && cond2 && isLeftSubTreeBst && isRightSubTreeBst;    
}

Node* lowestCommonAncestor(Node* root, Node* p, Node* q){
    if (root == NULL)
        return NULL;
    
    if (p->data<root->data && q->data<root->data)
        return lowestCommonAncestor(root->left, p, q);
    
    if (p->data>root->data && q->data>root->data)
        return lowestCommonAncestor(root->right, p, q);
    
    /* if ((p->data < root->data && q->data > root.data)||
    (p->data > root->data && q->data < root.data))
        return root;
    */
return root;
}

int kthSmallestElement(Node* root, int &k){
    if (root == nullptr) return -1;

    // Using Inorder we can easily find kth smallest.
    int leftAns = kthSmallestElement(root->left, k);
    if (leftAns != -1)
        return leftAns;
    
    k--;
    if (k==0)
    return root->data;

    int rightAns = kthSmallestElement(root->right, k);
    if (rightAns != -1)
        return rightAns;
}

//Leetcode 653: Two Sum 
void storeInorder(Node* root, vector<int> &inorderVector){
    if (root == NULL) return;

    storeInorder(root->left, inorderVector);
    inorderVector.push_back(root->data);
    storeInorder(root->right, inorderVector);

}
bool istargetSum(Node* root, int target){
    vector<int>inorderVector;
    storeInorder(root, inorderVector);
    for (int i = 0; i < inorderVector.size(); i++)
    {
        cout<<inorderVector[i]<<" ";
    }cout<<endl;
    
    int s = 0;
    int e = inorderVector.size()-1;
    while (s<e)
    {
        int sum = inorderVector[s] + inorderVector[e];
        if (sum == target)
            return true;
        
        else if (sum > target)
            e--; 

        else if (sum < target)
            s++;

    }
return false;
}

void BstToDll(Node* root, Node* &head){
    if (root == NULL)
        return;
    
    BstToDll(root->right, head);

    root->right = head;
    if (head != NULL)
        head->left = root;
    head = root;
    
    BstToDll(root->left, head);
}
void printDll(Node* head){
    Node* temp = head;
    cout<<endl<<"Printing the Doubly linked list : ";
    while(temp != NULL)
    {
        cout<<temp->data<<"->";
        temp = temp->right;
    }cout<<endl;
}

Node* dllToBst(Node* &head, int numberOfNode){
    if(head == NULL || numberOfNode <= 0) return NULL; 

    Node* leftSubTree = dllToBst(head, numberOfNode/2);

    Node* root = head;
    root->left = leftSubTree;
    head = head->right;

    Node* rightSubTree = dllToBst(head, numberOfNode-numberOfNode/2-1);
    root->right = rightSubTree;
return root;
}

int main(){
    int inorder[] = {10,20,30,40,50,60,70,80,85};
    int size = sizeof(inorder)/sizeof(int);
    int start = 0;
    int end = size-1;
    Node* root = createBstUsingInorder(inorder, start, end);
    levelOrderTraversalBfs(root);

    // Check the valid BST.
    long long int lowerBound = -2147483650; 
    long long int upperBound =  2147483650; 
    if (isBst(root, lowerBound, upperBound))
    {
        cout<<"Tree is valid BST."<<endl;
    }
    else{
        cout<<"Tree is not valid BST."<<endl;
    }

    Node* p = root->left->right->right;
    Node*q = root->left->left;
    Node* lowestCommonAncestorNode = lowestCommonAncestor(root, p, q);
    cout<<endl<<"Loweset commonn ancestor is "<<lowestCommonAncestorNode->data;
    
    // Finding the kth smallest element in the bst.
    int k =  4;
    cout<<endl<<"kth smallest element in the BST is : "<<kthSmallestElement(root, k)<<endl;

    // Leetcode 653: Two Sum 
    int target = 115;
    if(istargetSum(root, target)){
        cout<<"Target is exsist "<<endl;
    }
    else{
        cout<<"Tatget is not exsist."<<endl;
    }

    // Convert the BST into Sorted Doubly Linked list:
    Node* head = NULL;
    BstToDll(root, head);
    printDll(head); 

    // Convert the Doubly Linked List to BST:
    Node* rootb = dllToBst(head, 9);
    levelOrderTraversalBfs(rootb);
return 0;
}