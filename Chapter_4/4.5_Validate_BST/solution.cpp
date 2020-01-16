#include <iostream>
#include <vector>
#include <list>
#include <stack>
#include <queue>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <string>
#include <algorithm>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

bool isValid(TreeNode *node, TreeNode *&prev) {
    if (node == nullptr) {
        return true;
    }
    if (!isValid(node->left, prev)) {
        return false;
    }
    if (prev != nullptr && prev->val >= node->val) {
        return false;
    }
    prev = node;
    return isValid(node->right, prev);
}

bool isValidBST(TreeNode *root) {
    TreeNode *prev = nullptr;
    return isValid(root, prev);
}

int main() {
    /*
             5
          /     \
        0         8
          \     /   \
           2   7    11
    */
    TreeNode *BST = new TreeNode(5);
    BST->left = new TreeNode(0);
    BST->right = new TreeNode(8);
    BST->left->right = new TreeNode(2);
    BST->right->left = new TreeNode(7);
    BST->right->right = new TreeNode(11);
    /*
             5
          /     \
        9         8
          \     /   \
           2   7    11
    */
    TreeNode *notBST = new TreeNode(5);
    notBST->left = new TreeNode(9);
    notBST->right = new TreeNode(8);
    notBST->left->right = new TreeNode(2);
    notBST->right->left = new TreeNode(7);
    notBST->right->right = new TreeNode(11);

    cout << isValidBST(BST) << endl; // true
    cout << isValidBST(notBST) << endl; // false

    return 0;
}