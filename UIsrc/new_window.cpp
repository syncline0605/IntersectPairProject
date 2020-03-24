#include "new_window.h"
#include "ui_new_window.h"
#include <QPainter>
#include <QPaintEvent>
#include <iostream>
#include <vector>
#include <QPen>
#include "define.h"
#include "GeoCalculate.h"
#include "GeoFigures.h"

using namespace std;

extern vector<Line> lineSet;
extern vector<Circle> circleSet;
extern set<Point> pointSet;
extern vector<Segment> segmentSet;
extern vector<Ray> raySet;

new_window::new_window(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::new_window)
{
    ui->setupUi(this);
}

new_window::~new_window()
{
    delete ui;
}

void new_window::paintEvent(QPaintEvent *event)
{

    vector<double> v(20);
    v[0] = 10;
    v[1] = 25.5;
    v[2] = 30.8;
    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing, true);

    painter.setPen(QColor(0, 0, 0));
    painter.drawLine(QPointF(0,500), QPointF(1000,500));
    painter.drawLine(QPointF(500,0), QPointF(500,1000));

    painter.setPen(QColor(0, 0, 255));
    // 原点在左上角，1000*1000的画布，对点坐标进行放大60倍处理
    double mul = 60;
    // 直线
    int i,n;
    for (i = 0;i < lineSet.size();i++) {
        double k = (lineSet[i].p2.y-lineSet[i].p1.y)/(lineSet[i].p2.x-lineSet[i].p1.x);
        double newx1 = lineSet[i].p1.x * mul;
        double newy1 = lineSet[i].p1.y * mul;
        double newx2 = lineSet[i].p2.x * mul;
        double newy2 = lineSet[i].p2.y * mul;
        double y1 = 500*k-newy1+k*newx1+500;
        double y2 = -500*k-newy1+k*newx1+500;
        painter.drawLine(QPointF(0,y1), QPointF(1000,y2));
    }
    // 圆
    for (i = 0;i < circleSet.size();i++) {
        painter.drawEllipse(QPointF((mul*circleSet[i].center.x+500),(-mul*circleSet[i].center.y+500)),mul*circleSet[i].r,mul*circleSet[i].r);
    }
    // 射线
    for (i = 0;i < raySet.size();i++) {
        double k = (raySet[i].direction.y-raySet[i].start.y)/(raySet[i].direction.x-raySet[i].start.x);
        double newx1 = raySet[i].start.x * mul;
        double newy1 = raySet[i].start.y * mul;
        double newx2 = raySet[i].direction.x * mul;
        double newy2 = raySet[i].direction.y * mul;
        double y1 = 500*k-newy1+k*newx1+500;
        double y2 = -500*k-newy1+k*newx1+500;
        if(raySet[i].start.x < raySet[i].direction.x) {
            painter.drawLine(QPointF((newx1+500), (-newy1+500)), QPointF(1000,y2));
        }
        else {
            painter.drawLine(QPointF(0,y1), QPointF((newx1+500), (-newy1+500)));
        }
    }
    // 线段
    for (i = 0;i < segmentSet.size();i++) {
        double k = (segmentSet[i].p2.y-segmentSet[i].p1.y)/(segmentSet[i].p2.x-segmentSet[i].p1.x);
        double newx1 = segmentSet[i].p1.x * mul;
        double newy1 = segmentSet[i].p1.y * mul;
        double newx2 = segmentSet[i].p2.x * mul;
        double newy2 = segmentSet[i].p2.y * mul;
        double y1 = 500*k-newy1+k*newx1+500;
        double y2 = -500*k-newy1+k*newx1+500;
        painter.drawLine(QPointF((newx1+500), (-newy1+500)), QPointF((newx2+500), (-newy2+500)));
    }
    // 点
    n = calPoint(lineSet, segmentSet, raySet, circleSet, pointSet);
    QPen pen;
    pen.setWidth(5);
    pen.setColor(Qt::red);
    painter.setPen(pen);
    set<Point>::iterator iter=pointSet.begin();
    while(iter!=pointSet.end())
    {
        double x = iter->x * mul;
        double y = iter->y * mul;
        painter.drawPoint(x+500,-y+500);
        ++iter;
    }
}
