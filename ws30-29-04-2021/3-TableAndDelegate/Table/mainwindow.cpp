#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include "secondwindow.h"
#include <iostream>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    myDelegate = new Delegate(this);

    model = new QStandardItemModel(5, 2, this); // my "table model" of dimension 4 x 2

    // fill the model with data
    for(int row = 0; row < 5; ++row)
    {
        for(int col = 0; col < 2; ++col)
        {
            QModelIndex index = model->index(row, col, QModelIndex());
            model->setData(index, 0); // initialize a cell in the model with zero value (you can also put a string instead of 0)
        }
    }

    ui->tableView->setModel(model);

    // Assigning DELEGATE to VIEW
    // DELEGATES are a way to catch MODEL-VIEW communication
    ui->tableView->setItemDelegate(myDelegate);
}

MainWindow::~MainWindow()
{
    delete model;
    delete ui;
    delete myDelegate;
}

void MainWindow::on_actionAbout_2_triggered()
{
    std :: cout << "About action in the menu bar triggered..." << std :: endl;
    SecondWindow secondWindow;
    secondWindow.setModal(true);
    secondWindow.exec();
}
