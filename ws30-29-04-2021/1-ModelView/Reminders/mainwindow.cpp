#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <iostream>
#include <QAction>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    model = new QStringListModel(this);
    reminders = new Reminders(model);

    model->setStringList(reminders->read());
    ui->listView->setModel(model);

    QObject::connect(model, &QStringListModel::dataChanged, reminders, &Reminders::update);
    QObject::connect(model, &QStringListModel::rowsRemoved, reminders, &Reminders::update);
}

MainWindow::~MainWindow()
{
    delete reminders;
    delete model;
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    int row = model->rowCount();
    model->insertRows(row,1);

    QModelIndex index = model->index(row);

    ui->listView->setCurrentIndex(index);
    ui->listView->edit(index);
}

void MainWindow::on_pushButton_2_clicked()
{
    model->removeRows(ui->listView->currentIndex().row(), 1);
}
