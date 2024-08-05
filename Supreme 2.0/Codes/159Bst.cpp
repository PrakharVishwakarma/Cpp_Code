#include<iostream>
#include<vector>
#include<stack>
#include<queue>
#include <unordered_map>
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

// Leetcode 1008 : Construct Bst from preorder traversal.
Node* buildTree(vector<int> &preOrder, int &i, int lowerBound, int upperBound){
    if (i >= preOrder.size())
        return NULL;
    
    Node* root = NULL;
    if (preOrder[i]>lowerBound && preOrder[i]<upperBound)
    {
        root = new Node(preOrder[i++]);
        root->left = buildTree(preOrder, i, lowerBound, root->data);
        root->right = buildTree(preOrder, i, root->data, upperBound);
    }
return root;
}
Node* bstUsingPreOrder(vector<int> &preOrder){
    int i = 0;
    int lowerBound = INT_MIN;
    int upperBound = INT_MAX;
    return buildTree(preOrder, i, lowerBound, upperBound);
}

Node* inorderSuccessor(Node* root, Node* target){
    Node* successor = NULL;
    Node* temp = root;
    while (temp)
    {
        if (temp->data > target->data){
            successor = temp;
            temp = temp->left;
        }
        else{
            temp = temp->right;
        }
    }
return successor;
}

Node* inorderPredecessor(Node* root, Node* target){
    Node* Predecessor = NULL;
    Node* temp = root;
    while (temp)
    {
        if (temp->data < target->data){
            Predecessor = temp;
            temp = temp->right;
        }
        else{
            temp = temp->left;
        }
    }
return Predecessor;
}
// Brothers from different roots;
int findBrother(Node* root1, Node* root2, int sum){
    int ans = 0;
    stack<Node*> s1, s2;
    Node* a = root1;
    Node* b = root2;
    while (true)
    {
        while (a)
        {
            s1.push(a);
            a = a->left;
        }
        while (b)
        {
            s2.push(b);
            b = b->right;
        }
        if (s1.empty() || s2.empty())
            break;
        
        auto atop = s1.top();
        auto btop = s2.top();

        int sumOfNode = atop->data + btop->data;
        if (sumOfNode == sum)
        {
            ++ans;
            s1.pop();
            s2.pop();
            a = atop->right;
            b = btop->left;
        }
        else if (sumOfNode < sum)
        {
            s1.pop();
            a = atop->right;
        }
        else{
            s2.pop();
            b = btop->left;
        } 
    }
return ans;
}

// Leetcode 1382 : Balanced Binary Search Tree...
void inorder(Node* root, vector<int> &inOrder){
    if(root == NULL) return;

    inorder(root->left, inOrder);
    inOrder.push_back(root->data);
    inorder(root->right, inOrder);
}
Node* buildBalancedBst(vector<int> &inOrder, int s, int e){
    if (s>e) return NULL;
    
    int mid = (s+e) >> 1;
    Node* root = new Node(inOrder[mid]);
    root->left = buildBalancedBst(inOrder, s, mid-1);
    root->right = buildBalancedBst(inOrder, mid+1, e);
return root;
}
Node* balancedBst(Node* root){
    vector<int> inOrder;
    inorder(root, inOrder);
    return buildBalancedBst(inOrder, 0, inOrder.size()-1);
}


void solve(Node* root, bool &ans, unordered_map<int, bool>&visited){
    if (root == nullptr)
        return;
    
    visited[root->data] = true;
    if (root->left == nullptr && root->right == nullptr)
    {
        int xp1 = root->data+1;
        int xm1 = (root->data - 1) == 0 ? root->data : root->data - 1;  
        if (visited.find(xp1) != visited.end() && visited.find(xm1) != visited.end())
        {
            ans = true;
            return;
        }
    }  
    solve(root->left, ans, visited);
    solve(root->right, ans, visited);
}
bool isBstContainDeadEnd(Node* root){
    bool ans = false;
    unordered_map<int, bool>visited; 
    solve(root, ans, visited);
    return ans;
}


int rangeSumBst(Node* root, int &low, int &high){
    if(!root) return 0;

    int ans = 0;
    bool wasInRange = false;
    if (root->data >= low && root->data <= high){
        wasInRange = true;
        ans += root->data;       
    }
    if (wasInRange){
        ans += rangeSumBst(root->left, low, high) + rangeSumBst(root->right, low, high);
    }
    else if (root->data < low)
    {
        ans+=rangeSumBst(root->right, low, high);
    }
    else{
        ans += rangeSumBst(root->left, low, high);
    }
return ans;
}


void in(Node* root, Node* &prev){
    if(!root) return;

    in(root->left, prev);
    root->left = NULL;
    prev->right = root;
    prev = root;
    in(root->right, prev);
}
void printLl(Node* root){
    Node* temp = root;
    while (temp)
    {
        cout<<temp->data<<"->";
        temp = temp->right;
    }cout<<endl;
}
void flattenIntoLl(Node* root){
    Node* dummy = new Node(-1);
    Node* prev = dummy;
    in(root, prev);
    prev->right = NULL;
    prev->left = NULL;
    root = dummy->right;
    printLl(root);

}
int main(){

// Leetcode 1008 : Construct Bst from preorder traversal.
    vector<int> preOrder = {10, 5, 3, 4, 8, 20, 15, 13, 22};

    Node* root = bstUsingPreOrder(preOrder);
    levelOrderTraversalBfs(root);
    
    Node* targetNode = root->left->left->right;
    cout<<"Inorder successor of target node "<<targetNode->data<<" is "<<inorderSuccessor(root, targetNode)->data<<endl;
    cout<<"Inorder successor of target node "<<targetNode->data<<" is "<<inorderPredecessor(root, targetNode)->data<<endl;
    
    
    vector<int> preOrder2 = {15, 13, 8, 5, 10, 14, 20, 17, 22};

    Node* root2 = bstUsingPreOrder(preOrder2);
    levelOrderTraversalBfs(root2);

// Brothers from different roots;
    int sumToFindBrothers = 25;
    cout<<"Number of Brothers for the sum "<<sumToFindBrothers<<" is "<<findBrother(root, root2, sumToFindBrothers)<<endl;
    
// Balanced Bst
/*
    Node* rootB = NULL;
    // Enter the Bst which is not balanced.
    createBst(rootB);
    levelOrderTraversalBfs(rootB);
    cout<<endl;
    Node* updatedRootB = balancedBst(rootB);
    levelOrderTraversalBfs(updatedRootB);
*/

// Check Bst has dead end.
    if(isBstContainDeadEnd(root2))cout<<"Bst has Dead End."<<endl;
    else cout<<"Bst has not Dead End."<<endl;

// Leetcode 938 : Range sum of BST
    int low = 3;
    int high =20;
    cout<<"Range sum from "<<low<<" to "<<high<<" is "<<rangeSumBst(root, low, high)<<endl;

// Flatten the tree into Singly Linkeslist:
    flattenIntoLl(root);

return 0;
}