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

int length(ListNode *head) {
    int len = 0;
    while (head != nullptr) {
        len++;
        head = head->next;
    }
    return len;
}

ListNode *findIntersection(ListNode *l1, ListNode *l2) {
    int len1 = length(l1);
    int len2 = length(l2);

    if (len1 > len2) {
        for (int i = 0; i < len1 - len2; i++) {
            l1 = l1->next;
        }
    } else {
        for (int i = 0; i < len2 - len1; i++) {
            l2 = l2->next;
        }
    }

    while (l1 != l2) {
        l1 = l1->next;
        l2 = l2->next;
    }

    return l1;
}

int main() {
    // This is common part, that is 7 is the intersection.
    vector<int> commonValue{7, 2, 1};
    ListNode *dummyCommon = new ListNode(0);
    ListNode *curr = dummyCommon;
    for (int n : commonValue) {
        curr->next = new ListNode(n);
        curr = curr->next;
    }

    // list 1
    vector<int> values1{3, 1, 5, 9}, values2{4, 6};
    ListNode *dummy1 = new ListNode(0);
    curr = dummy1;
    for (int n : values1) {
        curr->next = new ListNode(n);
        curr = curr->next;
    }
    curr->next = dummyCommon->next; // 3 1 5 9 7 2 1

    // list 2
    ListNode *dummy2 = new ListNode(0);
    curr = dummy2;
    for (int n : values2) {
        curr->next = new ListNode(n);
        curr = curr->next;
    }
    curr->next = dummyCommon->next; // 4 6 7 2 1

    // find intersection (node which value is 7)
    ListNode *intersection = findIntersection(dummy1->next, dummy2->next);
    if (intersection != nullptr) {
        cout << intersection->val << endl; // 7
    } else {
        cout << "null" << endl;
    }

    return 0;
}