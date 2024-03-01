#include <iostream>
#include <vector>
#include <stack>

using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// Helper function to traverse the tree in a depth-first manner and collect leaf node values
void getLeafSequence(TreeNode* root, vector<int>& sequence) {
    if (!root) return;
    
    stack<TreeNode*> stk;
    stk.push(root);
    
    while (!stk.empty()) {
        TreeNode* node = stk.top();
        stk.pop();
        
        if (!node->left && !node->right) {
            sequence.push_back(node->val);
        }
        
        if (node->right) stk.push(node->right);
        if (node->left) stk.push(node->left);
    }
}

// Function to check if two trees have the same leaf value sequence
bool leafSimilar(TreeNode* root1, TreeNode* root2) {
    vector<int> sequence1, sequence2;
    
    getLeafSequence(root1, sequence1);
    getLeafSequence(root2, sequence2);
    
    return sequence1 == sequence2;
}

int main() {
    // Example usage:
    TreeNode* root1 = new TreeNode(3);
    root1->left = new TreeNode(5);
    root1->right = new TreeNode(1);
    root1->left->left = new TreeNode(6);
    root1->left->right = new TreeNode(2);
    root1->right->left = new TreeNode(9);
    root1->right->right = new TreeNode(8);
    root1->left->right->left = new TreeNode(7);
    root1->left->right->right = new TreeNode(4);

    TreeNode* root2 = new TreeNode(3);
    root2->left = new TreeNode(5);
    root2->right = new TreeNode(1);
    root2->left->left = new TreeNode(6);
    root2->left->right = new TreeNode(7);
    root2->right->right = new TreeNode(4);
    root2->right->left = new TreeNode(2);
    root2->right->left->right = new TreeNode(9);
    root2->right->left->left = new TreeNode(8);

    cout << boolalpha << leafSimilar(root1, root2) << endl; 

    return 0;
}
