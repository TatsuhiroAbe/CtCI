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

void weaveLists(list<int> &first, list<int> &second, vector<list<int>> &weaved, list<int> &prefix) {
    if (first.empty() || second.empty()) {
        list<int> res;
        res = prefix;
        for (int n : first) res.push_back(n);
        for (int n : second) res.push_back(n);
        weaved.push_back(res);
        return;
    }

    int headFirst = first.front(); first.pop_front();
    prefix.push_back(headFirst);
    weaveLists(first, second, weaved, prefix);
    prefix.pop_back();
    first.push_front(headFirst);

    int secondHead = second.front(); second.pop_front();
    prefix.push_back(secondHead);
    weaveLists(first, second, weaved, prefix);
    prefix.pop_back();
    second.push_front(secondHead);
}

vector<list<int>> allSequences(TreeNode *root) {
    vector<list<int>> res;
    if (root == nullptr) {
        res.push_back(list<int>());
        return res;
    }

    list<int> prefix;
    prefix.push_back(root->val);

    vector<list<int>> leftSequences = allSequences(root->left);
    vector<list<int>> rightSequences = allSequences(root->right);

    for (list<int> &left : leftSequences) {
        for (list<int> &right : rightSequences) {
            vector<list<int>> weaved;
            weaveLists(left, right, weaved, prefix);
            for (list<int> &sequence : weaved) {
                res.push_back(sequence);
            }
        }
    }

    return res;
}

int main() {
    /*
               50
             /    \
            20    60
           / \      \
          10   25    70
         / \        /  \
        5  15      65  80
    */
    TreeNode *root = new TreeNode(50);
    root->left = new TreeNode(20);
    root->right = new TreeNode(60);
    root->left->left = new TreeNode(10);
    root->left->right = new TreeNode(25);
    root->right->right = new TreeNode(70);
    root->left->left->left = new TreeNode(5);
    root->left->left->right = new TreeNode(15);
    root->right->right->left = new TreeNode(65);
    root->right->right->right = new TreeNode(80);

    vector<list<int>> sequences = allSequences(root);
    for (list<int> &sequence : sequences) {
        for (int n : sequence) {
            cout << n << " ";
        }
        cout << endl;
    }

    return 0;
}