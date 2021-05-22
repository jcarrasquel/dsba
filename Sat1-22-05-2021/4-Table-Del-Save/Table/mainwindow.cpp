#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include "secondwindow.h"
#include "detailwindow.h"
#include "addwindow.h"
#include "student.h"
#include "globalvariables.h"
#include <iostream>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    GlobalVariables::data = 100;

    model = new QStandardItemModel(2, 3, this); // my "table model" of dimension 2 x 3

    // headers
    model->setHorizontalHeaderItem(0, new QStandardItem("Name"));
    model->setHorizontalHeaderItem(1, new QStandardItem("Last Name"));
    model->setHorizontalHeaderItem(2, new QStandardItem("Group"));

    studentData = new StudentData(model);

    myDelegate = new Delegate(this);

    ui->tableView->setModel(model);

    // Assigning DELEGATE to VIEW
    // DELEGATES are a way to catch MODEL-VIEW communication
    ui->tableView->setItemDelegate(myDelegate);

    QObject::connect(model, &QStringListModel::dataChanged, studentData, &StudentData::update);
    QObject::connect(model, &QStringListModel::rowsRemoved, studentData, &StudentData::remove);
}

MainWindow::~MainWindow()
{
    delete studentData;
    delete model;
    delete ui;
    delete myDelegate;
}

void MainWindow::on_actionAbout_2_triggered()
{
    std :: cout << "[ABOUT] action in the menu bar triggered..." << std :: endl;
    SecondWindow secondWindow;
    secondWindow.setModal(true);
    secondWindow.exec();
}

void MainWindow::on_pushButton_clicked()
{
    //GlobalVariables::data 0;

    int selectedRow = ui->tableView->currentIndex().row();
    std :: cout << "[SEE DETAIL] of element in row " << selectedRow << std :: endl;
    DetailWindow detailWindow;

    Student student = studentData->getStudent(selectedRow);

    detailWindow.setStudentDetail(selectedRow, student);
    detailWindow.setModal(true);
    detailWindow.exec();
}

void MainWindow::on_pushButton_2_clicked()
{
    AddWindow addWindow;
    addWindow.setModelPointer(model);
    addWindow.setDataPointer(studentData); // this would be like setStudentDetail
    addWindow.setModal(true);
    addWindow.exec();
}

void MainWindow::on_pushButton_3_clicked()
{
    int selectedRow = ui->tableView->currentIndex().row();

    std :: cout << "Erasing row#" << selectedRow << std :: endl;

    model->removeRows(selectedRow, 1);
}

void MainWindow::on_pushButton_4_clicked()
{

    std :: cout << "Saving data to a file..." << std :: endl;

    studentData->save(this);
}
