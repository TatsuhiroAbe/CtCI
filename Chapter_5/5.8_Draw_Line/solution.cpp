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

void draw(vector<uint8_t> &screen, int width, int x1, int x2, int y) {
    int start_offset = x1 % 8;
    int first_full_byte = x1 / 8;
    if (start_offset != 0) {
        first_full_byte++;
    }

    int end_offset = x2 % 8;
    int last_full_byte = x2 / 8;
    if (end_offset != 7) {
        last_full_byte--;
    }

    for (int b = first_full_byte; b <= last_full_byte; b++) {
        screen[(width / 8) * y + b] = 0xFF;
    }

    uint8_t start_mask = (uint8_t )(0xFF >> start_offset);
    uint8_t end_mask = (uint8_t)~(0xFF >> (end_offset + 1));

    if ((x1 / 8) == (x2 / 8)) {
        uint8_t mask = (uint8_t)(start_mask & end_mask);
        screen[(width / 8) * y + (x1 / 8)] |= mask;
    } else {
        if (start_offset != 0) {
            int byte_number = (width / 8) * y + first_full_byte - 1;
            screen[byte_number] |= start_mask;
        }
        if (end_offset != 7) {
            int byte_number = (width / 8) * y + last_full_byte + 1;
            screen[byte_number] |= end_mask;
        }
    }
}

int main() {
    vector<uint8_t> screen(40);
    draw(screen, 8, 139, 170, 2);
    for (int i = 0; i < screen.size(); i++) {
        cout << bitset<8>(screen[i]) << " ";
        if (i % 8 == 7) cout << endl;
    }

    /*
        00000000 00000000 00000000 00000000 00000000 00000000 00000000 00000000
        00000000 00000000 00000000 00000000 00000000 00000000 00000000 00000000
        00000000 00000000 00000000 00011111 11111111 11111111 11111111 11100000
        00000000 00000000 00000000 00000000 00000000 00000000 00000000 00000000
        00000000 00000000 00000000 00000000 00000000 00000000 00000000 00000000
    */

    return 0;
}