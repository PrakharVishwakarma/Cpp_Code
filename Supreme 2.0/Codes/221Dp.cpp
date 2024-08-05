// 95. Unique Binary Search Trees II

#include<iostream>
#include<vector>
#include<queue>
#include<map>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
void inOrder(TreeNode* root){
    // Base case : 
    if (root == NULL)return;

    // left : (L)
    inOrder(root->left);
    // (N)
    cout<<root->val<<" ";
    // Right : (R)
    inOrder(root->right);
}
void levelOrderTraversalBfs(TreeNode* root){
    queue<TreeNode* >q;
    q.push(root);
    q.push(NULL);
    while (!q.empty())
    {
        TreeNode* front = q.front(); 
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
            cout<<front->val<<" ";
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

vector<TreeNode*> solveUsingRecursion(int s, int e){
    if(s > e) return {0};
    if(s == e) return {new TreeNode(s)};

    vector<TreeNode*> ans;
    for (int i = s; i<= e; i++)
    {
        vector<TreeNode*> left = solveUsingRecursion(s, i-1);   
        vector<TreeNode*> right = solveUsingRecursion(i+1, e);   
        for (int j = 0; j < left.size(); j++){
            for (int k = 0; k < right.size(); k++)
            {
                TreeNode* root = new TreeNode(i);
                root->left = left[j];
                root->right = right[k];
                ans.push_back(root);
            }
        }
    }
return ans;
}

map< pair<int, int>, vector<TreeNode*> >dp;
vector<TreeNode*> solveUsingMemoisation(int s, int e){
    if(s > e) return {0};
    if(s == e) return {new TreeNode(s)};

    if(dp.find({s,e}) != dp.end()) return dp[{s,e}];

    vector<TreeNode*> ans;
    for (int i = s; i<= e; i++)
    {
        vector<TreeNode*> left = solveUsingMemoisation(s, i-1);   
        vector<TreeNode*> right = solveUsingMemoisation(i+1, e);   
        for (int j = 0; j < left.size(); j++){
            for (int k = 0; k < right.size(); k++)
            {
                TreeNode* root = new TreeNode(i);
                root->left = left[j];
                root->right = right[k];
                ans.push_back(root);
            }
        }
    }
    dp[{s,e}] = ans;
return dp[{s,e}];
}
void generateTrees(int n) {
    if(n == 0) return ;
    // vector<TreeNode*> ans = solveUsingRecursion(1, n);
    vector<TreeNode*> ans = solveUsingMemoisation(1, n);
    for (auto i : ans)
    {
        levelOrderTraversalBfs(i);
        cout<<endl;
    }
}

int main()
{
    int  n = 5;
    generateTrees(n);

return 0;
}