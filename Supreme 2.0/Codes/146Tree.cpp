// Leecode 987: Vertical order Traversal of a Bonary Tree

#include<iostream>
#include<queue>
#include<utility>
#include<map>
#include<vector>

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

vector<vector<int>> vertclaTraversal(Node* root){
    vector<vector<int>> ans;
    queue<pair<Node*,pair<int, int>>>q;
    q.push({root,{0,0}});
    map<int, map<int, multiset<int>>>mp;

    while (!q.empty())
    {
        auto front = q.front(); q.pop();
        Node* &node front.first;
        auto &coordinate = front.second;
        int &row = coordinate.first;
        int col = coordinate.second;

        mp[col][row].insert(node->data);
        if (node->left)
        {
            q.push(node->left, {row+1, col-1});
        }
        if (node->right)
        {
            q.push(node->right, {row+1, col+1});
        }
        
    }
    for(auto it : mp){
        auto &colMap = it.second;
        vector<int>vLine;
        for(auto colMapIt:colMap){
            auto &mset = colMapIt.second;
            vLine.insert(vLine.end(), mset.begin, mset.end);
        }
        ans.push_back(vLine);
    }
return ans;
}


int main(){
    Node* root = createTree();
    cout<<"The value for root node is : "<<root->data<<endl;
    
return 0;
}

