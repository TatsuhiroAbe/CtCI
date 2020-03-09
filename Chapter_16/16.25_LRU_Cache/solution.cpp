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

class LinkedListNode {
public:
    int key;
    string value;
    LinkedListNode *prev;
    LinkedListNode *next;

    LinkedListNode(int k, string v) : key(k), value(v), prev(nullptr), next(nullptr) {}
};

class LRUCache {
private:
    int maxCacheSize;
    unordered_map<int, LinkedListNode*> hash;
    LinkedListNode *head;
    LinkedListNode *tail;

    void removeFromLinkedList(LinkedListNode *node) {
        if (node == nullptr) {
            return;
        }

        if (node->prev != nullptr) node->prev->next = node->next;
        if (node->next != nullptr) node->next->prev = node->prev;
        if (node == tail) tail = node->prev;
        if (node == head) head = node->next;
    }

    void insertAtFrontOfLinkedList(LinkedListNode *node) {
        if (head == nullptr) {
            head = node;
            tail = node;
        } else {
            head->prev = node;
            node->next = head;
            head = node;
        }
    }

    bool removeKey(int key) {
        LinkedListNode *node = hash[key];
        removeFromLinkedList(node);
        hash.erase(key);
        return true;
    }

public:
    LRUCache(int maxSize) : maxCacheSize(maxSize) {}

    string getValue(int key) {
        LinkedListNode *item = hash[key];
        if (item == nullptr) {
            return "-1";
        }

        if (item != head) {
            removeFromLinkedList(item);
            insertAtFrontOfLinkedList(item);
        }

        return item->value;
    }

    void setKeyValue(int key, string value) {
        removeKey(key);

        if (hash.size() >= maxCacheSize && tail != nullptr) {
            removeKey(tail->key);
        }

        LinkedListNode *node = new LinkedListNode(key, value);
        insertAtFrontOfLinkedList(node);
        hash[key] = node;
    }
};

int main() {
    int cache_size = 2;
    LRUCache cache(cache_size);

    cache.setKeyValue(1, "1");
    cache.setKeyValue(2, "2");
    cout << cache.getValue(1) << endl;
    cache.setKeyValue(3, "3");
    cout << cache.getValue(2) << endl;
    cache.setKeyValue(4, "4");
    cout << cache.getValue(1) << endl;
    cout << cache.getValue(3) << endl;
    cout << cache.getValue(4) << endl;

    return 0;
}