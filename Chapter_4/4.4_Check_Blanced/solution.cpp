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

int height(TreeNode *root) {
    if (root == nullptr) {
        return 0;
    }

    return max(height(root->left), height(root->right)) + 1;
}

bool isBalanced(TreeNode *root) {
    if (root == nullptr) {
        return true;
    }

    int left = height(root->left);
    int right = height(root->right);
    if (abs(left - right) > 1) {
        return false;
    } else {
        return isBalanced(root->left) && isBalanced(root->right);
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
    TreeNode *balanced = new TreeNode(5);
    balanced->left = new TreeNode(0);
    balanced->right = new TreeNode(8);
    balanced->left->right = new TreeNode(2);
    balanced->right->left = new TreeNode(7);
    balanced->right->right = new TreeNode(11);
    /*
             5
                \
                  8
                    \
                    11
    */
    TreeNode *notBalanced = new TreeNode(5);
    notBalanced->right = new TreeNode(8);
    notBalanced->right->right = new TreeNode(11);

    cout << isBalanced(balanced) << endl; // true
    cout << isBalanced(notBalanced) << endl; // false

    return 0;
}