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

class Animal {
private:
    int order;
    string name;

public:
    Animal(string _name) {
        this->name = _name;
    }

    void setOrder(int n) {
        this->order = n;
    }

    int getOrder() {
        return order;
    }
};

class Dog : public Animal {
public:
    Dog(string _name) : Animal(_name) {}
};
class Cat : public Animal {
    Cat(string _name) : Animal(_name) {}
};

class AnimalQueue {
private:
    list<Dog> dogs;
    list<Cat> cats;
    int order = 0;

public:
    void enqueue(Animal animal) {
        animal.setOrder(order);
        order++;


    }
};

int main() {
    Dog dog = Dog("inu");

    cout << typeid(dog).name() << endl;
}