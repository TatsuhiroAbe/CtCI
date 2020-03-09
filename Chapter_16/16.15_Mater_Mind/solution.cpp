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

class Result {
public:
    int hits;
    int pseudoHits;

    Result() {}
};

int getCode(char c) {
    switch (c) {
        case 'B':
            return 0;
        case 'G':
            return 1;
        case 'R':
            return 2;
        case 'Y':
            return 3;
        default:
            return -1;
    }
}

Result estimate(string guess, string solution) {
    Result res;
    vector<int> frequencies(4);

    for (int i = 0; i < guess.size(); i++) {
        if (guess[i] == solution[i]) {
            res.hits++;
        } else {
            int code = getCode(solution[i]);
            frequencies[code]++;
        }
    }

    for (int i = 0; i < guess.size(); i++) {
        int code = getCode(guess[i]);
        if (code > 0 && frequencies[code] && guess[i] != solution[i]) {
            res.pseudoHits++;
            frequencies[code]--;
        }
    }

    return res;
}

int main() {
    string guess = "GGRR";
    string solution = "RGBY";

    Result res = estimate(guess, solution);

    cout << "hits: " << res.hits << ", pseudoHits: " << res.pseudoHits << endl;

    return 0;
}