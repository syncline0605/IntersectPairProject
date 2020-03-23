#include "GeoFigures.h"
#include "GeoCalculate.h"

using namespace std;


//���������ĵ�˽��
double dot(Vector a, Vector b) noexcept
{
	return (a.x * b.x + a.y * b.y);
}

//������֮��ľ���
double getPointsDistance(Point a, Point b) noexcept
{
	const double x = a.x - b.x;
	const double y = a.y - b.y;
	return (sqrt(x * x + y * y));
}

//���������㣬�ӵ�aָ���b������
Vector getVector(Point a, Point b) noexcept
{
	Vector newVec;
	newVec.x = b.x - a.x;
	newVec.y = b.y - a.y;
	newVec.length = sqrt((newVec.x) * (newVec.x) + (newVec.y) * (newVec.y));
	return newVec;
}

//��ĳһ�����ĵ�λ����
Vector getUnitVector(Vector v) noexcept
{
	Vector unitVector;
	v.length = sqrt((v.x) * (v.x) + (v.y) * (v.y));
	unitVector.x = v.x / v.length;
	unitVector.y = v.y / v.length;
	unitVector.length = 1;
	return unitVector;
}

//�����ֱ���ϵ�ͶӰ����
Point getProjection(Point a, Line l) noexcept
{
	Vector e = getVector(l.p1, l.p2);
	const Vector k = getVector(l.p1, a);
	const double r = dot(k, e) / e.length;
	Point pr = { 1, 0 };
	e = getUnitVector(e);
	pr.x = l.p1.x + r * e.x;
	pr.y = l.p1.y + r * e.y;
	return pr;
}

//ͨ��������ϵ�ϵļ��Ǻͼ�������ֱ������ϵ�е�����
Point getCoorFromPolar(double x, double r) noexcept
{
	Point newPoint;
	newPoint.x = x * cos(r);
	newPoint.y = x * sin(r);
	return newPoint;
}

//ͨ�����������һ������������x��ļн�
double getAngleFromPoint(Point p) noexcept
{
	return atan2(p.y, p.x);
}

//���߶�ת���ɶ�Ӧ��ֱ��
Line segmentToLine(Segment s)
{
	Line l;
	if (s.p1.x <= s.p2.x)
	{
		l.p1 = s.p1;
		l.p2 = s.p2;
	}
	else
	{
		l.p1 = s.p2;
		l.p2 = s.p1;
	}
	return l;
}

//������ת���ɶ�Ӧ��ֱ��
Line rayToLine(Ray r)
{
	Line l{ r.start, r.direction };
	return l;
}

//�ж�һ�����Ƿ���һ�߶εĺ����귶Χ��
int pointIfOnSeg(Point p, Line l)
{
	if ((p.x >= l.p1.x) && (p.x <= l.p2.x))
	{
		return ON;
	}
	else
	{
		return NOTON;
	}
}

//�ж�һ�����Ƿ���һ���ߵĺ����귶Χ��
int pointIfOnRay(Point p, Line l)
{
	if (l.p2.x <= l.p1.x)
	{
		//������ָ�򸺷���
		if (p.x <= l.p1.x)
		{
			return ON;
		}
		else
		{
			return NOTON;
		}
	}
	else
	{
		//������ָ��������
		if (p.x > l.p1.x)
		{
			return ON;
		}
		else
		{
			return NOTON;
		}
	}
}

//����ֱ�߽���
int getPoint(Line l1, Line l2, Point& crossPoint) noexcept
{
	const int flag1 = (l1.p1.x == l1.p2.x) ? 0 : 1;
	const int flag2 = (l2.p1.x == l2.p2.x) ? 0 : 1;
	if (flag1 == 0 && flag2 == 0)
	{
		//����ֱ�ߵ�б�ʶ������ڣ����޽���
		return NOCROSS;
	}
	//�������һ��ʽ��ʾ����ֱ��ʱ��ϵ��a��b��c
	//��ʹ����ѧ��ʽ�ж��Ƿ���ڽ���ͽ��������
	const double a1 = l1.p1.y - l1.p2.y;
	const double b1 = l1.p2.x - l1.p1.x;
	const double c1 = l1.p1.x * l1.p2.y - l1.p2.x * l1.p1.y;
	const double a2 = l2.p1.y - l2.p2.y;
	const double b2 = l2.p2.x - l2.p1.x;
	const double c2 = l2.p1.x * l2.p2.y - l2.p2.x * l2.p1.y;

	const double D = a1 * b2 - a2 * b1;
	if (D == 0)
	{
		return NOCROSS;
	}
	crossPoint.x = (b1 * c2 - b2 * c1) / D;
	crossPoint.y = (a2 * c1 - a1 * c2) / D;
	return ONECROSS;
}

