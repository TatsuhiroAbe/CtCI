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

class SetOfStack {
private:
    vector<stack<int>> stacks;
    int capacity;

    stack<int> getLastStack() {
        if (stacks.empty()) {
            return stack<int>();
        }
        return stacks[stacks.size() - 1];
    }

public:
    SetOfStack(int n) {
        capacity = n;
    }

    void push(int x) {
        if (stacks.empty()) {
            stack<int> newStack;
            newStack.push(x);
            stacks.push_back(newStack);
        } else {
            stack<int> lastStack = getLastStack();
            if (lastStack.size() < capacity) {
                stacks[stacks.size() - 1].push(x);
            } else {
                stack<int> newStack;
                newStack.push(x);
                stacks.push_back(newStack);
            }
        }
    }

    void pop() {
        stack<int> lastStack = getLastStack();
        lastStack.pop();
        if (lastStack.empty()) {
            stacks.pop_back();
        }
    }

    int top() {
        stack<int> lastStack = getLastStack();
        return lastStack.top();
    }

    int size() {
        if (isEmpty()) {
            return 0;
        }
        int numOfFullStacks = (int)stacks.size() - 1;
        return capacity * numOfFullStacks + (int)getLastStack().size();
    }

    int numOfStacks() {
        return (int)stacks.size();
    }

    bool isEmpty() {
        return stacks.empty();
    }
};

int main() {
    SetOfStack setOfStack = SetOfStack(3);

    for (int i = 0; i <= 15; i++) setOfStack.push(i);

    cout << setOfStack.size() << endl; // 16
    cout << setOfStack.numOfStacks() << endl; // 6
    cout << setOfStack.top() << endl; // 15
    setOfStack.push(16);
    setOfStack.push(17);
    setOfStack.push(18);
    cout << setOfStack.size() << endl; // 19
    cout << setOfStack.numOfStacks() << endl; // 7
    setOfStack.pop();
    setOfStack.pop();
    cout << setOfStack.size() << endl; // 17
    cout << setOfStack.numOfStacks() << endl; // 6

    return 0;
}