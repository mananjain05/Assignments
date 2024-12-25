#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    int level(TreeNode* root) {
        if (root == NULL) return 0;
        return (1 + max(level(root->left), level(root->right)));
    }
    void bfs(TreeNode* root, vector<vector<int>>& ans) {
        if (root == NULL) return;
        queue<TreeNode*> q;
        q.push(root);
        while (q.size()) {
            int n = q.size();
            vector<int> temp1;
            for (int i = 0; i < n; i++) {
                TreeNode* temp = q.front();
                q.pop();
                
                if (temp->right) q.push(temp->right);
                if (temp->left) q.push(temp->left);
                temp1.push_back(temp->val);
            }
            ans.push_back(temp1);
        }
    }
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> v;
        bfs(root, v);
        return v;
    }
};

int main() {
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(7);

    Solution solution;
    vector<vector<int>> result = solution.levelOrder(root);

    for (const auto& level : result) {
        for (int val : level) {
            cout << val << " ";
        }
        cout << endl;
    }

    return 0;
}
