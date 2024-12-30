#include <iostream>
using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    void helper(TreeNode* root, int t, int s, int &ans) {
        if (root == NULL) return;
        if (!root->left && !root->right && s + root->val == t) {
            ans = 1;
            return;
        }
        helper(root->left, t, s + root->val, ans);
        helper(root->right, t, s + root->val, ans);
    }

    bool hasPathSum(TreeNode* root, int t) {
        int ans = 0;
        if (root == NULL) return ans;
        helper(root, t, 0, ans);
        return ans == 1;
    }
};

int main() {
    // Create a sample binary tree
    TreeNode* root = new TreeNode(5);
    root->left = new TreeNode(4);
    root->right = new TreeNode(8);
    root->left->left = new TreeNode(11);
    root->right->left = new TreeNode(13);
    root->right->right = new TreeNode(4);
    root->left->left->left = new TreeNode(7);
    root->left->left->right = new TreeNode(2);

    // Target sum
    int targetSum = 22;

    // Create a Solution object and check for path sum
    Solution sol;
    bool result = sol.hasPathSum(root, targetSum);

    // Print the result
    cout << "Does the tree have a path with sum " << targetSum << "? " << (result ? "Yes" : "No") << endl;

    // Clean up dynamically allocated memory
    delete root->left->left->right;
    delete root->left->left->left;
    delete root->left->left;
    delete root->left;
    delete root->right->right;
    delete root->right->left;
    delete root->right;
    delete root;

    return 0;
}
