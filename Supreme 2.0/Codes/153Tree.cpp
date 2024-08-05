// Burning Treee

#include<iostream>
#include<queue>
#include<unordered_map>
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

Node* makeNodeToParentMappingAndFindTarget(Node* root, unordered_map<Node*,Node*>&paraentMap, int target){
    queue<Node*>q;
    Node* targetNode = NULL;
    q.push(root);
    paraentMap[root] = NULL;
    while (!q.empty())
    {
        Node* front = q.front(); q.pop();
        if (front->data == target)
        {
            targetNode = front;
        }
        if (root->left)
        {
            q.push(root->left);
            makeNodeToParentMappingAndFindTarget(root->left, paraentMap,target);
        }
        if (root->right)
        {
            q.push(root->right);
            makeNodeToParentMappingAndFindTarget(root->right, paraentMap,target);
        }
    }
return targetNode;
}

int burnTree(Node* targetNode, unordered_map<Node*,Node*>paraentMap){
    unordered_map<Node*,bool>isBurnt;
    queue<Node*>q;
    int time = 0;
    q.push(targetNode);
    isBurnt[targetNode] = 1;
    while (!q.empty())
    {
        int size = q.size();
        bool isFireSpread = 0;
        for (int i = 0; i < size; i++)
        {
            Node* front = q.front();q.pop();
            if (front->left && !isBurnt[front->left])
            {
                q.push(front->left);
                isBurnt[front->left] = 1;
                isFireSpread = 1;
            }
            if (front->right && !isBurnt[front->right])
            {
                q.push(front->right);
                isBurnt[front->right] = 1;
                isFireSpread = 1;
            }
            if (paraentMap[front] && !isBurnt[paraentMap[front]])
            {
                q.push(paraentMap[front]);
                isBurnt[paraentMap[front]] = 1;
                isFireSpread = 1;
            }
        }
    if (isFireSpread)time++;
    }
return time;
}

int minTimeToBurn(Node* root, int target){
    unordered_map<Node*, Node*>paraentMap;
    Node* targetNode = makeNodeToParentMappingAndFindTarget(root , paraentMap , target);
    return burnTree(targetNode, paraentMap);
}
int main(){
    Node* root = createTree();
    cout<<"The value for root node is : "<<root->data<<endl;

return 0;
}