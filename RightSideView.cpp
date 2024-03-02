#include <iostream>
#include <vector>
#include <queue>

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
    vector<int> rightSideView(TreeNode* root) {
        vector<int> ans;
        queue<TreeNode*> q;
        if (root == NULL)
            return ans;
        q.push(root);
        while (1) {
            int size = q.size();
            if (size == 0)
                return ans;
            vector<int> data;
            while (size--) {
                TreeNode* temp = q.front();
                q.pop();
                data.push_back(temp->val);
                if (temp->left != NULL)
                    q.push(temp->left);
                if (temp->right != NULL)
                    q.push(temp->right);
            }
            ans.push_back(data.back());
        }
    }
};

// Function to create a binary tree from given array
TreeNode* createBinaryTree(vector<int>& arr, int i, int n) {
    TreeNode* root = nullptr;
    if (i < n && arr[i] != -1) {
        root = new TreeNode(arr[i]);
        root->left = createBinaryTree(arr, 2 * i + 1, n);
        root->right = createBinaryTree(arr, 2 * i + 2, n);
    }
    return root;
}

// Function to delete a binary tree
void deleteBinaryTree(TreeNode* root) {
    if (root) {
        deleteBinaryTree(root->left);
        deleteBinaryTree(root->right);
        delete root;
    }
}

int main() {
    // Example usage
    vector<int> arr = {1, 2, 3, -1, 5, -1, 4};
    TreeNode* root = createBinaryTree(arr, 0, arr.size());

    Solution sol;

    vector<int> result = sol.rightSideView(root);

    cout << "Right side view of the binary tree: ";
    for (int val : result) {
        cout << val << " ";
    }
    cout << endl;

    // Freeing the allocated memory
    deleteBinaryTree(root);

    return 0;
}
