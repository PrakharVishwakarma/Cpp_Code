//GFG: Diagonal Traversal.

#include<iostream>
#include<vector>
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

vector<int> diagonalTraversal(Node* root){
    vector<int>ans; 
    if(!root) return ans;

    queue<Node*> q;
    q.push(root);
    while (!q.empty())
    {
        Node *temp = q.front(); q.pop();
        while (temp){
            ans.push_back(temp->data);
            if (temp->left)
            {
                q.push(temp->left);
            }
            temp = temp->right;
        }
    }
return ans;
}

int main(){
    Node* root = createTree();
    cout<<"The value for root node is : "<<root->data<<endl;
    vector<int> v = diagonalTraversal(root);
    for(auto i : v){
        cout<<i<<" ";
    }
return 0;
}