//��ֱ�����߶εĽ���
int getPoint(Line l, Segment s, Point& crossPoint) noexcept
{
	Line l2 = segmentToLine(s);
	int result = getPoint(l, l2, crossPoint);
	if (result == NOCROSS)
	{
		return NOCROSS;
	}
	else 
	{
		if (pointIfOnSeg(crossPoint, l2))
		{
			return ONECROSS;
		}
		else
		{
			return NOCROSS;
		}
	}
}

//��ֱ�������ߵĽ���
int getPoint(Line l, Ray r, Point& crossPoint) noexcept
{
	Line l2 = rayToLine(r);
	int result = getPoint(l, l2, crossPoint);
	if (result == NOCROSS)
	{
		return NOCROSS;
	}
	else
	{
		if (pointIfOnRay(crossPoint, l2))
		{
			return ONECROSS;
		}
		else
		{
			return NOCROSS;
		}
	}
}

//��ֱ����Բ�Ľ���
int getPoint(Line l, Circle c, pair<Point, Point>& crossPair) noexcept
{
	const Point pr = getProjection(c.center, l); //��Բ����ֱ���ϵ�ͶӰ��
	const double distance = getPointsDistance(c.center, pr); //��ͶӰ�㵽Բ�ĵľ��루��Բ�ĵ�ֱ�ߵľ��룩
	if (distance > c.r)
	{
		//�������ԼԲ�İ뾶�����޽���
		return NOCROSS;
	}
	else if (distance == c.r)
	{
		//���������Բ�İ뾶������һ�����㣬�������ͶӰ��
		crossPair.first = pr;
		return ONECROSS;
	}
	else
	{
		//������С��Բ�İ뾶�������������㣬������Ӧ����ѧ�������м���
		const Vector e = getUnitVector(getVector(l.p1, l.p2));
		const double m = sqrt(c.r * c.r - distance * distance);
		crossPair.first.x = pr.x + m * e.x;
		crossPair.first.y = pr.y + m * e.y;
		crossPair.second.x = pr.x - m * e.x;
		crossPair.second.y = pr.y - m * e.y;
		return TWOCROSS;
	}
}

//�����߶ν���
int getPoint(Segment s1, Segment s2, Point& crossPoint) noexcept
{
	Line l1 = segmentToLine(s1);
	Line l2 = segmentToLine(s2);
	int result = getPoint(l1, l2, crossPoint);
	if (result == NOCROSS)
	{
		return NOCROSS;
	}
	else
	{
		if (pointIfOnSeg(crossPoint, l1) && pointIfOnSeg(crossPoint, l2))
		{
			return ONECROSS;
		}
		else
		{
			return NOCROSS;
		}
	}
}

//���߶������ߵĽ���
int getPoint(Segment s, Ray r, Point& crossPoint) noexcept
{
	Line l1 = segmentToLine(s);
	Line l2 = rayToLine(r);
	int result = getPoint(l1, l2, crossPoint);
	if (result == NOCROSS)
	{
		return NOCROSS;
	}
	else
	{
		if (pointIfOnSeg(crossPoint, l1) && pointIfOnRay(crossPoint, l2))
		{
			return ONECROSS;
		}
		else
		{
			return NOCROSS;
		}
	}
}

//���߶���Բ�Ľ���
int getPoint(Segment s, Circle c, pair<Point, Point>& crossPair) noexcept
{
	Line l = segmentToLine(s);
	int result = getPoint(l, c, crossPair);
	if (result == NOCROSS)
	{
		return NOCROSS;
	}
	else if (result == ONECROSS)
	{
		if (pointIfOnSeg(crossPair.first, l))
		{
			return ONECROSS;
		}
		else
		{
			return NOCROSS;
		}
	}
	else
	{
		if (pointIfOnSeg(crossPair.second, l))
		{
			if (pointIfOnSeg(crossPair.first, l))
			{
				//1��2��
				return TWOCROSS;
			}
			else
			{
				//1����2��
				crossPair.first = crossPair.second;
				return ONECROSS;
			}
		}
		else
		{
			if (pointIfOnSeg(crossPair.first, l))
			{
				//1��2����
				return ONECROSS;
			}
			else
			{
				//1����2����
				return NOCROSS;
			}
		}
	}
}

