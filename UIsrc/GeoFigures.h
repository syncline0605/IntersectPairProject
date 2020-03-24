#pragma once
#include <cmath>
#define EPS (1e-8)
using namespace std;

int compareDouble(double x) noexcept;

struct Point {
	double x;
	double y;
	double length;

	bool operator ==(const Point& b) const noexcept
	{
		if (compareDouble(x - b.x) == 0 && compareDouble(y - b.y) == 0) return true;
		return false;
	}
	bool operator <(const Point& b) const noexcept
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

struct Segment {
	Point p1, p2;
};

struct Ray {
	Point start, direction;
};

struct Circle {
	Point center;
	double r;
};
