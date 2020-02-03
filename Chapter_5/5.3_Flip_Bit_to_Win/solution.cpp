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

vector<int> getAlternatingSequences(int n) {
    vector<int > sequences;

    int searching = 0;
    int count = 0;

    for (int i = 0; i < 32; i++) {
        if ((n & 1) != searching) {
            sequences.push_back(count);
            searching = n & 1;
            count = 0;
        }
        count++;
        n >>= 1;
    }
    sequences.push_back(count);

    return sequences;
}

int findLongestSequence(vector<int> &sequence) {
    int res = 1;

    for (int i = 0; i < sequence.size(); i += 2) {
        int leftOnes = (i + 1 < sequence.size()) ? sequence[i + 1] : 0;
        int rightOnes = (i > 0) ? sequence[i - 1] : 0;

        if (sequence[i] == 1) {
            res = max(res, leftOnes + 1 + rightOnes);
        } else if (sequence[i] > 1) {
            res = max(res, max(leftOnes, rightOnes) + 1);
        } else {
            res = max(leftOnes, rightOnes);
        }
    }

    return res;
}

int longestSequence(int n) {
    vector<int> sequence = getAlternatingSequences(n);
    return findLongestSequence(sequence);
}

int main() {
    cout << longestSequence(1775) << endl;
    return 0;
}