//�������߽���
int getPoint(Ray r1, Ray r2, Point& crossPoint) noexcept
{
	Line l1 = rayToLine(r1);
	Line l2 = rayToLine(r2);
	int result = getPoint(l1, l2, crossPoint);
	if (result == NOCROSS)
	{
		return NOCROSS;
	}
	else
	{
		if (pointIfOnRay(crossPoint, l1) && pointIfOnRay(crossPoint, l2))
		{
			return ONECROSS;
		}
		else
		{
			return NOCROSS;
		}
	}
}

//�����ߺ�Բ�Ľ���
int getPoint(Ray r, Circle c, pair<Point, Point>& crossPair) noexcept
{
	Line l = rayToLine(r);
	int result = getPoint(l, c, crossPair);
	if (result == NOCROSS)
	{
		return NOCROSS;
	}
	else if (result == ONECROSS)
	{
		if (pointIfOnRay(crossPair.first, l))
		{
			return ONECROSS;
		}
		else
		{
			return NOCROSS;
		}
	}
	else
	{
		if (pointIfOnRay(crossPair.second, l))
		{
			if (pointIfOnRay(crossPair.first, l))
			{
				//1��2��
				return TWOCROSS;
			}
			else
			{
				//1����2��
				crossPair.first = crossPair.second;
				return ONECROSS;
			}
		}
		else
		{
			if (pointIfOnRay(crossPair.first, l))
			{
				//1��2����
				return ONECROSS;
			}
			else
			{
				//1����2����
				return NOCROSS;
			}
		}
	}
}

//����Բ����
int getPoint(Circle c1, Circle c2, pair<Point, Point>& crossPair) noexcept
{
	const double distance = getPointsDistance(c1.center, c2.center);
	if ((distance > c1.r + c2.r) || (distance < fabs(c1.r - c2.r)))
	{
		return NOCROSS;
	}
	else if (distance == c1.r + c2.r || distance == fabs(c1.r - c2.r))
	{
		const Vector e = getUnitVector(getVector(c1.center, c2.center));
		crossPair.first.x = c1.center.x + c1.r * e.x;
		crossPair.first.y = c1.center.y + c1.r * e.y;
		return ONECROSS;
	}
	else
	{
		const double a = acos((c1.r * c1.r + distance * distance - c2.r * c2.r) / (2 * c1.r * distance));
		const Vector e = getVector(c1.center, c2.center);
		const double t = getAngleFromPoint(e);
		const Point p1 = getCoorFromPolar(c1.r, t + a);
		const Point p2 = getCoorFromPolar(c1.r, t - a);
		crossPair.first.x = c1.center.x + p1.x;
		crossPair.first.y = c1.center.y + p1.y;
		crossPair.second.x = c1.center.x + p2.x;
		crossPair.second.y = c1.center.y + p2.y;
		return TWOCROSS;
	}
}

//ֱ�߼���
int calPoint(vector<Line>& lineSet, set<Point>& pointSet)
{
	for (unsigned int i = 0; i < lineSet.size(); i++)
	{
		for (unsigned int j = i + 1; j < lineSet.size(); j++)
		{
			Point crossPoint;
			const int result = getPoint(lineSet.at(i), lineSet.at(j), crossPoint);
			if (result == ONECROSS)
			{
				pointSet.insert(crossPoint);
			}
		}
	}
	return pointSet.size();
}

//ֱ�߼������߶μ���
int calPoint(vector<Line>& lineSet, vector<Segment>& segmentSet, set<Point>& pointSet)
{
	for (unsigned int i = 0; i < lineSet.size(); i++)
	{
		for (unsigned int j = 0; j < segmentSet.size(); j++)
		{
			Point crossPoint;
			const int result = getPoint(lineSet.at(i), segmentSet.at(j), crossPoint);
			if (result == ONECROSS)
			{
				pointSet.insert(crossPoint);
			}
		}
	}
	return pointSet.size();
}

//ֱ�߼��������߼���
int calPoint(vector<Line>& lineSet, vector<Ray>& raySet, set<Point>& pointSet)
{
	for (unsigned int i = 0; i < lineSet.size(); i++)
	{
		for (unsigned int j = 0; j < raySet.size(); j++)
		{
			Point crossPoint;
			const int result = getPoint(lineSet.at(i), raySet.at(j), crossPoint);
			if (result == ONECROSS)
			{
				pointSet.insert(crossPoint);
			}
		}
	}
	return pointSet.size();
}

//ֱ�߼�����Բ����
int calPoint(vector<Line>& lineSet, vector<Circle>& circleSet, set<Point>& pointSet)
{
	for (unsigned int i = 0; i < lineSet.size(); i++)
	{
		for (unsigned int j = 0; j < circleSet.size(); j++)
		{
			pair<Point, Point> crossPair;
			const int result = getPoint(lineSet.at(i), circleSet.at(j), crossPair);
			if (result == ONECROSS)
			{
				pointSet.insert(crossPair.first);
			}
			else if (result == TWOCROSS)
			{
				pointSet.insert(crossPair.first);
				pointSet.insert(crossPair.second);
			}
		}
	}
	return pointSet.size();
}

