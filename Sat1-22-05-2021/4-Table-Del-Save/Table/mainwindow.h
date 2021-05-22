#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtCore>
#include <QtGui>

// include our delegate
#include "delegate.h"
#include "student.h"

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

    StudentData* studentData; // data

    Ui::MainWindow* ui; // the views

    QStandardItemModel* model; // our "table-like" model

    Delegate* myDelegate; // my delegate to catch view-model interaction

    // my nice actions inside the menu bar

    QAction* about;

private slots:

    void on_actionAbout_2_triggered();
    void on_pushButton_clicked();
    void on_pushButton_2_clicked();
    void on_pushButton_3_clicked();
    void on_pushButton_4_clicked();
};
#endif // MAINWINDOW_H
