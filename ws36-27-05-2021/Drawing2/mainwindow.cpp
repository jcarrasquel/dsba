#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <iostream>
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

void example1(QPainter* painter)
{
    QPen myPen(Qt::blue);
    myPen.setWidth(2);
    myPen.setStyle(Qt::DashDotDotLine);

    painter->setPen(myPen);

    painter->setBrush(QBrush(Qt::green));

    /* QPainter::drawRect ( int x, int y, int width, int height )
     * ----------------------------------------------------------
     * Draw a rectangle with top-left corner at (x,y)=(70,20) with width=100 and height=100*/

    painter->drawRect(70, 120, 300, 50);
}

void example2(QPainter* painter)
{
    painter->setPen(Qt::white);
    painter->setBrush(QBrush(QBrush(Qt::white)));
    painter->drawRect(10, 40, 100, 25);

    painter->setPen(Qt::darkBlue);
    painter->setBrush(QBrush(QBrush(Qt::darkBlue)));
    painter->drawRect(10, 65, 100, 25);

    painter->setPen(Qt::red);
    painter->setBrush(QBrush(QBrush(Qt::red)));
    painter->drawRect(10, 90, 100, 25);

    // Loading the double-headed bizantine eagle
    QImage image;
    image.load("eagle.png");
    QImage scaledImage = image.scaled(50, 50, Qt::KeepAspectRatio);
    painter->drawImage(38, 55, scaledImage);
}

// this method shall be called each time when the window is built
void MainWindow::paintEvent(QPaintEvent *e)
{
    // A class that allows you to paint on the window
    QPainter painter(this);

    example2(&painter);
}


