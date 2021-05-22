#include "addwindow.h"
#include "ui_addwindow.h"
#include <QString>

AddWindow::AddWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AddWindow)
{
    ui->setupUi(this);
}

void AddWindow::setModelPointer(QStandardItemModel* model)
{
    pointerToModel = model;
}

void AddWindow::setDataPointer(StudentData *studentData)
{
    pointerToStudentData = studentData;
}

AddWindow::~AddWindow()
{
    delete ui;
}

void AddWindow::on_pushButton_clicked()
{
    int row = pointerToModel->rowCount(); // 2

    pointerToModel->insertRows(row, 1); // inserting row #2 (we have now three rows)

    QModelIndex index = pointerToModel->index(row, 0, QModelIndex());
    pointerToModel->setData(index,ui->lineEdit->text());

    index = pointerToModel->index(row, 1, QModelIndex());
    pointerToModel->setData(index,ui->lineEdit_2->text());

    index = pointerToModel->index(row, 2, QModelIndex());
    pointerToModel->setData(index,ui->lineEdit_3->text());

    // add marks for the student recently added!
    int history = ui->lineEdit_4->text().toInt();
    int english = ui->lineEdit_5->text().toInt();
    int math = ui->lineEdit_6->text().toInt();
    pointerToStudentData->setMarks(history,english,math,row);
}
