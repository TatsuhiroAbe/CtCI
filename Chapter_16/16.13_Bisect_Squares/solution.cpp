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

    string toString() {
        return "x: " + to_string(x) + " y: " + to_string(y);
    }
};

class Line {
public:
    Point start;
    Point end;

    Line(Point s, Point e) : start(s), end(e) {}
};

class Square {
public:
    double left;
    double top;
    double bottom;
    double right;
    double size;

    Square(double l, double b, double s) : left(l), bottom(b), size(s) {
        top = bottom + size;
        right = left + size;
    }

    Point middle() {
        Point mid((left + right) / 2, (top + bottom) / 2);
        return mid;
    }

    Point extend(Point mid1, Point mid2, double size) {
        double xdir = mid1.x < mid2.x ? -1 : 1;
        double ydir = mid1.y < mid2.y ? -1 : 1;

        if (mid1.x == mid2.x) {
            Point p(mid1.x, mid1.y + ydir * size / 2.0);
            return p;
        }
        double slope = (mid2.y - mid1.y) / (mid2.x - mid1.x);
        double x1 = 0;
        double y1 = 0;

        if (abs(slope) == 1) {
            x1 = mid1.x + xdir * size / 2.0;
            y1 = mid1.y + ydir * size / 2.0;
        } else if (abs(slope) < 1) {
            x1 = mid1.x + xdir * size / 2.0;
            y1 = slope * (x1 - mid1.x) + mid1.y;
        } else {
            y1 = mid1.y + ydir * size / 2.0;
            x1 = (y1 - mid1.y) / slope + mid1.x;
        }

        Point p(x1, y1);
        return p;
    }

    Line cut(Square other) {
        Point p1 = extend(this->middle(), other.middle(), size);
        Point p2 = extend(this->middle(), other.middle(), -size);
        Point p3 = extend(other.middle(), this->middle(), other.size);
        Point p4 = extend(other.middle(), this->middle(), -other.size);

        Point start = p1;
        Point end = p1;
        vector<Point> points{p2, p3, p4};
        for (Point &p : points) {
            if (p.x < start.x || (p.x == start.x && p.y < start.y)) {
                start = p;
            } else if (p.x > end.x || (p.x == end.x && p.y > end.y)) {
                end = p;
            }
        }

        Line l(start, end);
        return l;
    }
};

int main() {
    Square s1(1, 1, 4);
    Square s2(5, 5, 2);
    Line l = s1.cut(s2);

    cout << l.start.toString() << endl; // x: 1.0 y: 1.0
    cout << l.end.toString() << endl;   // x: 7.0 y: 7.0

    return 0;
}