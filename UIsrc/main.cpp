#include "mainwindow.h"
#include "dialog.h"
#include "GeoCalculate.h"
#include "GeoFigures.h"

#include <QApplication>
#include <QWidget>
#include <QPushButton>
#include <QFile>
#include <QVector>
#include <QString>
#include <QFileDialog>
#include <QLabel>
#include <QTextStream>

int main(int argc, char *argv[])
{

    QApplication a(argc, argv);
    Dialog w;

    w.show();
    return a.exec();
}

