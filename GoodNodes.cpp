#include <iostream>
#include <algorithm> // for max function

using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    int helper(TreeNode* node, int currMax, int cnt) {
        if(node == nullptr) return 0;
        if(node->val >= currMax) {
            cnt = 1;
        } else cnt = 0;
        currMax = max(currMax, node->val);
        cnt += helper(node->left, currMax, cnt);
        cnt += helper(node->right, currMax, cnt);
        return cnt;
    }

    int goodNodes(TreeNode* root) {
        return helper(root, root->val, 0);
    }
};

int main() {
    // Example usage
    Solution sol;
    
    // Creating a sample binary tree
    TreeNode* root = new TreeNode(3);
    root->left = new TreeNode(1);
    root->right = new TreeNode(4);
    root->left->left = new TreeNode(3);
    root->right->left = new TreeNode(1);
    root->right->right = new TreeNode(5);

    // Calling the function to count good nodes
    cout << "Number of good nodes: " << sol.goodNodes(root) << endl;

    // Freeing the allocated memory
    delete root->left->left;
    delete root->right->left;
    delete root->right->right;
    delete root->left;
    delete root->right;
    delete root;

    return 0;
}
