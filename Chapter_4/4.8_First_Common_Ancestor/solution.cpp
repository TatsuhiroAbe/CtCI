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

TreeNode *commonAncestor(TreeNode *root, TreeNode *p, TreeNode *q) {
    if (root == nullptr || root == p || root == q) {
        return root;
    }

    TreeNode *left = commonAncestor(root->left, p, q);
    TreeNode *right = commonAncestor(root->right, p, q);

    if (left && right) {
        return root;
    } else {
        return left ? left : right;
    }
}

int main() {
    /*
             5
          /     \
        0         8
          \     /   \
           2   7    11
    */
    TreeNode *root = new TreeNode(5);
    root->left = new TreeNode(0);
    root->right = new TreeNode(8);
    root->left->right = new TreeNode(2);
    root->right->left = new TreeNode(7);
    root->right->right = new TreeNode(11);

    TreeNode *common = commonAncestor(root, root->right->right, root->right);
    cout << common->val << endl; // 8

    return 0;
}