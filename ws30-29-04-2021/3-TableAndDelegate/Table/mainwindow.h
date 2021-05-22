#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtCore>
#include <QtGui>

// include our delegate
#include "delegate.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget* parent = nullptr);
    ~MainWindow();

private:

    Ui::MainWindow* ui; // the views

    QStandardItemModel* model; // our "table-like" model

    Delegate* myDelegate; // my delegate to catch view-model interaction


    // my nice actions inside the menu bar

    QAction* about;

private slots:

    void on_actionAbout_2_triggered();
};
#endif // MAINWINDOW_H
