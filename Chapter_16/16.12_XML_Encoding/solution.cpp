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


class Attribute {
public:
    string tag;
    string value;

    Attribute(string t, string v) : tag(t), value(v) {}

    string getTagCode() {
        if (tag == "family") {
            return "1";
        } else if (tag == "person") {
            return "2";
        } else if (tag == "firstName") {
            return "3";
        } else if (tag == "lastName") {
            return "4";
        } else if (tag == "state") {
            return "5";
        } else {
            return "--";
        }
    }
};

class Element {
public:
    vector<Attribute> attributes;
    vector<Element> children;
    string name;
    string value;

    Element(string n) : name(n) {}

    Element(string n, string v) : name(n), value(v) {}

    string getNameCode() {
        if (name == "family") {
            return "1";
        } else if (name == "person") {
            return "2";
        } else if (name == "firstName") {
            return "3";
        } else if (name == "lastName") {
            return "4";
        } else if (name == "state") {
            return "5";
        } else {
            return "--";
        }
    }

    void insert(Attribute attribute) {
        attributes.push_back(attribute);
    }

    void insert(Element child) {
        children.push_back(child);
    }
};

void encode(string v, string &s) {
    s += v + " ";
}

void encode(Attribute attribute, string &s) {
    encode(attribute.getTagCode(), s);
    encode(attribute.value, s);
}

void encode(Element root, string &s) {
    encode(root.getNameCode(), s);
    for (Attribute &a : root.attributes) {
        encode(a, s);
    }
    encode("0", s);
    if (!root.value.empty()) {
        encode(root.value, s);
    } else {
        for (Element &child : root.children) {
            encode(child, s);
        }
    }
    encode("0", s);
}

string encodeToString(Element root) {
    string res;
    encode(root, res);
    return res;
}

int main() {
    Element root("family");
    Attribute a1("lastName", "mcdowell");
    Attribute a2("state", "CA");
    root.insert(a1);
    root.insert(a2);

    Element child("person", "Some Message");
    Attribute a3("firstName", "Gayle");
    child.insert(a3);

    root.insert(child);

    cout << encodeToString(root) << endl; // 1 4 mcdowell 5 CA 0 2 3 Gayle 0 Some Message 0 0

    return 0;
}