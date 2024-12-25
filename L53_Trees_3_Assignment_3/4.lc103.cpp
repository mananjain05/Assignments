#include <iostream>
#include <vector>
#include <queue>
#include <stack>
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
    int levels(TreeNode* root) {
        if (root == NULL) return 0;
        return (1 + max(levels(root->left), levels(root->right)));
    }
    void zlorder(TreeNode* root, vector<vector<int>>& ans) {
        if (root == NULL) return;
        queue<TreeNode*> q;
        stack<TreeNode*> st;
        int i = 0;
        q.push(root);
        while (!q.empty()) {
            if (i % 2 != 0) {
                while (!q.empty()) {
                    st.push(q.front());
                    q.pop();
                }
                while (!st.empty()) {
                    TreeNode* temp = st.top();
                    if (temp->right) q.push(temp->right);
                    if (temp->left) q.push(temp->left);
                    st.pop();
                    ans[i].push_back(temp->val);
                }
                i++;
            } else {
                while (!q.empty()) {
                    st.push(q.front());
                    q.pop();
                }
                while (!st.empty()) {
                    TreeNode* temp = st.top();
                    if (temp->left) q.push(temp->left);
                    if (temp->right) q.push(temp->right);
                    st.pop();
                    ans[i].push_back(temp->val);
                }
                i++;
            }
        }
    }
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        int n = levels(root);
        vector<vector<int>> ans(n);
        zlorder(root, ans);
        return ans;
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
    vector<vector<int>> result = solution.zigzagLevelOrder(root);

    for (const auto& level : result) {
        for (int val : level) {
            cout << val << " ";
        }
        cout << endl;
    }

    return 0;
}
