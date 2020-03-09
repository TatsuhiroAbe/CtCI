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


vector<string> smalls{"Zero", "One", "Two", "Three", "Four", "Five", "Six", "Seven",
                      "Eight", "Nine", "Ten", "Eleven", "Twelve", "Thirteen", "Fourteen",
                      "Fifteen", "Sixteen", "Seventeen", "Eighteen", "Nineteen"};
vector<string> tens{"", "", "Twenty", "Thirty", "Forty", "Fifty", "Sixty", "Seventy", "Eighty", "Ninety"};
vector<string> bigs{"", "Thousand", "Million", "Billion"};
string hundred = "Hundred";
string negative = "Negative";

string listToString(list<string> &parts) {
    string res;
    while (parts.size() > 1) {
        res += parts.front() + " ";
        parts.pop_front();
    }
    res += parts.front();
    return res;
}

string convertChunk(int num) {
    list<string> parts;

    if (num >= 100) {
        parts.push_back(smalls[num / 100]);
        parts.push_back(hundred);
        num %= 100;
    }

    if (num >= 10 && num <= 19) {
        parts.push_back(smalls[num]);
    } else if (num >= 20) {
        parts.push_back(tens[num / 10]);
        num %= 10;
    }

    if (num >= 1 && num <= 9) {
        parts.push_back(smalls[num]);
    }

    return listToString(parts);
}

string convert(int num) {
    if (num == 0) {
        return smalls[0];
    } else if (num < 0) {
        return negative + " " + convert(-num);
    }

    list<string> parts;
    int chunkCount = 0;

    while (num > 0) {
        if (num % 1000 != 0) {
            string chunk = convertChunk(num % 1000) + " " + bigs[chunkCount];
            parts.push_front(chunk);
        }
        num /= 1000;
        chunkCount++;
    }

    return listToString(parts);
}


int main() {
    int num1 = 19323984;
    int num2 = -473917209;
    cout << convert(num1) << endl;
    cout << convert(num2) << endl;
    return 0;
}