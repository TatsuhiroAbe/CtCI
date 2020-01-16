#include <iostream>
#include <vector>
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

TreeNode *helper(vector<int> &array, int left, int right) {
    if (right < left) {
        return nullptr;
    }

    int mid = (left + right) / 2;
    TreeNode *root = new TreeNode(array[mid]);
    root->left = helper(array, left, mid - 1);
    root->right = helper(array, mid + 1, right);
    return root;
}

TreeNode *createMinimalBST(vector<int> &array) {
    return helper(array, 0, (int)array.size() - 1);
}

void inOrder(TreeNode *node, vector<int> &nums) {
    if (node == nullptr) {
        return;
    }

    inOrder(node->left, nums);
    nums.push_back(node->val);
    inOrder(node->right, nums);
}

bool isEqual(vector<int> a, vector<int> b) {
    if (a.size() != b.size()) {
        return false;
    }

    for (int i = 0; i < a.size(); i++) {
        if (a[i] != b[i]) return false;
    }

    return true;
}

int main() {
    vector<int> array{0, 2, 5, 7, 8, 11};

    TreeNode *root = createMinimalBST(array);
    /*
                 5
              /     \
            0         8
              \     /   \
               2   7    11
    */
    vector<int> nums;
    inOrder(root, nums);

    cout << isEqual(array, nums) << endl;
    return 0;
}