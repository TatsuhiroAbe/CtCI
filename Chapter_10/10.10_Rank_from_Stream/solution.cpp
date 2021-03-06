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
#include <cstddef>

using namespace std;

class RankNode {
public:
    int left_size = 0;
    RankNode *left;
    RankNode *right;
    int data;

    RankNode (int d) {
        data = d;
        left = nullptr;
        right = nullptr;
    }

    void insert(int d) {
        if (d <= data) {
            if (left != nullptr) {
                left->insert(d);
            } else {
                left = new RankNode(d);
            }
            left_size++;
        } else {
            if (right != nullptr) {
                right->insert(d);
            } else {
                right = new RankNode(d);
            }
        }
    }

    int getRank(int d) {
        if (d == data) {
            return left_size;
        } else if (d < data) {
            if (left == nullptr) {
                return -1;
            } else {
                return left->getRank(d);
            }
        } else {
            int right_rank = (right == nullptr) ? -1 : right->getRank(d);
            if (right_rank == -1) {
                return -1;
            } else {
                return left_size + 1 + right_rank;
            }
        }
    }
};

RankNode *root = nullptr;

void track(int num) {
    if (root == nullptr) {
        root = new RankNode(num);
    } else {
        root->insert(num);
    }
}

int getRank(int num) {
    return root->getRank(num);
}

int main() {
    vector<int> values{5, 1, 4, 4, 5, 9, 7, 13, 3};
    for (int n : values) {
        track(n);
    }

    cout << getRank(1) << endl; // 0
    cout << getRank(3) << endl; // 1
    cout << getRank(4) << endl; // 3

    return 0;
}