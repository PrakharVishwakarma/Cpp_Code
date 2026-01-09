#include <iostream>
#include <vector>
#include <queue>
#include <algorithm> // Needed for std::reverse (an alternative approach to your current index calculation)

// Use 'std::' prefix instead of 'using namespace std;' in a competitive environment,
// but for simplicity in this case, we'll keep your original 'using namespace std;'.
using namespace std;

// --- TreeNode Definition (Node is generally preferred as TreeNode in LeetCode) ---
class TreeNode {
public:
    int val;
    TreeNode* left;
    TreeNode* right;
    // Constructor
    TreeNode(int _val) {
        this->val = _val;
        this->left = nullptr; // Use nullptr instead of NULL
        this->right = nullptr; // Use nullptr instead of NULL
    }
    // Added default constructor for completeness
    TreeNode() : val(0), left(nullptr), right(nullptr) {}

    ~TreeNode() {
        // Destructor to free memory (not strictly necessary for LeetCode, but good practice)
        delete left;
        delete right;
    }
};

// --- Utility Function: createTree (Optional, used for local testing) ---
// Changed Node to TreeNode for consistency.
TreeNode* createTree(){
    int data;
    cout << "Enter the value of the node (-1 for NULL): ";
    cin >> data;
    if (data == -1) {
        return nullptr;
    }

    TreeNode* root = new TreeNode(data);

    cout << "Enter left of node " << root->val << endl;
    root->left = createTree();

    cout << "Enter right of node " << root->val << endl;
    root->right = createTree();
    return root;
}

// --- LeetCode Solution Function (Renamed to match LeetCode's common function name) ---
// The original logic is retained as it is correct and efficient.
vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
    vector<vector<int>> ans;
    if (!root) return ans;
    
    bool leftToRight = true; // Flag to track direction: true = L->R, false = R->L
    queue<TreeNode*> q;
    q.push(root);

    while (!q.empty()) {
        int widthOfLevel = q.size();
        // The level vector size is known, allowing pre-allocation for O(1) insertion at index
        vector<int> nodesAtALevel(widthOfLevel); 

        for (int i = 0; i < widthOfLevel; i++) {
            TreeNode* front = q.front(); 
            q.pop();

            // Core logic for Zigzag traversal: determining the insertion index
            int index = leftToRight ? i : widthOfLevel - i - 1;
            nodesAtALevel[index] = front->val;

            // Enqueue children for the next level (always L then R, maintaining Level Order)
            if (front->left) {
                q.push(front->left);
            }
            if (front->right) {
                q.push(front->right);
            }
        }
        
        // Flip the direction for the next level
        leftToRight = !leftToRight;
        ans.push_back(nodesAtALevel);
    }
    return ans; 
}
// Note: An alternative to the index calculation is to always insert at 'i' and 
// use 'std::reverse(nodesAtALevel.begin(), nodesAtALevel.end())' when 'leftToRight' is false.
// Your current indexing method is generally considered slightly faster as it avoids the reverse call.

// --- Main Function (for local testing) ---
int main(){
    // Minor correction: Only one #include<iostream> is needed
    // Replaced zigZag with zigzagLevelOrder

    // Example Tree Input: 3, 9, -1, -1, 20, 15, -1, -1, 7, -1, -1
    TreeNode* root = createTree(); 
    
    // Safety check for an empty tree
    if (root) {
        cout << "\nThe value for root node is: " << root->val << endl;
        vector<vector<int>> v = zigzagLevelOrder(root);
        
        cout << "Zigzag Traversal Result:" << endl;
        for (const auto& level : v) {
            for (int val : level) {
                cout << val << " ";
            }
            cout << endl;
        }
    } else {
        cout << "\nTree is empty." << endl;
    }

    // Note: In a real-world application, you should add memory cleanup (deleting nodes).
    
    return 0;
}