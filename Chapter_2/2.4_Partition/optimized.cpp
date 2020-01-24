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

ListNode *partition(ListNode *node, int x) {
    ListNode *head = node;
    ListNode *tail = node;

    while (node != nullptr) {
        ListNode *next = node->next;
        if (node->val < x) {
            node->next = head;
            head = node;
        } else {
            tail->next = node;
            tail = node;
        }
        node = next;
    }
    tail->next = nullptr;

    return head;
}

int main() {
    vector<int> values{3, 10, 5, 8, 4, 1, 2, 9, 6};
    ListNode *dummy = new ListNode(0);
    ListNode *curr = dummy;
    for (int n : values) {
        curr->next = new ListNode(n);
        curr = curr->next;
    }

    ListNode *parted = partition(dummy->next, 5);

    curr = parted;
    while (curr != nullptr) {
        cout << curr->val << " "; // 2 1 4 3 10 5 8 9 6
        curr = curr->next;
    }

    return 0;
}