//�߶μ���
int calPoint(vector<Segment>& segmentSet, set<Point>& pointSet)
{
	for (unsigned int i = 0; i < segmentSet.size(); i++)
	{
		for (unsigned int j = i + 1; j < segmentSet.size(); j++)
		{
			Point crossPoint;
			const int result = getPoint(segmentSet.at(i), segmentSet.at(j), crossPoint);
			if (result == ONECROSS)
			{
				pointSet.insert(crossPoint);
			}
		}
	}
	return pointSet.size();
}

//�߶μ��������߼���
int calPoint(vector<Segment>& segmentSet, vector<Ray>& raySet, set<Point>& pointSet)
{
	for (unsigned int i = 0; i < segmentSet.size(); i++)
	{
		for (unsigned int j = 0; j < raySet.size(); j++)
		{
			Point crossPoint;
			const int result = getPoint(segmentSet.at(i), raySet.at(j), crossPoint);
			if (result == ONECROSS)
			{
				pointSet.insert(crossPoint);
			}
		}
	}
	return pointSet.size();
}

//�߶μ�����Բ����
int calPoint(vector<Segment>& segmentSet, vector<Circle>& circleSet, set<Point>& pointSet)
{
	for (unsigned int i = 0; i < segmentSet.size(); i++)
	{
		for (unsigned int j = 0; j < circleSet.size(); j++)
		{
			pair<Point, Point> crossPair;
			const int result = getPoint(segmentSet.at(i), circleSet.at(j), crossPair);
			if (result == ONECROSS)
			{
				pointSet.insert(crossPair.first);
			}
			else if (result == TWOCROSS)
			{
				pointSet.insert(crossPair.first);
				pointSet.insert(crossPair.second);
			}
		}
	}
	return pointSet.size();
}

//���߼���
int calPoint(vector<Ray>& raySet, set<Point>& pointSet)
{
	for (unsigned int i = 0; i < raySet.size(); i++)
	{
		for (unsigned int j = i + 1; j < raySet.size(); j++)
		{
			Point crossPoint;
			const int result = getPoint(raySet.at(i), raySet.at(j), crossPoint);
			if (result == ONECROSS)
			{
				pointSet.insert(crossPoint);
			}
		}
	}
	return pointSet.size();
}

//���߼�����Բ����
int calPoint(vector<Ray>& raySet, vector<Circle>& circleSet, set<Point>& pointSet)
{
	for (unsigned int i = 0; i < raySet.size(); i++)
	{
		for (unsigned int j = 0; j < circleSet.size(); j++)
		{
			pair<Point, Point> crossPair;
			const int result = getPoint(raySet.at(i), circleSet.at(j), crossPair);
			if (result == ONECROSS)
			{
				pointSet.insert(crossPair.first);
			}
			else if (result == TWOCROSS)
			{
				pointSet.insert(crossPair.first);
				pointSet.insert(crossPair.second);
			}
		}
	}
	return pointSet.size();
}

//Բ����
int calPoint(vector<Circle>& circleSet, set<Point>& pointSet)
{
	for (unsigned int i = 0; i < circleSet.size(); i++)
	{
		for (unsigned int j = i + 1; j < circleSet.size(); j++)
		{
			pair<Point, Point> crossPair;
			const int result = getPoint(circleSet.at(i), circleSet.at(j), crossPair);
			if (result == ONECROSS)
			{
				pointSet.insert(crossPair.first);
			}
			else if (result == TWOCROSS)
			{
				pointSet.insert(crossPair.first);
				pointSet.insert(crossPair.second);
			}
		}
	}
	return pointSet.size();
}

//�����ܽ������
int calPoint(vector<Line>& lineSet, vector<Segment>& segmentSet, vector<Ray>& raySet, vector<Circle>& circleSet, set<Point>& pointSet)
{
	calPoint(lineSet, pointSet);
	calPoint(lineSet, segmentSet, pointSet);
	calPoint(lineSet, raySet, pointSet);
	calPoint(lineSet, circleSet, pointSet);
	calPoint(segmentSet, pointSet);
	calPoint(segmentSet, raySet, pointSet);
	calPoint(segmentSet, circleSet, pointSet);
	calPoint(raySet, pointSet);
	calPoint(raySet, circleSet, pointSet);
	calPoint(circleSet, pointSet);
	return pointSet.size();
}
