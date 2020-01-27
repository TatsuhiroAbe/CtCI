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

ListNode *partition(ListNode *head, int x) {
    ListNode *beforeStart = nullptr;
    ListNode *beforeEnd = nullptr;
    ListNode *afterStart = nullptr;
    ListNode *afterEnd = nullptr;

    while (head != nullptr) {
        ListNode *next = head->next;
        head->next = nullptr;
        if (head->val < x) {
            if (beforeStart == nullptr) {
                beforeStart = head;
                beforeEnd = head;
            } else {
                beforeEnd->next = head;
                beforeEnd = beforeEnd->next;
            }
        } else {
            if (afterStart == nullptr) {
                afterStart = head;
                afterEnd = head;
            } else {
                afterEnd->next = head;
                afterEnd = afterEnd->next;
            }
        }
        head = next;
    }

    if (beforeStart == nullptr) return afterStart;

    beforeEnd->next = afterStart;
    return beforeStart;
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
        cout << curr->val << " "; // 3 4 1 2 10 5 8 9 6
        curr = curr->next;
    }

    return 0;
}
