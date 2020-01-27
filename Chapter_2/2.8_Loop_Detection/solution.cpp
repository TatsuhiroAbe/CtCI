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

ListNode *findBeginning(ListNode *head) {
    ListNode *slow = head;
    ListNode *fast = head;

    while (fast != nullptr && fast->next != nullptr) {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast) {
            break;
        }
    }

    if (fast == nullptr || fast->next == nullptr) {
        return nullptr;
    }

    slow = head;
    while (slow != fast) {
        slow = slow->next;
        fast = fast->next;
    }
    return slow;
}

int main() {
    vector<int> values{3, 2, 6, 8, 4};
    ListNode *start = new ListNode(values[0]);
    ListNode *curr = start;
    for (int i = 1; i < values.size(); i++) {
        curr->next = new ListNode(values[i]);
        curr = curr->next;
    }
    curr->next = start;

    ListNode *head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next  = new ListNode(5);
    head->next->next->next = start;

    /*
      1 -> 2 -> 5 -> 3
                  /    \
                4        2
                 \      /
                  8 <- 6
    */

    ListNode *beginning = findBeginning(head);
    cout << beginning->val << endl; // 3

    return 0;
}