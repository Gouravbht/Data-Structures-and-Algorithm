#include <iostream>

struct TreeNode {
    int data;
    TreeNode* left;
    TreeNode* right;
    
    TreeNode(int val) : data(val), left(nullptr), right(nullptr) {}
};

class BST {
public:
    TreeNode* root;

    BST() : root(nullptr) {}

    void insert(int value) {
        root = insertRecursive(root, value);
    }

    // In-order Traversal: Left, Root, Right
    void inorderTraversal(TreeNode* node) {
        if (node == nullptr) {
            return;
        }

        inorderTraversal(node->left);
        std::cout << node->data << " ";
        inorderTraversal(node->right);
    }

    // Pre-order Traversal: Root, Left, Right
    void preorderTraversal(TreeNode* node) {
        if (node == nullptr) {
            return;
        }

        std::cout << node->data << " ";
        preorderTraversal(node->left);
        preorderTraversal(node->right);
    }

    // Post-order Traversal: Left, Right, Root
    void postorderTraversal(TreeNode* node) {
        if (node == nullptr) {
            return;
        }

        postorderTraversal(node->left);
        postorderTraversal(node->right);
        std::cout << node->data << " ";
    }

private:
    TreeNode* insertRecursive(TreeNode* node, int value) {
        if (node == nullptr) {
            return new TreeNode(value);
        }

        if (value < node->data) {
            node->left = insertRecursive(node->left, value);
        } else if (value > node->data) {
            node->right = insertRecursive(node->right, value);
        }

        return node;
    }
};

int main() {
    BST bst;

    // Insert elements into the BST
    bst.insert(50);
    bst.insert(30);
    bst.insert(70);
    bst.insert(20);
    bst.insert(40);
    bst.insert(60);
    bst.insert(80);

    std::cout << "In-order Traversal: ";
    bst.inorderTraversal(bst.root);
    std::cout << std::endl;

    std::cout << "Pre-order Traversal: ";
    bst.preorderTraversal(bst.root);
    std::cout << std::endl;

    std::cout << "Post-order Traversal: ";
    bst.postorderTraversal(bst.root);
    std::cout << std::endl;

    return 0;
}
