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

class MyQueue {
private:
    stack<int> newest;
    stack<int> oldest;

    void shiftStacks() {
        if (oldest.empty()) {
            while (!newest.empty()) {
                oldest.push(newest.top());
                newest.pop();
            }
        }
    }

public:
    MyQueue() {}

    void push(int x) {
        newest.push(x);
    }

    void pop() {
        shiftStacks();
        oldest.pop();
    }

    int front() {
        shiftStacks();
        return oldest.top();
    }
};

int main() {
    MyQueue myQueue = MyQueue();

    myQueue.push(1);
    myQueue.push(8);
    myQueue.push(5);
    cout << myQueue.front() << endl; // 1
    myQueue.pop();
    myQueue.push(10);
    cout << myQueue.front() << endl; // 8
    myQueue.pop();

    return 0;
}