#include <iostream>
#include <cmath>
using namespace std;

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
    int height(TreeNode* root) {
        if (root == NULL) return 0;
        return max(1 + height(root->left), 1 + height(root->right));
    }

    int heightdiff(TreeNode* root) {
        int ans = 0;
        if (root == NULL) return 0;
        if (root->left == NULL && root->right == NULL) {
            return ans;
        } else if (root->right == NULL) {
            ans = height(root->left);
        } else if (root->left == NULL) {
            ans = height(root->right);
        } else {
            ans += abs(height(root->left) - height(root->right));
        }
        return ans;
    }

    bool isBalanced(TreeNode* root) {
        if (root == NULL) return 1;
        return ((abs(heightdiff(root) < 2)) && ((root->left != NULL) ? (isBalanced(root->left)) : 1) && ((root->right != NULL) ? (isBalanced(root->right)) : 1));
    }
};

int main() {
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);

    Solution sol;
    cout << sol.isBalanced(root) << endl;

    return 0;
}
