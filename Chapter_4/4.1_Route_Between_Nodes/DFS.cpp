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

bool dfs(vector<vector<int>> &G, int u, int end, vector<bool> &visited) {
    if (u == end) {
        return true;
    }

    visited[u] = true;
    bool res = false;
    for (int v : G[u]) {
        if (visited[v]) continue;
        res |= dfs(G, v, end, visited);
    }
    return res;
}

bool search(vector<vector<int>> &G, int start, int end) {
    if (G.empty()) {
        return false;
    }

    int n = (int)G.size();
    vector<bool> visited(n, false);
    return dfs(G, start, end, visited);
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