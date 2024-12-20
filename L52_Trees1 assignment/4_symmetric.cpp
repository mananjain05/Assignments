#include <iostream>
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
    bool isequal(TreeNode* l, TreeNode* r) {
        int ans = 1;
        if (l == NULL && r == NULL) return 1;
        else if (r == NULL || l == NULL) return 0;

        if (l->val != r->val) return 0;

        if (l->left == r->right) ans = ans & 1;
        else ans = ans & (isequal(l->left, r->right));

        if (l->right == r->left) ans = ans & 1;
        else ans = ans & (isequal(l->right, r->left));

        return ans;
    }

    bool isSymmetric(TreeNode* root) {
        if (root->left == NULL && root->right == NULL) return 1;
        else if (root->right == NULL || root->left == NULL) return 0;

        if (root->left == root->right) return 1;
        if (root->left->val == root->right->val) return (isequal(root->left, root->right));
        else return 0;
    }
};

int main() {
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(2);
    root->left->left = new TreeNode(3);
    root->left->right = new TreeNode(4);
    root->right->left = new TreeNode(4);
    root->right->right = new TreeNode(3);

    Solution sol;
    cout << sol.isSymmetric(root) << endl;

    return 0;
}
