#ifndef DETAILWINDOW_H
#define DETAILWINDOW_H

#include <QDialog>
#include "student.h"

namespace Ui {
class DetailWindow;
}

class DetailWindow : public QDialog
{
    Q_OBJECT

public:
    explicit DetailWindow(QWidget *parent = nullptr);
    ~DetailWindow();
    void setStudentDetail(int number, Student student);

private:
    Ui::DetailWindow *ui;

    Student studentDetail;
};

#endif // DETAILWINDOW_H
