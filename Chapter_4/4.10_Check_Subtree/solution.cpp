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

bool isEqual(TreeNode *s, TreeNode *t) {
    if (s == nullptr && t == nullptr) {
        return true;
    }
    if (s == nullptr || t == nullptr) {
        return false;
    }
    if (s->val != t->val) {
        return false;
    }

    return isEqual(s->left, t->left) && isEqual(s->right, t->right);
}

bool isSubtree(TreeNode *s, TreeNode *t) {
    if (s == nullptr) {
        return false;
    }
    if (isEqual(s, t)) {
        return true;
    }

    return isSubtree(s->left, t) || isSubtree(s->right, t);
}

int main() {
    /*
             5
          /     \
        0         8
          \     /   \
           2   7    11
    */
    TreeNode *s = new TreeNode(5);
    s->left = new TreeNode(0);
    s->right = new TreeNode(8);
    s->left->right = new TreeNode(2);
    s->right->left = new TreeNode(7);
    s->right->right = new TreeNode(11);
    /*
              8
            /   \
           7     11
    */
    TreeNode *t = new TreeNode(8);
    t->left = new TreeNode(7);
    t->right = new TreeNode(11);

    cout << isSubtree(s, t) << endl; // true
    return 0;
}