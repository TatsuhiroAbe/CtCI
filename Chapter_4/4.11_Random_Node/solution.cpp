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

class TreeNode {
public:
    int val;
    TreeNode *left;
    TreeNode *right;
    int size;

    TreeNode(int x) {
        val = x;
        left = nullptr;
        right = nullptr;
        size = 1;
    }

    TreeNode *getRandomNode() {
        int leftSize = (left == nullptr) ? 0 : left->size;
        srand(time(nullptr));
        int randomIndex = rand() % size;
        if (randomIndex < leftSize) {
            return left->getRandomNode();
        } else if (randomIndex == leftSize) {
            return this;
        } else {
            return right->getRandomNode();
        }
    }

    void insertInOrder(int n) {
        if (n <= val) {
            if (left == nullptr) {
                left = new TreeNode(n);
            } else {
                left->insertInOrder(n);
            }
        } else {
            if (right == nullptr) {
                right = new TreeNode(n);
            } else {
                right->insertInOrder(n);
            }
        }
        size++;
    }

    TreeNode *find(int n) {
        if (n == val) {
            return this;
        } else if (n < val) {
            return left != nullptr ? left->find(n) : nullptr;
        } else {
            return right != nullptr ? right->find(n) : nullptr;
        }
    }
};

int main() {
    TreeNode root = TreeNode(50);
    root.insertInOrder(60);
    cout << root.getRandomNode()->val << endl;
    root.insertInOrder(20);
    root.insertInOrder(10);
    cout << root.getRandomNode()->val << endl;
    root.insertInOrder(5);
    root.insertInOrder(100);
    cout << root.getRandomNode()->val << endl;

    return 0;
}