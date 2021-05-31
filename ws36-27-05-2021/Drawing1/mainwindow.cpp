#include "mainwindow.h"
#include "./ui_mainwindow.h"

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
    // Window Positioning System
    // TOP-LEFT of your window is position is (0,0). Y-axis growths from TOP to bottom.

    QPoint a;
    a.setX(10);
    a.setY(10);

    QPoint b;
    b.setX(100);
    b.setY(100);

    QPoint c;
    c.setX(10);
    c.setY(100);

    painter->drawLine(a, b); // draw a line between points (10,10) and (100, 100)
    painter->drawLine(a, c);
    painter->drawLine(c, b);
}











void example2(QPainter* painter)
{
    QPen myPen(Qt::blue); // like a blue pencil
    myPen.setWidth(4); // you set how thick the pencil draws

    QPoint p1;
    p1.setX(10);
    p1.setY(10);

    QPoint p2;
    p2.setX(100);
    p2.setY(100);

    // Tell to the system that you want to "paint" with your "pen"
    painter->setPen(myPen);
    painter->drawLine(p1,p2);

    // You can change again the "pen" you use for drawing other things! :)
    QPen myPen2(Qt::darkBlue); // now paint in dark blue
    myPen2.setWidth(6); // even thicker

    painter->setPen(myPen2);
    painter->drawPoint(p1);
    painter->drawPoint(p2);
}


// this method shall be called each time when the window is built
void MainWindow::paintEvent(QPaintEvent *e)
{
    // A class that allows you to paint on the window
    QPainter painter(this); // canvas

    example2(&painter);
}
