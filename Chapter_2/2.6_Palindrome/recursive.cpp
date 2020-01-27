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

class Result {
public:
    ListNode *node;
    bool result;

    Result(ListNode *_node, bool _result) {
        node = _node;
        result = _result;
    }
};

int length(ListNode *head) {
    int len = 0;
    while (head != nullptr) {
        len++;
        head = head->next;
    }
    return len;
}

Result isPalindromeRecurse(ListNode *head, int length) {
    if (head == nullptr || length <= 0) {
        Result res = Result(head, true);
        return res;
    } else if (length == 1) {
        Result res = Result(head->next, true);
        return res;
    }

    Result res = isPalindromeRecurse(head->next, length - 2);
    if (!res.result || res.node == nullptr) {
        return res;
    }
    res.result = (head->val == res.node->val);
    res.node = res.node->next;

    return res;
}

bool isPalindrome(ListNode *head) {
    int len = length(head);
    Result p = isPalindromeRecurse(head, len);
    return p.result;
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