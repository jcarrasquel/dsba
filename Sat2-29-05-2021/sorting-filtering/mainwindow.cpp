#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <iostream>
#include <QFile>
#include <QFileDialog>

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

    /*model->setData(model->index(0, 0), "Tokio");
    model->setData(model->index(0, 1), 35.6897);
    model->setData(model->index(0, 2), 139.6922);
    model->setData(model->index(0, 3), "Japan");
    model->setData(model->index(0, 4), 37977000);

    model->setData(model->index(1, 0), "Jakarta");
    model->setData(model->index(1, 1), 6.2146);
    model->setData(model->index(1, 2), 106.8451);
    model->setData(model->index(1, 3), "Indonesia");
    model->setData(model->index(1, 4), 34540000);*/

    proxyModel = new QSortFilterProxyModel();
    proxyModel->setSourceModel(model);

    ui->tableView->setModel(proxyModel);
    ui->tableView->setSortingEnabled(true);
    ui->tableView->sortByColumn(4);

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_lineEdit_textChanged(const QString &arg1)
{
    QRegExp::PatternSyntax syntax = QRegExp::PatternSyntax(QRegExp::FixedString);

    Qt::CaseSensitivity caseSensitivity = Qt::CaseSensitive;

    QString text = ui->lineEdit->text();

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
}

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
}
