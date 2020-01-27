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

ListNode *helper(ListNode *head, int k, int &i) {
    if (head == nullptr) {
        return nullptr;
    }
    ListNode *node = helper(head->next, k, i);
    i++;
    if (i == k) {
        return head;
    }
    return node;
}

ListNode *nthToLast(ListNode *head, int k) {
    int i = 0;
    return helper(head, k, i);
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
