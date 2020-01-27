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

bool search(vector<vector<int>> &G, int start, int end) {
    if (G.empty()) {
        return false;
    }

    int n = (int)G.size();
    queue<int> q;
    vector<bool> visited(n, false);
    q.push(start);
    visited[start] = true;

    while (!q.empty()) {
        int u = q.front(); q.pop();
        for (int v : G[u]) {
            if (visited[v]) continue;
            if (v == end) {
                return true;
            }
            visited[v] = true;
            q.push(v);
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