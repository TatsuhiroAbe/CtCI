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

unordered_map<string, vector<string>> buildGraph(vector<string> &projects, vector<vector<string>> &dependencies) {
    unordered_map<string, vector<string>> graph;
    for (int i = 0; i < projects.size(); i++) {
        graph[projects[i]] = vector<string>();
    }
    for (int i = 0; i < dependencies.size(); i++) {
        graph[dependencies[i][0]].push_back(dependencies[i][1]);
    }
    return graph;
}

unordered_map<string, int> countDependencies(vector<string> &projects, vector<vector<string>> &dependencies) {
    unordered_map<string, int> cnt;
    for (int i = 0; i < projects.size(); i++) {
        cnt[projects[i]] = 0;
    }
    for (int i = 0; i < dependencies.size(); i++) {
        cnt[dependencies[i][1]]++;
    }
    return cnt;
}

vector<string> buildOrder(vector<string> &projects, vector<vector<string>> &dependencies) {
    unordered_map<string, vector<string>> graph = buildGraph(projects, dependencies);
    unordered_map<string, int> count = countDependencies(projects, dependencies);

    queue<string> que;
    for (pair<string, int> p : count) {
        if (p.second == 0) que.push(p.first);
    }
    vector<string> order;
    while (!que.empty()) {
        string project = que.front(); que.pop();
        order.push_back(project);
        for (string &s : graph[project]) {
            count[s]--;
            if (count[s] == 0) {
                que.push(s);
            }
        }
    }

    if (order.size() == projects.size()) {
        return order;
    } else {
        return vector<string>();
    }
}

int main() {
    vector<string> projects{"a", "b", "c", "d", "e", "f", "g", "h", "i", "j"};
    vector<vector<string>> dependencies{
            {"a", "b"},
            {"b", "c"},
            {"a", "c"},
            {"d", "e"},
            {"b", "d"},
            {"e", "f"},
            {"a", "f"},
            {"h", "i"},
            {"h", "j"},
            {"i", "j"},
            {"g", "j"}
    };

    vector<string> order = buildOrder(projects, dependencies);
    if (order.empty()) {
        cout << "Error" << endl;
    } else {
        for (string &s : order) {
            cout << s << " ";
        }
    }

    return 0;
}