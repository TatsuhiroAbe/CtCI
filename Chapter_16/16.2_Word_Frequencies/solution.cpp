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

vector <string> getLongTextAsVector(string text) {
    vector <string> res;
    string word;
    for (char c : text) {
        if (c == ' ') {
            res.push_back(word);
            word = "";
        } else {
            if (isalpha(c)) {
                word += c;
            }
        }
    }
    return res;
}

void toLower(char &c) {
    if (c >= 'A' && c <= 'Z') {
        c = c - ('A' - 'a');
    }
}

void toLower(string &s) {
    for (char &c : s) {
        toLower(c);
    }
}

unordered_map<string, int> setupDictionary(vector <string> &book) {
    unordered_map<string, int> res;
    for (string &s : book) {
        toLower(s);
        res[s]++;
    }
    return res;
}

int getFrequency(unordered_map<string, int> &dictionary, string word) {
    toLower(word);
    return dictionary[word];
}

int main() {
    string text = "Lorem Ipsum is simply dummy text of the printing and typesetting industry. "
                  "Lorem Ipsum has been the industry's standard dummy text ever since the 1500s, "
                  "when an unknown printer took a galley of type and scrambled it to make a type specimen book. "
                  "It has survived not only five centuries, but also the leap into electronic typesetting, "
                  "remaining essentially unchanged. It was popularised in the 1960s with the release of Letraset "
                  "sheets containing Lorem Ipsum passages, and more recently with desktop publishing software like "
                  "Aldus PageMaker including versions of Lorem Ipsum.";
    vector <string> book = getLongTextAsVector(text);
    unordered_map<string, int> dictionary = setupDictionary(book);

    vector <string> words{"the", "it"};
    for (string word : words) {
        cout << getFrequency(dictionary, word) << endl;
    }

    return 0;
}
