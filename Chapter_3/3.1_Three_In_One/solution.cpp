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

class FixedMultiStack {
private:
    vector<int> array;
    int numberOfStack = 3;
    int stackCapacity;
    vector<int> sizes;

    int indexOfTop(int stackNum) {
        int offset = stackNum * stackCapacity;
        int size = sizes[stackNum];
        return offset + size - 1;
    }

public:
    FixedMultiStack(int n) {
        stackCapacity = n;
        array.resize(n);
        sizes.resize(numberOfStack);
    }

    void push(int stackNum, int x) {
        if (isFull(stackNum)) {
            cout << "full" << endl;
        }
        sizes[stackNum]++;
        array[indexOfTop(stackNum)] = x;
    }

    void pop(int stackNum) {
        if (isEmpty(stackNum)) {
            cout << "empty" << endl;
        }
        array[indexOfTop(stackNum)] = 0;
        sizes[stackNum]--;
    }

    int top(int stackNum) {
        if (isEmpty(stackNum)) {
            cout << "empty" << endl;
        }
        return array[indexOfTop(stackNum)];
    }

    bool isEmpty(int stackNum) {
        return sizes[stackNum] == 0;
    }

    bool isFull(int stackNum) {
        return sizes[stackNum] == stackCapacity;
    }
};

int main() {
    FixedMultiStack stack = FixedMultiStack(300);

    stack.push(0, 1);
    stack.push(0, 10);
    stack.push(1, 4);
    stack.push(2, 5);
    stack.push(2, 7);
    stack.push(2, 10);

    cout << stack.top(0) << endl; // 10
    stack.pop(0);
    cout << stack.top(0) << endl; // 1
    cout << stack.isEmpty(0) << endl; // false
    stack.pop(1);
    cout << stack.isEmpty(1) << endl; // true
    cout << stack.top(2) << endl; // 10

    return 0;
}