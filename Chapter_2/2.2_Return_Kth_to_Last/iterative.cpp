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

ListNode *nthToLast(ListNode *head, int k) {
    ListNode *p1 = head;
    ListNode *p2 = head;

    for (int i = 0; i < k; i++) {
        if (p1 == nullptr) return nullptr;
        p1 = p1->next;
    }

    while (p1 != nullptr) {
        p1 = p1->next;
        p2 = p2->next;
    }
    return p2;
}

int main() {
    vector<int> values{3, 2, 5, 3, 4, 1, 2, 3, 6};
    ListNode *dummy = new ListNode(0);
    ListNode *curr = dummy;
    for (int n : values) {
        curr->next = new ListNode(n);
        curr = curr->next;
    }

    ListNode *kthNode = nthToLast(dummy->next, 3);

    cout << kthNode->val << endl; // 2

    return 0;
}