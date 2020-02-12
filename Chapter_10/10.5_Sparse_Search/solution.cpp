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


int helper(vector<string> &strings, string str, int first, int last) {
    if (first > last) {
        return -1;
    }
    int mid = (first + last) / 2;

    if (strings[mid].empty()) {
        int left = mid - 1;
        int right = mid + 1;
        while (true) {
            if (left < first && right > last) {
                return -1;
            } else if (left >= first && !strings[left].empty()) {
                mid = left;
                break;
            } else if (right <= last && !strings[right].empty()) {
                mid = right;
                break;
            }
            left--;
            right++;
        }
    }

    if (strings[mid] == str) {
        return mid;
    } else if (str < strings[mid]) {
        return helper(strings, str, first, mid - 1);
    } else {
        return helper(strings, str, mid + 1, last);
    }
}

int search(vector<string> &strings, string str) {
    return helper(strings, str, 0, (int)strings.size() - 1);
}

int main() {
    vector<string> strings{"at", "", "", "", "ball", "", "", "car", "", "", "dad", "", ""};
    cout << search(strings, "ball") << endl; // 4
    return 0;
}