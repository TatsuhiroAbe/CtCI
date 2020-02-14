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


struct Node {
    int data;
    Node *ptr1;
    Node *ptr2;
    Node() : ptr1(nullptr), ptr2(nullptr) {}
};

typedef map<Node*, Node*> NodeMap;

Node *copy_recursive(Node *curr, NodeMap &nodeMap) {
    if (curr == nullptr) {
        return nullptr;
    }

    NodeMap::iterator it = nodeMap.find(curr);
    if (it != nodeMap.end()) {
        return it->second;
    }

    Node *node = new Node;
    node->data = curr->data;
    nodeMap[curr] = node;
    node->ptr1 = copy_recursive(curr->ptr1, nodeMap);
    node->ptr2 = copy_recursive(curr->ptr2, nodeMap);
    return node;
}

Node *copy_structure(Node *curr) {
    NodeMap nodeMap;
    return copy_recursive(curr, nodeMap);
}

