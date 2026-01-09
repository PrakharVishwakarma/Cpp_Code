// Leecode 987: Vertical order Traversal of a Binary Tree

#include <iostream>
#include <queue>
#include <utility>
#include <map>
#include <vector>
#include <set>

using namespace std;

class Node
{
public:
    int data;
    Node *left;
    Node *right;
    Node(int _data)
    {
        this->data = _data;
        this->left = NULL;
        this->right = NULL;
    }
};

Node *createTree()
{
    int data;
    cout << "Enter the value of the node : ";
    cin >> data;
    if (data == -1)
    {
        return NULL;
    }

    Node *root = new Node(data);

    cout << "Enter left of node " << root->data << endl;
    root->left = createTree();

    cout << "Enter right of node " << root->data << endl;
    root->right = createTree();
    return root;
}

vector<vector<int>> vertclaTraversal(Node *root)
{
    vector<vector<int>> ans;
    queue<pair<Node *, pair<int, int>>> q;
    q.push({root, {0, 0}});
    map<int, map<int, multiset<int>>> mp;

    while (!q.empty())
    {
        auto front = q.front();
        q.pop();
        Node *&node = front.first;
        auto &coordinate = front.second;
        int &row = coordinate.first;
        int col = coordinate.second;

        mp[col][row].insert(node->data);
        if (node->left)
        {
            q.push({node->left, {row + 1, col - 1}});
        }
        if (node->right)
        {
            q.push({node->right, {row + 1, col + 1}});
        }
    }
    for (auto it : mp)
    {
        auto &colMap = it.second;
        vector<int> vLine;
        for (auto colMapIt : colMap)
        {
            auto &mset = colMapIt.second;
            vLine.insert(vLine.end(), mset.begin(), mset.end());
        }
        ans.push_back(vLine);
    }
    return ans;
}

int main()
{
    Node *root = createTree();
    cout << "The value for root node is : " << root->data << endl;

    return 0;
}


/*
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        vector<vector<int>> ans;
        if (!root) return ans; // Handle empty tree case

        // Queue for BFS: {Node, {row, col}}
        queue<pair<TreeNode *, pair<int, int>>> q; 
        q.push({root, {0, 0}});

        // Map: col -> {row -> [nodes]} using multiset for sorted values at the same (col, row)
        map<int, map<int, multiset<int>>> mp; 

        while (!q.empty()) {
            pair<TreeNode *, pair<int, int>> front = q.front();
            q.pop();
            
            TreeNode *node = front.first;
            pair<int, int> coordinate = front.second;
            int row = coordinate.first;
            int col = coordinate.second;

            // Store the node value in the multiset at its (col, row) position
            mp[col][row].insert(node->val);

            // Process left child: moves down (row + 1) and left (col - 1)
            if (node->left) {
                q.push({node->left, {row + 1, col - 1}});
            }

            // Process right child: moves down (row + 1) and right (col + 1)
            if (node->right) {
                q.push({node->right, {row + 1, col + 1}});
            }
        }

        // --- Reconstruct the final answer ---
        // Iterate through the outer map (columns). The map ensures columns are processed in order.
        for (const auto& col_pair : mp) {
            // col_pair.first is the column index (int)
            // col_pair.second is the inner map (map<int, multiset<int>>)
            
            map<int, multiset<int>> colMap = col_pair.second;
            vector<int> vLine;

            // Iterate through the inner map (rows). The map ensures rows are processed in order.
            for (const auto& row_pair : colMap) {
                // row_pair.first is the row index (int)
                // row_pair.second is the multiset of values (multiset<int>)
                
                const multiset<int>& mset = row_pair.second;
                
                // Append all elements from the multiset (already sorted) to the current vertical line vector
                vLine.insert(vLine.end(), mset.begin(), mset.end());
            }
            
            ans.push_back(vLine);
        }

        return ans;
    }
*/