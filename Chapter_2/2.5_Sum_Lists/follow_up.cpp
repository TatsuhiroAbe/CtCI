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

class PartialSum {
public:
    ListNode *sum = nullptr;
    int carry = 0;
};

int length(ListNode *l) {
    int len = 0;
    while (l != nullptr) {
        len++;
        l = l->next;
    }
    return len;
}

ListNode* insertBefore(ListNode *l, int val) {
    ListNode *node = new ListNode(val);
    if (l != nullptr) {
        node->next = l;
    }
    return node;
}

ListNode* padList(ListNode *l, int padding) {
    ListNode *head = l;
    for (int i = 0; i < padding; i++) {
        insertBefore(head, 0);
    }
    return head;
}

PartialSum addListsHelper(ListNode *l1, ListNode *l2) {
    if (l1 == nullptr && l2 == nullptr) {
        PartialSum sum = PartialSum();
        return sum;
    }

    PartialSum sum = addListsHelper(l1->next, l2->next);
    int val = sum.carry + l1->val + l2->val;
    ListNode *full_result = insertBefore(sum.sum, val % 10);

    sum.sum = full_result;
    sum.carry = val / 10;
    return sum;
}

ListNode* addLists(ListNode *l1, ListNode *l2) {
    int len1 = length(l1);
    int len2 = length(l2);

    if (len1 < len2) {
        padList(l1, len2 - len1);
    } else {
        padList(l2, len1 - len2);
    }

    PartialSum sum = addListsHelper(l1, l2);

    if (sum.carry == 0) {
        return sum.sum;
    } else {
        ListNode *res = insertBefore(sum.sum, sum.carry);
        return res;
    }
}

int main() {
    ListNode *l1 = new ListNode(7);
    l1->next = new ListNode(1);
    l1->next->next = new ListNode(6); // 7 -> 1 -> 6

    ListNode *l2 = new ListNode(5);
    l2->next = new ListNode(9);
    l2->next->next = new ListNode(2); // 5 -> 9 -> 2

    ListNode *head = addLists(l1, l2);
    while (head != nullptr) {
        cout << head->val << " "; // 1 -> 3 -> 0 -> 8
        head = head->next;
    }
    return 0;
}