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

int findPath(TreeNode *root, int sum, int curr) {
    if (root == nullptr) {
        return 0;
    }
    curr += root->val;
    int res = (curr == sum);
    res += findPath(root->left, sum, curr) + findPath(root->right, sum, curr);
    return res;
}

int pathSum(TreeNode *root, int sum) {
    if (root == nullptr) {
        return 0;
    }

    int res = findPath(root, sum, 0);
    res += pathSum(root->left, sum) + pathSum(root->right, sum);
    return res;
}

int main() {
    /*
              10
             /  \
            5   -3
           / \    \
          3   2   11
         / \   \
        3  -2   1
    */
    TreeNode *root = new TreeNode(10);
    root->left = new TreeNode(5);
    root->right = new TreeNode(-3);
    root->left->left = new TreeNode(3);
    root->left->right = new TreeNode(2);
    root->right->right = new TreeNode(11);
    root->left->left->left = new TreeNode(3);
    root->left->left->right = new TreeNode(-2);
    root->left->right->right = new TreeNode(1);

    cout << pathSum(root, 8) << endl; // 3
    return 0;
}