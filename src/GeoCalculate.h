#pragma once
#include <set>
#include <vector>
#include <exception>
#include "GeoFigures.h"

#define NOCROSS 0
#define ONECROSS 1
#define TWOCROSS 2
#define MANYCROSS 3

#define NOTON 0
#define ON 1

#define OUTRANGE 0
#define INRANGE 1

using namespace std;

int testDoubleRange(double r);
int testPointRange(Point p);
void testCoorRange(vector<Line> lineSet, vector<Segment> segmentSet, vector<Ray> raySet, vector<Circle> circleSet);

double dot(Vector a, Vector b) noexcept;
double getPointsDistance(Point a, Point b) noexcept;
Vector getVector(Point a, Point b) noexcept;
Vector getUnitVector(Vector v) noexcept;
Point getProjection(Point a, Line l) noexcept;
Point getCoorFromPolar(double x, double r) noexcept;
double getAngleFromPoint(Point p) noexcept;
Line segmentToLine(Segment s);
Line rayToLine(Ray r);
int pointIfOnSeg(Point p, Line l);
int pointIfOnRay(Point p, Line l);

int getPoint(Line l1, Line l2, Point& crossPoint) noexcept;
int getPoint(Line l, Segment s, Point& crossPoint) noexcept;
int getPoint(Line l, Ray r, Point& crossPoint) noexcept;
int getPoint(Line l, Circle c, pair<Point, Point>& crossPair) noexcept;

int getPoint(Segment s1, Segment s2, Point& crossPoint) noexcept;
int getPoint(Segment s, Ray r, Point& crossPoint) noexcept;
int getPoint(Segment s, Circle c, pair<Point, Point>& crossPair) noexcept;

int getPoint(Ray r1, Ray r2, Point& crossPoint) noexcept;
int getPoint(Ray r, Circle c, pair<Point, Point>& crossPair) noexcept;

int getPoint(Circle c1, Circle c2, pair<Point, Point>& crossPair) noexcept;

int calPoint(vector<Line>& lineSet, set<Point>& pointSet);
int calPoint(vector<Line>& lineSet, vector<Segment>& segmentSet, set<Point>& pointSet);
int calPoint(vector<Line>& lineSet, vector<Ray>& raySet, set<Point>& pointSet);
int calPoint(vector<Line>& lineSet, vector<Circle>& circleSet, set<Point>& pointSet);

int calPoint(vector<Segment>& segmentSet, set<Point>& pointSet);
int calPoint(vector<Segment>& segmentSet, vector<Ray>& raySet, set<Point>& pointSet);
int calPoint(vector<Segment>& segmentSet, vector<Circle>& circleSet, set<Point>& pointSet);

int calPoint(vector<Ray>& raySet, set<Point>& pointSet);
int calPoint(vector<Ray>& raySet, vector<Circle>& circleSet, set<Point>& pointSet);

int calPoint(vector<Circle>& circleSet, set<Point>& pointSet);

int calPoint(vector<Line>& lineSet, vector<Segment>& segmentSet, vector<Ray>& raySet, vector<Circle>& circleSet, set<Point>& pointSet);