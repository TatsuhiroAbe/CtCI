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


class GraphPoint {
public:
    double x;
    double y;

    GraphPoint(double _x, double _y) : x(_x), y(_y) {}
};

class Line {
public:
    static constexpr double epsilon = 0.0001;
    double slope;
    double intercept;

private:
    bool infinite_slope = false;

public:
    Line(GraphPoint p, GraphPoint q) {
        if (abs(p.x - q.x) > epsilon) {
            slope = (p.y - q.y) / (p.x - q.x);
            intercept = p.y - slope * p.x;
        } else {
            infinite_slope = true;
            intercept = p.x;
        }
    }

    static double floorToNearestEpsilon(double d) {
        int r = (int)(d / epsilon);
        return (double)r * epsilon;
    }

    bool isEquivalent(double a, double b) {
        return abs(a - b) < epsilon;
    }

    bool isEquivalent(Line line) {
        return isEquivalent(slope, line.slope)
               && isEquivalent(intercept, line.intercept)
               && infinite_slope == line.infinite_slope;
    }
};

unordered_map<double, list<Line>> getListOfLines(vector<GraphPoint> &points) {
    unordered_map<double, list<Line>> hash;
    for (int i = 0; i < points.size(); i++) {
        for (int j = i + 1; j < points.size(); j++) {
            Line line(points[i], points[j]);
            double key = Line::floorToNearestEpsilon(line.slope);
            hash[key].push_back(line);
        }
    }
    return hash;
}

int countEquivalentLines(list<Line> &lines, Line line) {
    int count = 0;
    for (Line &parallelLine: lines) {
        if (parallelLine.isEquivalent(line)) {
            count++;
        }
    }
    return count;
}

int countEquivalentLines(unordered_map<double, list<Line>> &hash, Line line) {
    double key = Line::floorToNearestEpsilon(line.slope);
    int count = countEquivalentLines(hash[key], line);
    count += countEquivalentLines(hash[key - Line::epsilon], line);
    count += countEquivalentLines(hash[key + Line::epsilon], line);
    return count;
}


Line getBestLine(unordered_map<double, list<Line>> &hash) {
    Line *line = nullptr;
    int bestCount = 0;

    set<double> slopes;
    for (auto &p : hash) {
        slopes.insert(p.first);
    }

    for (double slope : slopes) {
        list<Line> lines = hash[slope];
        for (Line &l : lines) {
            int count = countEquivalentLines(hash, l);
            if (count > bestCount) {
                line = &l;
                bestCount = count;
            }
        }
    }
    return *line;
}

Line findBestLine(vector<GraphPoint> &points) {
    unordered_map<double, list<Line>> hash = getListOfLines(points);
    return getBestLine(hash);
}

int main() {
    vector<GraphPoint> points;
    for (int i = 1; i <= 10; i++) {
        if (i <= 6) {
            points.emplace_back(GraphPoint((double)i, 2.3 * (double)i + 20.0));
        } else {
            points.emplace_back(GraphPoint((double)i, 3.0 * (double)i + 1.0));
        }
    }

    Line line = findBestLine(points);
    cout << "y = " << line.slope << " x + " << line.intercept << endl;
    return 0;
}