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

class Point {
public:
    double x;
    double y;

    Point(double _x, double _y) : x(_x), y(_y) {}

    void setLocation(double _x, double _y) {
        x = _x;
        y = _y;
    }
};

class Line {
public:
    double slope;
    double yintercept;

    Line(Point *start, Point *end) {
        double deltaX = end->x - start->x;
        double deltaY = end->y - start->y;
        slope = deltaY / deltaX;
        yintercept = end->y - slope * end->x;
    }
};

void swap(Point *a, Point *b) {
    double x = a->x;
    double y = a->y;
    a->setLocation(b->x, b->y);
    b->setLocation(x, y);
}

bool isBetween(double start, double middle, double end) {
    if (start > end) {
        return middle >= end && middle <= start;
    } else {
        return middle >= start && middle <= end;
    }
}

bool isBetween(Point *start, Point *middle, Point *end) {
    return isBetween(start->x, middle->x, end->x) && isBetween(start->y, middle->y, end->y);
}

Point *getIntersection(Point *start1, Point *end1, Point *start2, Point *end2) {
    if (start1->x > end1->x) swap(start1, end1);
    if (start2->x > end2->x) swap(start2, end2);
    if (start1->x > start2->x) {
        swap(start1, start2);
        swap(end1, end2);
    }

    Line *line1 = new Line(start1, end1);
    Line *line2 = new Line(start2, end2);

    if (line1->slope == line2->slope) {
        if (line1->yintercept == line2->yintercept && isBetween(start1, start2, end1)) {
            return start2;
        } else {
            return nullptr;
        }
    }

    double x = (line2->yintercept - line1->yintercept) / (line1->slope - line2->slope);
    double y = line1->slope * x + line1->yintercept;
    Point *intersection = new Point(x, y);

    if (isBetween(start1, intersection, end1) && isBetween(start2, intersection, end2)) {
        return intersection;
    } else {
        return nullptr;
    }
}


int main() {
    Point *s1 = new Point(-2, 0);
    Point *e1 = new Point(2, 8);
    Point *s2 = new Point(-3, 4);
    Point *e2 = new Point(2, -1);
    Point *intersection = getIntersection(s1, e1, s2, e2);

    if (intersection == nullptr) {
        cout << "None" << endl;
    } else {
        cout << "x = " << intersection->x << ", y = " << intersection->y << endl;
    }

    return 0;
}
