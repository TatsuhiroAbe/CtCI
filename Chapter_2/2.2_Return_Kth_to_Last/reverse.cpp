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

ListNode *reverse(ListNode *head) {
    ListNode *prev = nullptr;
    while (head != nullptr) {
        ListNode *node = new ListNode(head->val);
        node->next = prev;
        prev = node;
        head = head->next;
    }
    return prev;
}

ListNode *nthToLast(ListNode *head, int k) {
    ListNode *reversed = reverse(head);
    ListNode *curr = reversed;
    int count = 1;
    while (curr != nullptr && count < k) {
        curr = curr->next;
        count++;
    }
    return curr;
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

