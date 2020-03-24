#ifndef DEFINE_H
#define DEFINE_H
#include <cmath>
#include <vector>
#include <set>
#define EPS (1e-8)

using namespace std;
/*
static int compareDouble(double x)
{
    if (fabs(x) < EPS) return 0;
    if (x < 0) return -1;
    else return 1;
}

struct Point {
    double x;
    double y;
    double length;

    bool operator ==(const Point& b)
    {
        if (compareDouble(x - b.x) == 0 && compareDouble(y - b.y) == 0) return true;
        return false;
    }
    bool operator <(const Point& b)
    {
        if (compareDouble(x - b.x) == 0 && compareDouble(y - b.y) < 0) return true;
        if (compareDouble(x - b.x) < 0) return true;
        return false;
    }

};

typedef Point Vector;

struct Line {
    Point p1, p2;
};

struct Circle {
    Point center;
    double r;
};

*/
#endif // DEFINE_H
