#include <iostream>
#include <vector>
#include <queue>

using namespace std;

// --- Node Definition ---
class Node {
public:
    int data;
    Node* left;
    Node* right;
    
    Node(int _data) : data(_data), left(nullptr), right(nullptr) {}
    
    // CRITICAL CORRECTION: Remove the recursive destructor!
    // Recursive destructors like ~Node() { delete left; delete right; } 
    // are highly dangerous for raw pointers. They cause issues like stack 
    // overflow for deep trees and unintended deletion in shared ownership scenarios.
    // Use a separate utility function (deleteTree) instead.
    ~Node() {
        // Do NOTHING here. Cleanup is handled by deleteTree() in main().
    }
};

// --- Utility: Tree Creation ---
Node* createTree(){
    int data;
    cout << "Enter the value of the node (-1 for NULL): ";
    if (!(cin >> data)) return nullptr; // Safe input
    
    if (data == -1) {
        return nullptr;
    }

    Node* root = new Node(data);

    cout << "Enter left of node " << root->data << endl;
    root->left = createTree();

    cout << "Enter right of node " << root->data << endl;
    root->right = createTree();
    return root;
}

// --- Utility: Level Order Traversal (Corrected for nullptr) ---
void levelOrderTraversalBfs(Node* root){
    if (!root) return;
    queue<Node* >q;
    q.push(root);
    q.push(nullptr); // Sentinel for level change
    
    while (!q.empty()) {
        Node* front = q.front();
        q.pop(); 
        
        if (front == nullptr) {
            cout << endl;
            if (!q.empty()) {
                q.push(nullptr);
            }
        } else {
            cout << front->data << " ";
            
            // Only push if not nullptr
            if (front->left) {
                q.push(front->left); 
            }
            if (front->right) {
                q.push(front->right); 
            }
        }
    } 
}

// --- Utility: Memory Cleanup ---
void deleteTree(Node* node) {
    if (node == nullptr) {
        return;
    }
    deleteTree(node->left);
    deleteTree(node->right);
    delete node; 
}


// --- GfG Solution Function (Your original logic, slightly renamed for clarity) ---
int transformAndSum(Node* root){
    if (root == nullptr) return 0;
    
    // Base case: Leaf node. Must be handled first or logic fails.
    if (root->left == nullptr && root->right == nullptr) {
        int temp = root->data;
        root->data = 0; // Transform leaf to 0
        return temp;    // Return its original value
    }
    
    // Recursive calls
    int lSum = transformAndSum(root->left);
    int rSum = transformAndSum(root->right);
    
    int temp = root->data; // Store original value
    
    // Transform node's value
    root->data = lSum + rSum; 
    
    // Return total sum of this subtree (old value + new children's sum)
    return root->data + temp; 
}


int main(){
    Node* root = createTree();
    
    if (root) {
        cout << "\nLevel Order traversal (BFS) for the original tree: " << endl;
        levelOrderTraversalBfs(root);
        
        // Call the transformation function
        transformAndSum(root); 
        
        cout << "\nLevel Order traversal (BFS) for the Sum Tree: " << endl;
        levelOrderTraversalBfs(root);
        cout << endl;
        
        // **PERFECT MEMORY CLEANUP**
        deleteTree(root);
    } else {
        cout << "Tree is empty." << endl;
    }

    return 0; 
}