#include "dialog.h"
#include "ui_dialog.h"
#include <QApplication>
#include <QWidget>
#include <QPushButton>
#include <QFile>
#include <QVector>
#include <QString>
#include <QFileDialog>
#include <QLabel>
#include <QTextStream>
#include <QDebug>
#include <QPainter>
#include <QPaintEvent>
#include "define.h"
#include "GeoCalculate.h"
#include "GeoFigures.h"
#include <QTextEdit>
#include <QPixmap>

vector<Line> lineSet;
vector<Circle> circleSet;
vector<Segment> segmentSet;
vector<Ray> raySet;
set<Point> pointSet;

Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);
    connect(ui->button1, SIGNAL(clicked(bool)), this, SLOT(readFile()));
    connect(ui->button2, SIGNAL(clicked(bool)), this, SLOT(addone()));
    connect(ui->button3, SIGNAL(clicked(bool)), this, SLOT(deleteone()));
    connect(ui->button4, SIGNAL(clicked(bool)), this, SLOT(open()));
}

Dialog::~Dialog()
{
    delete ui;
}

void Dialog::readFile()
{
    QString filename=QFileDialog::getOpenFileName(this,tr("打开文件"),".",tr("文件类型(*.txt)"));
    QFile file(filename);
    QVector<double> array;
    if(!file.open(QFile::ReadOnly|QFile::Text)){
        qDebug()<<"Error"<<endl;
    }

    QString str = file.readLine();    // 读第一行

    QByteArray t ;
    while(!file.atEnd())
    {
        str = file.readLine();
        t += str;

        str.remove("\r\n");
        QStringList list = str.split(" ");

        if(QString::compare(list.at(0), "L" )==0) {
            Line newline;
            newline.p1.x = list.at(1).toDouble();
            newline.p1.y = list.at(2).toDouble();
            newline.p2.x = list.at(3).toDouble();
            newline.p2.y = list.at(4).toDouble();
            lineSet.push_back(newline);
        }
        else if(QString::compare(list.at(0), "C" )==0) {
            Circle newcircle;
            newcircle.center.x = list.at(1).toDouble();
            newcircle.center.y = list.at(2).toDouble();
            newcircle.r = list.at(3).toDouble();
            circleSet.push_back(newcircle);
        }
        else if(QString::compare(list.at(0), "S" )==0) {
            Segment newseg;
            newseg.p1.x = list.at(1).toDouble();
            newseg.p1.y = list.at(2).toDouble();
            newseg.p2.x = list.at(3).toDouble();
            newseg.p2.y = list.at(4).toDouble();
            segmentSet.push_back(newseg);
        }
        else if(QString::compare(list.at(0), "R" )==0) {
            Ray newray;
            newray.start.x = list.at(1).toDouble();
            newray.start.y = list.at(2).toDouble();
            newray.direction.x = list.at(3).toDouble();
            newray.direction.y = list.at(4).toDouble();
            raySet.push_back(newray);
        }
    }

    ui->label->setText(QString(t));

    file.close();
}

void Dialog::open()
{
    new_win = new new_window;
    new_win->show();
}

void Dialog::addone()
{
    QString str = ui->text->toPlainText();
    QStringList list = str.split(" ");
    if(QString::compare(list.at(0), "L" )==0) {
        Line newline;
        newline.p1.x = list.at(1).toDouble();
        newline.p1.y = list.at(2).toDouble();
        newline.p2.x = list.at(3).toDouble();
        newline.p2.y = list.at(4).toDouble();
        lineSet.push_back(newline);
    }
    else if(QString::compare(list.at(0), "C" )==0) {
        Circle newcircle;
        newcircle.center.x = list.at(1).toDouble();
        newcircle.center.y = list.at(2).toDouble();
        newcircle.r = list.at(3).toDouble();
        circleSet.push_back(newcircle);
    }
    else if(QString::compare(list.at(0), "S" )==0) {
        Segment newseg;
        newseg.p1.x = list.at(1).toDouble();
        newseg.p1.y = list.at(2).toDouble();
        newseg.p2.x = list.at(3).toDouble();
        newseg.p2.y = list.at(4).toDouble();
        segmentSet.push_back(newseg);
    }
    else if(QString::compare(list.at(0), "R" )==0) {
        Ray newray;
        newray.start.x = list.at(1).toDouble();
        newray.start.y = list.at(2).toDouble();
        newray.direction.x = list.at(3).toDouble();
        newray.direction.y = list.at(4).toDouble();
        raySet.push_back(newray);
    }
    str.append(" successfully added!");
    ui->label_2->setText(str);
}

void Dialog::deleteone()
{
    QString str = ui->text->toPlainText();
    QStringList list = str.split(" ");
    int i;
    if(QString::compare(list.at(0), "L" )==0) {
        for(i = 0;i < lineSet.size();i++) {
            if(lineSet[i].p1.x == list.at(1).toDouble() && lineSet[i].p1.y == list.at(2).toDouble()
               && lineSet[i].p2.x == list.at(3).toDouble() && lineSet[i].p2.y == list.at(4).toDouble()) {
                lineSet.erase(lineSet.begin()+i);
                break;
            }
        }
    }
    else if(QString::compare(list.at(0), "C" )==0) {
        for(i = 0;i < circleSet.size();i++) {
            if(circleSet[i].center.x == list.at(1).toDouble() && circleSet[i].center.y == list.at(2).toDouble()
               && circleSet[i].r == list.at(3).toDouble()) {
                circleSet.erase(circleSet.begin()+i);
                break;
            }
        }
    }
    else if(QString::compare(list.at(0), "S" )==0) {
        for(i = 0;i < segmentSet.size();i++) {
            if(segmentSet[i].p1.x == list.at(1).toDouble() && segmentSet[i].p1.y == list.at(2).toDouble()
               && segmentSet[i].p2.x == list.at(3).toDouble() && segmentSet[i].p2.y == list.at(4).toDouble()) {
                segmentSet.erase(segmentSet.begin()+i);
                break;
            }
        }
    }
    else if(QString::compare(list.at(0), "R" )==0) {
        for(i = 0;i < raySet.size();i++) {
            if(raySet[i].start.x == list.at(1).toDouble() && raySet[i].start.y == list.at(2).toDouble()
               && raySet[i].direction.x == list.at(3).toDouble() && raySet[i].direction.y == list.at(4).toDouble()) {
                raySet.erase(raySet.begin()+i);
                break;
            }
        }
    }
    str.append(" successfully removed!");
    ui->label_2->setText(str);
}
