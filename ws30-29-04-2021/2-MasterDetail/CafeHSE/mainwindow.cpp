#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include "cafemenu.h"
#include <iostream>
#include <QPixmap>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    model = new QStringListModel(this);
    model2 = new QStringListModel(this);

    QStringList productList = cafeMenu.getKeys(); // details

    model->setStringList(productList);

    ui->listView->setModel(model);
    ui->listView->setEditTriggers(QAbstractItemView::NoEditTriggers);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_listView_doubleClicked(const QModelIndex &index)
{
    //const QAbstractItemModel *item = index.model();

    std::string productName = (index.data().toString()).toStdString();

    std::cout << "Selecting: " << productName << std :: endl;

    QStringList productDetails = cafeMenu.getProductByKey(productName); // data

    model2->setStringList(productDetails);
    ui->listView_2->setModel(model2);
    ui->listView_2->setEditTriggers(QAbstractItemView::NoEditTriggers);

    // update image
    QPixmap image(cafeMenu.getImage(productName));
    ui->label_4->setPixmap(image);
    ui->label_4->setScaledContents(true);
}
