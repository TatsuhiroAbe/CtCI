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

bool isEqual(ListNode *l1, ListNode *l2) {
    while (l1 != nullptr && l2 != nullptr) {
        if (l1->val != l2->val) {
            return false;
        }
        l1 = l1->next;
        l2 = l2->next;
    }
    return (l1 == nullptr && l2 == nullptr);
}

bool isPalindrome(ListNode *head) {
    ListNode *reversed = reverse(head);
    return isEqual(head, reversed);
}

int main() {
    vector<int> values{1, 2, 3, 2, 1};
    ListNode *dummy = new ListNode(0);
    ListNode *curr = dummy;
    for (int n : values) {
        curr->next = new ListNode(n);
        curr = curr->next;
    }

    cout << isPalindrome(dummy->next) << endl; // true
    return 0;
}