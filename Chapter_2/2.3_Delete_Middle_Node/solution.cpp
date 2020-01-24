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

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};


bool deleteNode(ListNode *node) {
    if (node == nullptr || node->next == nullptr) {
        return false;
    }

    ListNode *next = node->next;
    node->val = next->val;
    node->next = next->next;
    return true;
}

int main() {
    vector<int> values{3, 2, 5, 3, 4, 1, 2, 3, 6};
    ListNode *dummy = new ListNode(0);
    ListNode *curr = dummy;
    for (int n : values) {
        curr->next = new ListNode(n);
        curr = curr->next;
    }

    ListNode *toDelete = dummy->next->next->next->next->next; // 4
    deleteNode(toDelete);

    curr = dummy->next;
    while (curr != nullptr) {
        cout << curr->val << " ";
        curr = curr->next; // 3 2 5 3 1 2 3 6
    }

    return 0;
}
