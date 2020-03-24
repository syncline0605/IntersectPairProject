#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QApplication>
#include <QWidget>
#include <QPushButton>
#include <QFile>
#include <QVector>
#include <QString>
#include <QFileDialog>
#include <QLabel>
#include <QTextStream>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


