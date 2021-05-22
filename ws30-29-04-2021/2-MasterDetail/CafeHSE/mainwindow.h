#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QStringListModel>
#include "cafemenu.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_listView_doubleClicked(const QModelIndex &index);

private:
    Ui::MainWindow *ui; // ui (view)

    QStringListModel *model; // names of all products model

    QStringListModel *model2; // product detail model

    CafeMenu cafeMenu; // data
};
#endif // MAINWINDOW_H
