#include "detailwindow.h"
#include "ui_detailwindow.h"
#include "student.h"
#include "globalvariables.h"
#include <QString>

DetailWindow::DetailWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DetailWindow)
{
    ui->setupUi(this);
}

void DetailWindow::setStudentDetail(int number, Student student)
{
    std::cout << "GLOBAL VARIABLE: " << GlobalVariables::data << std :: endl;

    ui->lineEdit->setText(QString::number(number + 1));
    ui->lineEdit_2->setText(QString::fromStdString(student.firstName));
    ui->lineEdit_3->setText(QString::fromStdString(student.lastName));
    ui->lineEdit_4->setText(QString::fromStdString(student.group));
    ui->lineEdit_5->setText(QString::number(student.history));
    ui->lineEdit_6->setText(QString::number(student.english));
    ui->lineEdit_7->setText(QString::number(student.math));
}

DetailWindow::~DetailWindow()
{
    delete ui;
}
