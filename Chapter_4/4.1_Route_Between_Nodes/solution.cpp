#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <string>
#include <algorithm>
using namespace std;

bool search(vector<vector<int>> &G, int start, int end) {
    queue<int> q;
    q.push(start);
    vector<bool> visited(G.size(), false);
    visited[start] = true;

    while (!q.empty()) {
        int u = q.front(); q.pop();
        for (int v : G[u]) {
            if (visited[v]) continue;

            if (v == end) {
                return true;
            } else {
                visited[v] = true;
                q.push(v);
            }
        }
    }
    return false;
}

int main() {
    vector<vector<int>> G{{},
                          {},
                          {3},
                          {1},
                          {0, 1},
                          {2, 0}};
    cout << search(G, 5, 4) << endl; // false;
    cout << search(G, 5, 1) << endl; // true;
    return 0;
}