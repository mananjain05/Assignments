#include <iostream>
#include <vector>
#include <algorithm> // For std::max
using namespace std;

// Define the BinaryTreeNode structure
template <typename T>
struct BinaryTreeNode {
    T data;
    BinaryTreeNode* left;
    BinaryTreeNode* right;

    BinaryTreeNode(T val) : data(val), left(nullptr), right(nullptr) {}
};

// Function prototypes
void preorder(BinaryTreeNode<int>* root, vector<int>& left, int level);
int levels(BinaryTreeNode<int>* root);
vector<int> printLeftView(BinaryTreeNode<int>* root);

void preorder(BinaryTreeNode<int>* root, vector<int>& left, int level) {
    if (root == nullptr) return;

    // Update the left view vector for the current level
    left[level] = root->data;

    // Recurse for right and left subtrees
    preorder(root->right, left, level + 1);
    preorder(root->left, left, level + 1);
}

int levels(BinaryTreeNode<int>* root) {
    if (root == nullptr) return 0;
    return 1 + max(levels(root->right), levels(root->left));
}

vector<int> printLeftView(BinaryTreeNode<int>* root) {
    int n = levels(root); // Get the number of levels in the tree
    vector<int> left(n, 0); // To store the left view of the tree
    preorder(root, left, 0); // Start preorder traversal from root
    return left; // Return the left view
}

int main() {
    // Create a sample binary tree
    BinaryTreeNode<int>* root = new BinaryTreeNode<int>(1);
    root->left = new BinaryTreeNode<int>(2);
    root->right = new BinaryTreeNode<int>(3);
    root->left->left = new BinaryTreeNode<int>(4);
    root->left->right = new BinaryTreeNode<int>(5);
    root->right->right = new BinaryTreeNode<int>(6);

    // Get the left view of the binary tree
    vector<int> leftView = printLeftView(root);

    // Print the left view
    cout << "Left View of the Binary Tree:" << endl;
    for (int val : leftView) {
        cout << val << " ";
    }
    cout << endl;

    // Cleanup dynamically allocated memory
    delete root->left->right;
    delete root->left->left;
    delete root->right->right;
    delete root->left;
    delete root->right;
    delete root;

    return 0;
}
