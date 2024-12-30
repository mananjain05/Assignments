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
    TreeNode* build(vector<int>& preorder, int preLo, int preHi, vector<int>& postorder, int postLo, int postHi) {
        if (preLo > preHi) return NULL;
        TreeNode* root = new TreeNode(preorder[preLo]);
        if (preLo == preHi) return root;

        int i = postLo;
        while (i <= postHi) {
            if (postorder[i] == preorder[preLo + 1]) break;
            i++;
        }
        int leftCount = i - postLo;

        root->left = build(preorder, preLo + 1, preLo + leftCount + 1, postorder, postLo, i);
        root->right = build(preorder, preLo + leftCount + 2, preHi, postorder, i + 1, postHi - 1);

        return root;
    }

    TreeNode* constructFromPrePost(vector<int>& preorder, vector<int>& postorder) {
        int n = preorder.size();
        return build(preorder, 0, n - 1, postorder, 0, n - 1);
    }
};

// Helper function to print the tree in preorder (for validation)
void printPreorder(TreeNode* root) {
    if (root == NULL) return;
    cout << root->val << " ";
    printPreorder(root->left);
    printPreorder(root->right);
}

int main() {
    // Test case: Preorder and Postorder traversal arrays
    vector<int> preorder = {1, 2, 4, 5, 3, 6, 7};
    vector<int> postorder = {4, 5, 2, 6, 7, 3, 1};

    Solution sol;
    TreeNode* root = sol.constructFromPrePost(preorder, postorder);

    // Print the constructed tree in preorder to verify correctness
    cout << "Preorder traversal of the constructed tree: ";
    printPreorder(root);
    cout << endl;

    // Clean up dynamically allocated memory (optional for simple cases)
    delete root->left->left;   // 4
    delete root->left->right;  // 5
    delete root->left;         // 2
    delete root->right->left;  // 6
    delete root->right->right; // 7
    delete root->right;        // 3
    delete root;               // 1

    return 0;
}
