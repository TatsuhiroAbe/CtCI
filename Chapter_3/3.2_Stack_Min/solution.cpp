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

class MinStack {
private:
    stack<int> s1;
    stack<int> s2;

public:
    MinStack() {}

    void push(int x) {
        s1.push(x);
        if (s2.empty() || x <= getMin()) {
            s2.push(x);
        }
    }

    void pop() {
        if (s1.top() == getMin()) {
            s2.pop();
        }
        s1.pop();
    }

    int top() {
        return s1.top();
    }

    int getMin() {
        return s2.top();
    }
};

int main() {
    MinStack minStack = MinStack();

    minStack.push(-2);
    minStack.push(0);
    minStack.push(-3);
    cout << minStack.getMin() << endl; // -3
    minStack.pop();
    cout << minStack.top() << endl; // 0
    cout << minStack.getMin() << endl; // -2

    return 0;
}