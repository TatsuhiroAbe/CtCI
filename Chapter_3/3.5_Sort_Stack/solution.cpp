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

void sortStack(stack<int> &s) {
    stack<int> t;
    while (!s.empty()) {
        int temp = s.top(); s.pop();
        while (!t.empty() && t.top() > temp) {
            s.push(t.top());
            t.pop();
        }
        t.push(temp);
    }

    while (!t.empty()) {
        s.push(t.top());
        t.pop();
    }
}

int main() {
    stack<int> s;

    vector<int> values{2, 4, 1, 0, -1, 7, 4, 12};
    for (int n : values) s.push(n);

    sortStack(s);
    while (!s.empty()) {
        cout << s.top() << " "; // -1 0 1 2 4 4 7 12
        s.pop();
    }

    return 0;
}