#include <iostream>

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

// Function to find the minimum value in the BST
int findMin(TreeNode* root) {
    if (root == nullptr)
        throw std::runtime_error("The tree is empty.");

    TreeNode* current = root;
    while (current->left != nullptr) {
        current = current->left;
    }
    return current->val;
}

// Function to find the maximum value in the BST
int findMax(TreeNode* root) {
    if (root == nullptr)
        throw std::runtime_error("The tree is empty.");

    TreeNode* current = root;
    while (current->right != nullptr) {
        current = current->right;
    }
    return current->val;
}

int main() {
    // Example usage:
    // Create a sample binary search tree
    TreeNode* root = new TreeNode(10);
    root->left = new TreeNode(5);
    root->right = new TreeNode(15);
    root->left->left = new TreeNode(3);
    root->left->right = new TreeNode(7);
    root->right->left = new TreeNode(12);
    root->right->right = new TreeNode(18);

    int minValue = findMin(root);
    int maxValue = findMax(root);

    std::cout << "Minimum value in the BST: " << minValue << std::endl;
    std::cout << "Maximum value in the BST: " << maxValue << std::endl;

    
    
    return 0;
}
