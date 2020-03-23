#include "pch.h"
#include "CppUnitTest.h"
#include "../Intersect2/GeoFigures.h"
#include "../Intersect2/GeoCalculate.h"
#include "../Intersect2/CommandLine.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest2
{
	TEST_CLASS(TestGetPoint)
	{
	public:
		TEST_METHOD(Line_Line_OneCross_Normal_Normal)
		{
			Line l1, l2;
			l1.p1.x = 0; l1.p1.y = 0; l1.p2.x = 2; l1.p2.y = 2;
			l2.p1.x = 0; l2.p1.y = 2; l2.p2.x = 2; l2.p2.y = 0;
			Point realPoint, testPoint;
			realPoint.x = 1; realPoint.y = 1;
			Assert::IsTrue(getPoint(l1, l2, testPoint) == 1);
			Assert::IsTrue(realPoint == testPoint);
		}

		TEST_METHOD(Line_Line_OneCross_Normal_NoSlope)
		{
			Line l1, l2;
			l1.p1.x = 0; l1.p1.y = 1; l1.p2.x = 10; l1.p2.y = 1;
			l2.p1.x = 1; l2.p1.y = -1; l2.p2.x = 1; l2.p2.y = 10;
			Point realPoint, testPoint;
			realPoint.x = 1; realPoint.y = 1;
			Assert::IsTrue(getPoint(l1, l2, testPoint) == 1);
			Assert::IsTrue(realPoint == testPoint);
		}

		TEST_METHOD(Line_Line_NoCross)
		{
			Line l1, l2;
			l1.p1.x = 0; l1.p1.y = 0; l1.p2.x = 2; l1.p2.y = 2;
			l2.p1.x = 1; l2.p1.y = 0; l2.p2.x = 2; l2.p2.y = 1;
			Point testPoint;
			Assert::IsTrue(getPoint(l1, l2, testPoint) == 0);
		}

		TEST_METHOD(Line_Seg_OneCross_Normal_Normal1)
		{
			Line l;
			Segment s;
			l.p1.x = 0; l.p1.y = 0; l.p2.x = 2; l.p2.y = 2;
			s.p1.x = 0; s.p1.y = 2; s.p2.x = 2; s.p2.y = 0;
			Point realPoint, testPoint;
			realPoint.x = 1; realPoint.y = 1;
			Assert::IsTrue(getPoint(l, s, testPoint) == 1);
			Assert::IsTrue(realPoint == testPoint);
		}

		TEST_METHOD(Line_Seg_OneCross_Normal_Normal2)
		{
			Line l;
			Segment s;
			l.p1.x = 0; l.p1.y = 0; l.p2.x = 2; l.p2.y = 2;
			s.p1.x = 1; s.p1.y = 1; s.p2.x = 2; s.p2.y = 0;
			Point realPoint, testPoint;
			realPoint.x = 1; realPoint.y = 1;
			Assert::IsTrue(getPoint(l, s, testPoint) == 1);
			Assert::IsTrue(realPoint == testPoint);
		}

		TEST_METHOD(Line_Seg_NOCross)
		{
			Line l;
			Segment s;
			l.p1.x = 0; l.p1.y = 0; l.p2.x = 2; l.p2.y = 2;
			s.p1.x = 3; s.p1.y = -2; s.p2.x = 2; s.p2.y = 0;
			Point testPoint;
			Assert::IsTrue(getPoint(l, s, testPoint) == 0);
		}

		TEST_METHOD(Line_Ray_OneCross_Normal_Normal1)
		{
			Line l;
			Ray r;
			l.p1.x = 0; l.p1.y = 0; l.p2.x = 2; l.p2.y = 2;
			r.start.x = 0; r.start.y = 2; r.direction.x = 2; r.direction.y = 0;
			Point realPoint, testPoint;
			realPoint.x = 1; realPoint.y = 1;
			Assert::IsTrue(getPoint(l, r, testPoint) == 1);
			Assert::IsTrue(realPoint == testPoint);
		}

		TEST_METHOD(Line_Ray_NOCross)
		{
			Line l;
			Ray r;
			l.p1.x = 0; l.p1.y = 0; l.p2.x = 2; l.p2.y = 2;
			r.start.x = 0; r.start.y = 2; r.direction.x = -1; r.direction.y = 3;
			Point testPoint;
			Assert::IsTrue(getPoint(l, r, testPoint) == 0);
		}

		TEST_METHOD(Line_Circle_OneCross)
		{
			Line l;
			Circle c;
			l.p1.x = 2; l.p1.y = 0; l.p2.x = 2; l.p2.y = 2;
			c.center.x = 0; c.center.y = 0; c.r = 2;
			Point realPoint;
			pair<Point, Point> testPair;
			realPoint.x = 2; realPoint.y = 0;
			Assert::IsTrue(getPoint(l, c, testPair) == 1);
			Assert::IsTrue(realPoint == testPair.first);
		}

		TEST_METHOD(Line_Circle_TwoCross)
		{
			Line l;
			Circle c;
			l.p1.x = -1; l.p1.y = 2; l.p2.x = 2; l.p2.y = -1;
			c.center.x = 0; c.center.y = 0; c.r = 1;
			Point realPoint1, realPoint2;
			pair<Point, Point> testPair;
			realPoint1.x = 0; realPoint1.y = 1;
			realPoint2.x = 1; realPoint2.y = 0;
			Assert::IsTrue(getPoint(l, c, testPair) == 2);
			Assert::IsTrue(((realPoint1 == testPair.first) && (realPoint2 == testPair.second))||
			((realPoint2 == testPair.first) && (realPoint1 == testPair.second)));
		}

		TEST_METHOD(Line_Circle_NOCross)
		{
			Line l;
			Circle c;
			l.p1.x = 2; l.p1.y = 0; l.p2.x = 2; l.p2.y = 2;
			c.center.x = 0; c.center.y = 0; c.r = 1;
			pair<Point, Point> testPair;
			Assert::IsTrue(getPoint(l, c, testPair) == 0);
		}

		TEST_METHOD(Seg_Seg_OneCross_Normal_Normal2)
		{
			Segment s1;
			Segment s2;
			s1.p1.x = 0; s1.p1.y = 0; s1.p2.x = 2; s1.p2.y = 2;
			s2.p1.x = 1; s2.p1.y = 1; s2.p2.x = 2; s2.p2.y = 0;
			Point realPoint, testPoint;
			realPoint.x = 1; realPoint.y = 1;
			Assert::IsTrue(getPoint(s1, s2, testPoint) == 1);
			Assert::IsTrue(realPoint == testPoint);
		}

		TEST_METHOD(Seg_Seg_NOCross_Normal_Normal2)
		{
			Segment s1;
			Segment s2;
			s1.p1.x = 0; s1.p1.y = 0; s1.p2.x = 1; s1.p2.y = 1;
			s2.p1.x = 3; s2.p1.y = 0; s2.p2.x = 2; s2.p2.y = 1;
			Point testPoint;
			Assert::IsTrue(getPoint(s1, s2, testPoint) == 0);
		}

		TEST_METHOD(Ray_Ray_OneCross_Normal_Normal2)
		{
			Ray r1;
			Ray r2;
			r1.start.x = 0; r1.start.y = 2; r1.direction.x = 1; r1.direction.y = 0;
			r2.start.x = 3; r2.start.y = 2; r2.direction.x = 2; r2.direction.y = 0;
			Point realPoint, testPoint;
			realPoint.x = 1.5; realPoint.y = -1;
			Assert::IsTrue(getPoint(r1, r2, testPoint) == 1);
			Assert::IsTrue(realPoint == testPoint);
		}

		TEST_METHOD(Ray_Ray_NOCross_Normal_Normal2)
		{
			Ray r1;
			Ray r2;
			r1.start.x = 1; r1.start.y = 0; r1.direction.x = 0; r1.direction.y = 2;
			r2.start.x = 2; r2.start.y = 0; r2.direction.x = 3; r2.direction.y = 2;
			Point testPoint;
			Assert::IsTrue(getPoint(r1, r2, testPoint) == 0);
		}

		TEST_METHOD(Circle_Circle_TwoCross)
		{
			Circle c1;
			Circle c2;
			c1.center.x = 0; c1.center.y = 0; c1.r = 2;
			c2.center.x = 2; c2.center.y = 0; c2.r = 2;
			Point realPoint1, realPoint2;
			pair<Point, Point> testPair;
			realPoint1.x = 1; realPoint1.y = 1.73205081;
			realPoint2.x = 1; realPoint2.y = -1.73205081;
			Assert::IsTrue(getPoint(c1, c2, testPair) == 2);
			Assert::IsTrue(((realPoint1 == testPair.first) && (realPoint2 == testPair.second)) ||
				((realPoint2 == testPair.first) && (realPoint1 == testPair.second)));
		}

		TEST_METHOD(Circle_Circle_OneCross)
		{
			Circle c1;
			Circle c2;
			c1.center.x = 0; c1.center.y = 0; c1.r = 2;
			c2.center.x = 4; c2.center.y = 0; c2.r = 2;
			Point realPoint1, realPoint2;
			pair<Point, Point> testPair;
			realPoint1.x = 2; realPoint1.y = 0;
			Assert::IsTrue(getPoint(c1, c2, testPair) == 1);
			Assert::IsTrue(realPoint1 == testPair.first);
		}

		TEST_METHOD(Circle_Circle_NoCross)
		{
			Circle c1;
			Circle c2;
			c1.center.x = 0; c1.center.y = 0; c1.r = 2;
			c2.center.x = 5; c2.center.y = 0; c2.r = 2;
			Point realPoint1, realPoint2;
			pair<Point, Point> testPair;
			Assert::IsTrue(getPoint(c1, c2, testPair) == 0);
		}

		TEST_METHOD(TestAll)
		{
			vector<Line> lineSet;
			vector<Segment> segmentSet;
			vector<Ray> raySet;
			vector<Circle> circleSet;
			set<Point> pointSet;
			
			Line l1, l2; Segment s1, s2, s3; Ray r1, r2, r3; Circle c1, c2;
			l1.p1.x = 1; l1.p1.y = 2; l1.p2.x = 3; l1.p2.y = 3;
			l2.p1.x = 4; l2.p1.y = 2; l2.p2.x = 2; l2.p2.y = -4;
			lineSet.push_back(l1); lineSet.push_back(l2);
			s1.p1.x = -5; s1.p1.y = 1; s1.p2.x = 5; s1.p2.y = -3;
			s2.p1.x = 5; s2.p1.y = 3; s2.p2.x = 2; s2.p2.y = 2;
			s3.p1.x = 6; s3.p1.y = -5; s3.p2.x = 6; s3.p2.y = 6;
			segmentSet.push_back(s1); segmentSet.push_back(s2); segmentSet.push_back(s3);
			r1.start.x = 5; r1.start.y = 2; r1.direction.x = 3; r1.direction.y = 4;
			r2.start.x = 2; r2.start.y = -4; r2.direction.x = -1; r2.direction.y = -1;
			r3.start.x = -10; r3.start.y = 1; r3.direction.x = 10; r3.direction.y = 1;
			raySet.push_back(r1); raySet.push_back(r2); raySet.push_back(r3);
			c1.center.x = 2; c1.center.y = 3; c1.r = 4;
			c2.center.x = 5; c2.center.y = 2; c2.r = 2;
			circleSet.push_back(c1); circleSet.push_back(c2);
			Assert::AreEqual(calPoint(lineSet, segmentSet, raySet, circleSet, pointSet), 35);
		}
		TEST_METHOD(T1)
		{
			//点在直线外
			Line line1;
			line1.p1.x = 1; line1.p1.y = 0; line1.p2.x = 1; line1.p2.y = 1;
			Point point;
			point.x = 0; point.y = 0;
			Point testpoint = getProjection(point, line1);
			Point realpoint;
			realpoint.x = 1;
			realpoint.y = 0;
			Assert::IsTrue(testpoint == realpoint);
		}

		TEST_METHOD(T2)
		{
			struct Segment s1;
			struct Segment s2;
			struct Point crossPoint;
			s1.p1.x = 0;
			s1.p1.y = 0;
			s1.p2.x = 0;
			s1.p2.y = 10;
			s2.p1.x = -5;
			s2.p1.y = 5;
			s2.p2.x = 5;
			s2.p2.y = 5;
			int re = getPoint(s1, s2, crossPoint);
			Assert::AreEqual(crossPoint.x, 0.0);
			Assert::AreEqual(crossPoint.y, 5.0);
			Assert::AreEqual(getPoint(s1, s2, crossPoint), 1);
		}
		TEST_METHOD(T3)
		{
			struct Line s1;
			struct Line s2;
			struct Point crossPoint;
			s1.p1.x = 0;
			s1.p1.y = 0;
			s1.p2.x = 0;
			s1.p2.y = 10;
			s2.p1.x = -5;
			s2.p1.y = 5;
			s2.p2.x = 5;
			s2.p2.y = 5;
			int re = getPoint(s1, s2, crossPoint);
			Assert::AreEqual(crossPoint.x, 0.0);
			Assert::AreEqual(crossPoint.y, 5.0);
			Assert::AreEqual(getPoint(s1, s2, crossPoint), 1);
		}

		TEST_METHOD(TestMethod1)
		{
			Line line1, line2;
			line1.p1.x = 1; line1.p1.y = 2; line1.p2.x = 3; line1.p2.y = 4;
			line2.p1.x = 3; line2.p1.y = 4; line2.p2.x = 4; line2.p2.y = 10;
			Point point;
			Assert::AreEqual(getPoint(line1, line2, point), ONECROSS);
		}

		TEST_METHOD(TestMethod2)
		{
			Line line1, line2;
			line1.p1.x = 1; line1.p1.y = 4; line1.p2.x = 2; line1.p2.y = 7;
			line2.p1.x = 3; line2.p1.y = 11; line2.p2.x = 4; line2.p2.y = 14;
			Point point;
			Assert::AreEqual(getPoint(line1, line2, point), NOCROSS);
		}

		
		TEST_METHOD(TestMethod4)
		{
			Line line;
			Segment seg;
			Point point;
			line.p1.x = 1; line.p1.y = 2; line.p2.x = 3; line.p2.y = 4;
			seg.p1.x = 6; seg.p1.y = 3; seg.p2.x = 8; seg.p2.y = 4;
			Assert::AreEqual(getPoint(line, seg, point), NOCROSS);
		}

		TEST_METHOD(TestMethod5)
		{
			Line line;
			Segment seg;
			Point point;
			line.p1.x = 1; line.p1.y = 2; line.p2.x = 3; line.p2.y = 4;
			seg.p1.x = -4; seg.p1.y = -2; seg.p2.x = 8; seg.p2.y = 4;
			Assert::AreEqual(getPoint(line, seg, point), ONECROSS);
		}

		TEST_METHOD(TestMethod6)
		{
			Line line;
			Segment seg;
			Point point;
			line.p1.x = 1; line.p1.y = 2; line.p2.x = 3; line.p2.y = 4;
			seg.p1.x = 1; seg.p1.y = 3; seg.p2.x = 2; seg.p2.y = 4;
			Assert::AreEqual(getPoint(line, seg, point), NOCROSS);
		}

		
		TEST_METHOD(TestMethod8)
		{
			Line line;
			Ray ray;
			Point point;
			line.p1.x = 1; line.p1.y = 2; line.p2.x = 3; line.p2.y = 4;
			ray.start.x = 6; ray.start.y = 3; ray.direction.x = 8; ray.direction.y = 4;
			Assert::AreEqual(getPoint(line, ray, point), NOCROSS);
		}

		TEST_METHOD(TestMethod9)
		{
			Line line;
			Ray ray;
			Point point;
			line.p1.x = 1; line.p1.y = 2; line.p2.x = 3; line.p2.y = 4;
			ray.start.x = 6; ray.start.y = 3; ray.direction.x = 2; ray.direction.y = 1;
			Assert::AreEqual(getPoint(line, ray, point), ONECROSS);
		}

		TEST_METHOD(TestMethod10)
		{
			Line line;
			Ray ray;
			Point point;
			line.p1.x = 1; line.p1.y = 2; line.p2.x = 3; line.p2.y = 4;
			ray.start.x = 1; ray.start.y = 3; ray.direction.x = 2; ray.direction.y = 4;
			Assert::AreEqual(getPoint(line, ray, point), NOCROSS);
		}

		
		TEST_METHOD(TestMethod12)
		{
			Segment seg;
			Ray ray;
			Point point;
			seg.p1.x = 0; seg.p1.y = 1; seg.p2.x = 2; seg.p2.y = 3;
			ray.start.x = 3; ray.start.y = 4; ray.direction.x = 5; ray.direction.y = -2;
			Assert::AreEqual(getPoint(seg, ray, point), NOCROSS);
		}

		TEST_METHOD(TestMethod13)
		{
			Segment seg;
			Ray ray;
			Point point;
			seg.p1.x = 0; seg.p1.y = 1; seg.p2.x = 2; seg.p2.y = 3;
			ray.start.x = 0; ray.start.y = 3; ray.direction.x = 2; ray.direction.y = 1;
			Assert::AreEqual(getPoint(seg, ray, point), ONECROSS);
		}

		TEST_METHOD(TestMethod14)
		{
			Segment seg;
			Ray ray;
			Point point;
			seg.p1.x = 0; seg.p1.y = 1; seg.p2.x = 2; seg.p2.y = 3;
			ray.start.x = 2; ray.start.y = 4; ray.direction.x = 5; ray.direction.y = 7;
			Assert::AreEqual(getPoint(seg, ray, point), NOCROSS);
		}


		TEST_METHOD(TestMethod17)
		{
			Segment seg;
			Ray ray;
			Point point;
			seg.p1.x = 1; seg.p1.y = 2; seg.p2.x = 2; seg.p2.y = 3;
			ray.start.x = 0; ray.start.y = 1; ray.direction.x = -1; ray.direction.y = 0;
			Assert::AreEqual(getPoint(seg, ray, point), NOCROSS);
		}

		TEST_METHOD(TestMethod18)
		{
			Segment seg1;
			Segment seg2;
			Point point;
			seg1.p1.x = 1; seg1.p1.y = -1; seg1.p2.x = 1; seg1.p2.y = 5;
			seg2.p1.x = 2; seg2.p1.y = 1; seg2.p2.x = 3; seg2.p2.y = 1;
			Assert::AreEqual(getPoint(seg1, seg2, point), NOCROSS);
		}

		TEST_METHOD(TestMethod19)
		{
			Segment seg1;
			Segment seg2;
			Point point;
			seg1.p1.x = 1; seg1.p1.y = -1; seg1.p2.x = 1; seg1.p2.y = 5;
			seg2.p1.x = 0; seg2.p1.y = 1; seg2.p2.x = 3; seg2.p2.y = 1;
			Assert::AreEqual(getPoint(seg1, seg2, point), ONECROSS);
		}

		TEST_METHOD(TestMethod20)
		{
			Segment seg1;
			Segment seg2;
			Point point;
			seg1.p1.x = 1; seg1.p1.y = -1; seg1.p2.x = 1; seg1.p2.y = 5;
			seg2.p1.x = 0; seg2.p1.y = 1; seg2.p2.x = 0; seg2.p2.y = 2;
			Assert::AreEqual(getPoint(seg1, seg2, point), NOCROSS);
		}


		TEST_METHOD(TestMethod23)
		{
			Segment seg1;
			Segment seg2;
			Point point;
			seg1.p1.x = 1; seg1.p1.y = -1; seg1.p2.x = 1; seg1.p2.y = 5;
			seg2.p1.x = 1; seg2.p1.y = 6; seg2.p2.x = 1; seg2.p2.y = 7;
			Assert::AreEqual(getPoint(seg1, seg2, point), NOCROSS);
		}

		TEST_METHOD(TestMethod24)
		{
			Ray ray1;
			Ray ray2;
			Point point;
			ray1.start.x = 1; ray1.start.y = 2; ray1.direction.x = 3; ray1.direction.y = 4;
			ray2.start.x = 1; ray2.start.y = 1; ray2.direction.x = -1; ray2.direction.y = 1;
			Assert::AreEqual(getPoint(ray1, ray2, point), NOCROSS);
		}

		TEST_METHOD(TestMethod25)
		{
			Ray ray1;
			Ray ray2;
			Point point;
			ray1.start.x = 0; ray1.start.y = 1; ray1.direction.x = 2; ray1.direction.y = 3;
			ray2.start.x = 1; ray2.start.y = 0; ray2.direction.x = 1; ray2.direction.y = 1;
			Assert::AreEqual(getPoint(ray1, ray2, point), ONECROSS);
		}

		TEST_METHOD(TestMethod26)
		{
			Ray ray1;
			Ray ray2;
			Point point;
			ray1.start.x = 1; ray1.start.y = 1; ray1.direction.x = 1; ray1.direction.y = 4;
			ray2.start.x = 3; ray2.start.y = 1; ray2.direction.x = 3; ray2.direction.y = 4;
			Assert::AreEqual(getPoint(ray1, ray2, point), NOCROSS);
		}
		
		TEST_METHOD(TestMethod29)
		{
			Ray ray1;
			Ray ray2;
			Point point;
			ray1.start.x = 1; ray1.start.y = 3; ray1.direction.x = 1; ray1.direction.y = 0;
			ray2.start.x = 1; ray2.start.y = 5; ray2.direction.x = 1; ray2.direction.y = 6;
			Assert::AreEqual(getPoint(ray1, ray2, point), NOCROSS);
		}
	};
}
