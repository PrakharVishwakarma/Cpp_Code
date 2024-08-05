// Leetcode : 337. House Robber III
#include<iostream>
#include<unordered_map>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

int solveUsingRecursion(TreeNode* root){
    if(root == NULL) return 0;

    int robThisHouse, dontRobThis;

    robThisHouse = root->val;
    if(root->left) robThisHouse += solveUsingRecursion(root->left->left) + solveUsingRecursion(root->left->right);
    if(root->right) robThisHouse += solveUsingRecursion(root->right->left) + solveUsingRecursion(root->right->right);

    dontRobThis = 0;
    dontRobThis += solveUsingRecursion(root->left) + solveUsingRecursion(root->right);

return max(robThisHouse, dontRobThis);
}

unordered_map<TreeNode* , int> dp;
int solveUsingMemoisation(TreeNode* root){
    if(root == NULL) return 0;

    if(dp.find(root) != dp.end()) return dp[root];

    int robThisHouse, dontRobThis;

    robThisHouse = root->val;
    if(root->left) robThisHouse += solveUsingMemoisation(root->left->left) + solveUsingMemoisation(root->left->right);
    if(root->right) robThisHouse += solveUsingMemoisation(root->right->left) + solveUsingMemoisation(root->right->right);

    dontRobThis = 0;
    dontRobThis += solveUsingMemoisation(root->left) + solveUsingMemoisation(root->right);

    dp[root] = max(robThisHouse, dontRobThis);
return dp[root];
}

void rob(TreeNode* root) {
    int ans = solveUsingRecursion(root);
    cout<<"The maximum amount of money the thief can rob without alerting the police "<< ans;
    
    ans = solveUsingMemoisation(root);
    cout<<endl<<"The maximum amount of money the thief can rob without alerting the police "<< ans;

}

int main(){
    TreeNode * root = new TreeNode(3);
    root->left = new TreeNode(4, new TreeNode(1), new TreeNode(3));
    root->right = new TreeNode(5, NULL, new TreeNode(1));

    rob(root);
return 0;
}