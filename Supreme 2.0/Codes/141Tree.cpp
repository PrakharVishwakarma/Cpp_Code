// Form a tree using the given preorder and inorder
// Form a tree using the given postorder and inorder

#include<iostream>
#include<queue>
#include<map>
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

/*
int searchInInorder(int inorder[] , int size, int element){
    for (int i = 0; i < size; i++)
    {
        if (inorder[i] == element)return i;   
    }
}
*/
void createMapping(int inorder[], map<int,int> &valueToIndex , int size){
    for (int i = 0; i < size; i++)
    {
        int element = inorder[i];
        int index = i;
        valueToIndex[element] = index;
    }   
}
Node* constructBTUsingPreNInorder(int preorder[], int inorder[], int &preOrderIndex , int inOrderStart, int inOrderEnd, int size, map<int,int> &valueToIndex1){
    if (preOrderIndex >= size || inOrderStart > inOrderEnd)
    {
        return NULL;
    }
    
    int element = preorder[preOrderIndex];
    preOrderIndex++;
    Node* root = new Node(element);
    int position = valueToIndex1[element];

    root->left = constructBTUsingPreNInorder(preorder , inorder, preOrderIndex, inOrderStart, position-1, size, valueToIndex1);
    root->right = constructBTUsingPreNInorder(preorder , inorder, preOrderIndex, position+1 , inOrderEnd, size, valueToIndex1);

return root;
}

Node* constructBTUsingPostNInoerde(int postorder[], int inorder[], int &postorderindex , int inOrderStart, int inOrderEnd, int size, map<int,int> &valueToIndex2){
    if (postorderindex < 0 || inOrderStart > inOrderEnd)
    {
        return NULL;
    }
    
    int element = postorder[postorderindex];
    postorderindex--;
    Node* root = new Node(element);
    int position = valueToIndex2[element];

    root->right = constructBTUsingPreNInorder(postorder , inorder, postorderindex, position+1 , inOrderEnd, size, valueToIndex2);
    root->left = constructBTUsingPreNInorder(postorder , inorder, postorderindex, inOrderStart, position-1, size, valueToIndex2);

return root;
}

int main(){
    int preorder[] = {2, 8, 10, 6, 4, 12};
    int inorder[] = {10, 8, 6, 2, 4, 12};
    int size = 6;
    int preOrderIndex = 0;
    int inOrderStart = 0;
    int inOrderEnd = size-1;
    map<int, int> valuetoInd;
    createMapping(inorder , valuetoInd, size);
    Node * root1 = constructBTUsingPreNInorder(preorder, inorder, preOrderIndex , inOrderStart, inOrderEnd, size, valuetoInd);
    levelOrderTraversalBfs(root1);cout<<endl;

    // Using inorder and postorder:
    int postorder[] = {8, 6, 14, 4, 10, 2};
    int postorderIndex = size-1;
    createMapping(inorder , valuetoInd, size);
    Node * root2 = constructBTUsingPostNInoerde(postorder, inorder, postorderIndex , inOrderStart, inOrderEnd, size, valuetoInd);
    levelOrderTraversalBfs(root2);
return 0;
}