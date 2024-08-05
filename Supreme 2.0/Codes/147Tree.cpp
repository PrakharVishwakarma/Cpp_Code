// Leetcode 113 : ZigZag level order tragversal.

#include<iostream>
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

vector<vector<int>> zigZag(Node*root){
    vector<vector<int>> ans;
    if (!root)
        return ans;
    
    bool leftToRight = true;
    queue<Node*>q;
    q.push(root);
    while (!q.empty())
    {

        int widthOfVector = q.size();
        vector<int> nodeAtALevel(widthOfVector);
        for (int i = 0; i < widthOfVector; i++)
        {
            Node* front = q.front(); q.pop();
            int index = leftToRight ? i : widthOfVector-i-1;
            nodeAtALevel[index] = front->data;
            if (front->left)
            {
                q.push(front->left);
            }
            if (front->right)
            {
                q.push(front->right);
            }
        }
        leftToRight = !leftToRight;
        ans.push_back(nodeAtALevel);
    }
return ans;    
}

int main(){
    Node* root = createTree();
    cout<<"The value for root node is : "<<root->data<<endl;
    vector<vector<int> >v = zigZag(root);
    for (int i = 0; i < v.size(); i++) {
        for (int j = 0; j < v[i].size(); j++) {
            cout << v[i][j] << " ";
        }
        cout << endl;
    }
    
return 0;
}
