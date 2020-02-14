#include <iostream>
#include <fstream>
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


void reverse(char* str) {
    char *end = str;
    char tmp;
    if (str) {
        while (*end) {
            end++;
        }
        end--;

        while (str < end) {
            tmp = *str;
            *str++ = *end;
            *end-- = tmp;
        }
    }
}

int main() {
    char str[100] = "abcdef";
    reverse(str);
    cout << str << endl; // fedcba
}