#include <iostream>
#include <vector>
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
    TreeNode* build(vector<int>& inorder, int inLo, int inHi, vector<int>& postorder, int postLo, int postHi) {
        if (postLo > postHi) return NULL;
        TreeNode* root = new TreeNode(postorder[postHi]);
        if (postLo == postHi) return root;
        
        int i = inLo;
        while (i <= inHi) {
            if (inorder[i] == root->val) break;
            i++;
        }
        int leftCount = i - inLo;

        root->left = build(inorder, inLo, i - 1, postorder, postLo, postLo + leftCount - 1);
        root->right = build(inorder, i + 1, inHi, postorder, postLo + leftCount, postHi - 1);

        return root;
    }

    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int n = inorder.size();
        return build(inorder, 0, n - 1, postorder, 0, n - 1);
    }
};

// Helper function to print the tree in preorder (for validation)
void preorder(TreeNode* root) {
    if (root == NULL) return;
    cout << root->val << " ";
    preorder(root->left);
    preorder(root->right);
}

int main() {
    // Test case: Inorder and Postorder traversal arrays
    vector<int> inorder = {9, 3, 15, 20, 7};
    vector<int> postorder = {9, 15, 7, 20, 3};

    Solution sol;
    TreeNode* root = sol.buildTree(inorder, postorder);

    // Print the constructed tree in preorder to verify correctness
    cout << "Preorder traversal of the constructed tree: ";
    preorder(root);
    cout << endl;

    // Clean up dynamically allocated memory (optional for simple cases)
    delete root->left;   // 9
    delete root->right->left;   // 15
    delete root->right->right;  // 7
    delete root->right;  // 20
    delete root;         // 3

    return 0;
}
