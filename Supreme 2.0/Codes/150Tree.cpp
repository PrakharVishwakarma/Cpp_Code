// Morris Traversal is the traversal to find the inorder woithout using recursion. 

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

vector<int> morrisTraversal(Node* root){
    vector<int> ans;
    Node* curr = root;
    while (curr)
    {
        if (curr->left == NULL)
        {
            ans.push_back(curr->data);
            curr = curr->right;
        }
        else{
            Node* predecessor = curr->left;
            while (predecessor->right != curr && predecessor->right)
            {
                predecessor = predecessor->right;
            }
            // yadi predecessor se curr ki link nahi hai toh link bana do. 
            if (predecessor->right == NULL)
            {
                predecessor->right = curr;
                curr = curr->left;
            }
            // yadi predecessor se curr ki link hai toh link bana hata do.
            else{
                predecessor->right = NULL;
                ans.push_back(curr->data);
                curr = curr->right;
            } 
        }
    }
return ans;
}

int main(){
    Node* root = createTree();
    cout<<"The value for root node is : "<<root->data<<endl;

    cout<<"Inorder traversal for the tree is : ";
    inOrder(root);cout<<endl;

    vector<int> morrisTraversalAns = morrisTraversal(root);
    for (int i = 0; i < morrisTraversalAns.size(); i++)
    {
        cout<<morrisTraversalAns[i]<<" ";
    }
    

return 0;
}