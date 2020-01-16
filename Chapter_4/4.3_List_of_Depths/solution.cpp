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

void create(TreeNode *node, vector<list<TreeNode*>> &lists, int level) {
    if (node == nullptr) {
        return;
    }

    if (lists.size() == level) {
        lists.push_back(list<TreeNode*>());
    }

    lists[level].push_back(node);
    create(node->left, lists, level + 1);
    create(node->right, lists, level + 1);
}

vector<list<TreeNode*>> createLevelLinkedList(TreeNode *root) {
    vector<list<TreeNode*>> res;
    create(root, res, 0);
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

    vector<list<TreeNode*>> levelLinkedList = createLevelLinkedList(root);
    for (list<TreeNode*> &l : levelLinkedList) {
        while (!l.empty()) {
            cout << l.front()->val << " ";
            l.pop_front();
        }
        cout << endl;
    }

    return 0;
}