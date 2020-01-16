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
    TreeNode *parent;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr), parent(nullptr) {}
};

TreeNode *leftMostChild(TreeNode *node) {
    if (node == nullptr) {
        return nullptr;
    }

    while (node->left != nullptr) {
        node = node->left;
    }
    return node;
}

TreeNode *inorderSuccessor(TreeNode *node) {
    if (node == nullptr) {
        return nullptr;
    }

    if (node->right != nullptr) {
        return leftMostChild(node->right);
    } else {
        TreeNode *child = node;
        TreeNode *par = node->parent;
        while (par != nullptr && par->right == child) {
            child = par;
            par = par->parent;
        }
        return par;
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
    TreeNode *BST = new TreeNode(5);
    BST->left = new TreeNode(0);
    BST->left->parent = BST;
    BST->right = new TreeNode(8);
    BST->right->parent = BST;
    BST->left->right = new TreeNode(2);
    BST->left->right->parent = BST->left;
    BST->right->left = new TreeNode(7);
    BST->right->left->parent = BST->right;
    BST->right->right = new TreeNode(11);
    BST->right->right->parent = BST->right;

    TreeNode *successor = inorderSuccessor(BST->left->right);
    cout << successor->val << endl; // 7

    return 0;
}