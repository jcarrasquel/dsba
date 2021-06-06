#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <iostream>
#include <sstream>
#include <QFile>
#include <QFileDialog>
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    model = new QStandardItemModel(0, 5, parent);

    model->setHeaderData(0, Qt::Horizontal, QObject::tr("Name"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("Latitude"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("Longitude"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("Country"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("Population"));

    proxyModel = new MyProxyModel(); // new MyProxyModel()

    proxyModel->setSourceModel(model);

    ui->tableView->setModel(proxyModel);
    ui->tableView->setSortingEnabled(true);
    ui->tableView->sortByColumn(4);

    // MIN-MAX VALUES OF SPINBOXES
    ui->spinBox->setMinimum(0);
    ui->spinBox->setMaximum(50000000);
    ui->spinBox->setValue(0);

    ui->spinBox_2->setMinimum(0);
    ui->spinBox_2->setMaximum(50000000);
    ui->spinBox_2->setValue(50000000);
}

MainWindow::~MainWindow()
{
    delete ui;
}

/*void MainWindow::on_lineEdit_textChanged(const QString &arg1)
{
    QRegExp::PatternSyntax syntax = QRegExp::PatternSyntax(QRegExp::FixedString);

    Qt::CaseSensitivity caseSensitivity = Qt::CaseSensitive;

    QString text = ui->lineEdit->text(); // Accra

    QRegExp filter(text, caseSensitivity, syntax);

    proxyModel->setFilterRegExp(filter);
}

void MainWindow::on_comboBox_currentIndexChanged(int index)
{
    std::cout << "Changed sorting to column: " << ui->comboBox->currentIndex() << std :: endl;
    proxyModel->setFilterKeyColumn(ui->comboBox->currentIndex());
}

void MainWindow::on_pushButton_clicked()
{
    QModelIndex proxyIndex = ui->tableView->currentIndex();

    QModelIndex modelIndex = proxyModel->mapToSource(proxyIndex);

    std :: cout << "Proxy Index:" << proxyIndex.row() << " Model Index: " << modelIndex.row() << std :: endl;
}*/

void MainWindow::on_pushButton_2_clicked()
{
    QString fileName = QFileDialog::getOpenFileName(this,"Open File","*.csv");
    QFile file(fileName);
    file.open(QIODevice::ReadOnly);

    file.readLine();

    int row = 0;

    while(!file.atEnd())
    {
        QByteArray line = file.readLine();
        QList<QByteArray> lineAsVector = line.split(',');

        model->insertRows(row, 1);
        model->setData(model->index(row, 0), QString(lineAsVector.at(0)));
        model->setData(model->index(row, 1), lineAsVector.at(1).toDouble());
        model->setData(model->index(row, 2), lineAsVector.at(2).toDouble());
        model->setData(model->index(row, 3), QString(lineAsVector.at(3)));
        model->setData(model->index(row, 4), QString(lineAsVector.at(4)).toInt());
        row++;
    }

    QMessageBox messageBox;
    int countries = model->rowCount();
    messageBox.setWindowTitle("My Message Box");
    std::stringstream ss;
    ss << countries << " " << "countries have been loaded!\n";
    messageBox.setText(QString::fromStdString(ss.str()));
    messageBox.exec();
}

void MainWindow::on_spinBox_valueChanged(int arg1)
{
    proxyModel->setFilterMinPopulation(ui->spinBox->text().toInt());
}

void MainWindow::on_spinBox_2_valueChanged(int arg1)
{
     proxyModel->setFilterMaxPopulation(ui->spinBox_2->text().toInt());
}

void MainWindow::on_lineEdit_textChanged(const QString &arg1)
{
    proxyModel->setFilterCountry(ui->lineEdit->text());
}
