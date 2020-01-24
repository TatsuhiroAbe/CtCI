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

void removeDups(ListNode *head) {
    unordered_set<int> set;
    ListNode *prev = nullptr;
    while (head != nullptr) {
        if (set.find(head->val) != set.end()) {
            prev->next = head->next;
        } else {
            set.insert(head->val);
            prev = head;
        }
        head = head->next;
    }
}

int main() {
    vector<int> values{3, 2, 5, 3, 4, 1, 2, 3, 6};
    ListNode *dummy = new ListNode(0);
    ListNode *curr = dummy;
    for (int n : values) {
        curr->next = new ListNode(n);
        curr = curr->next;
    }

    removeDups(dummy->next);

    curr = dummy->next;
    while (curr != nullptr) {
        cout << curr->val << " "; // 3 2 5 4 1 6
        curr = curr->next;
    }

    return 0;
}

