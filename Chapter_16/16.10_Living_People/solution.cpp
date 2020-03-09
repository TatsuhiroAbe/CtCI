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


class Person {
public:
    int birth;
    int death;

    Person(int b, int d) : birth(b), death(d) {}
};

vector<int> getPopulationDelta(vector<Person> &people, int minYear, int maxYear) {
    vector<int> populationDeltas(maxYear - minYear + 2);
    for (Person person : people) {
        int birth = person.birth - minYear;
        populationDeltas[birth]++;

        int death = person.death - minYear;
        populationDeltas[death + 1]--;
    }
    return populationDeltas;
}

int getMaxAliveYear(vector<int> &deltas) {
    int maxAliveYear = 0;
    int maxAlive = 0;
    int currentlyAlive = 0;
    for (int year = 0; year < deltas.size(); year++) {
        currentlyAlive += deltas[year];
        if (currentlyAlive > maxAlive) {
            maxAliveYear = year;
            maxAlive = currentlyAlive;
        }
    }
    return maxAliveYear;
}

int maxAliveYear(vector<Person> &people, int minYear, int maxYear) {
    vector<int> populationDeltas = getPopulationDelta(people, minYear, maxYear);
    int maxAliveYear = getMaxAliveYear(populationDeltas);
    return maxAliveYear + minYear;
}

int main() {
    vector<Person> people{Person(1912, 1915),
                          Person(1920, 1990),
                          Person(1910, 1998),
                          Person(1901, 1972),
                          Person(1910, 1998),
                          Person(1923, 1982),
                          Person(1913, 1998),
                          Person(1990, 1998),
                          Person(1983, 1999),
                          Person(1975, 1994)};
    cout << maxAliveYear(people, 1901, 1999) << endl; // 1990
    return 0;
}