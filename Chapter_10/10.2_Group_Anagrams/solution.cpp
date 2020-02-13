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
#include <cstddef>

using namespace std;


static bool compare(string a, string b) {
    string s = a;
    string t = b;
    sort(s.begin(), s.end());
    sort(t.begin(), t.end());
    return s < t;
}

void sortStrings(vector<string> &array) {
    int n = (int)array.size();
    if (n < 2) {
        return;
    }

    sort(array.begin(), array.end(), compare);
}

int main() {
    vector<string> array{"apple", "banana", "carrot", "ele", "duck", "papel", "tarroc", "cudk", "eel", "lee"};
    sortStrings(array);
    for (int i = 0; i < array.size(); i++) {
        cout << array[i] << endl;
    }
    return 0;
}