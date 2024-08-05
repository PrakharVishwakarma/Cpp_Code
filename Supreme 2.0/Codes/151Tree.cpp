// Sum of the longest bloodline of a tree (Sum of nodes on the longest path from root to leaf node.)

#include<iostream>
#include<utility>
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

pair<int, int> solveUsingheight(Node* root){
    if (root == nullptr)
        return {0,0};
    
    auto lH = solveUsingheight(root->left);
    auto rH = solveUsingheight(root->right);

    int sum = root->data;
    if (lH.first == rH.first)
    {
        sum += lH.second > rH.second ? lH.second : rH.second; 
    }
    else if (lH.first > rH.first)
    {
        sum += lH.second;
    }
    else{
        sum += rH.second;
    }
        
return {max(lH.first , rH.first) + 1,sum};
}
int solve(Node* root){
    auto h = solveUsingheight(root);
    return h.second;
}

int main(){
    Node* root = createTree();
    cout<<"The value for root node is : "<<root->data<<endl;
    
    cout<<"Sum of nodes on the longest path from root to leaf node is : "<<solve(root);

return 0;
}


