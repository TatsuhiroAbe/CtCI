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


bool isPalindrome(ListNode *head) {
    ListNode *slow = head;
    ListNode *fast = head;
    stack<int> st;
    while (fast != nullptr && fast->next != nullptr) {
        st.push(slow->val);
        slow = slow->next;
        fast = fast->next->next;
    }
    if (fast != nullptr) {
        slow = slow->next;
    }

    while (slow != nullptr) {
        if (st.top() != slow->val) {
            return false;
        }
        st.pop();
        slow = slow->next;
    }
    return true;
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