#ifndef STUDENT_H
#define STUDENT_H

#include <string>
#include <sstream>
#include <iostream>
#include <vector>
#include <QStringList>
#include <QObject>
#include <QtCore>
#include <QtGui>
#include <QFileDialog>
#include <QFile>
#include <QMainWindow>

struct Student // a student with marks 0...10 in three subjects
{
    std::string firstName;
    std::string lastName;
    std::string group;

    int history;
    int english;
    int math;
};

class StudentData : public QObject
{
    Q_OBJECT

    public:
        StudentData(QStandardItemModel* model)
        {
            Student student1 = {"John","Smith","204-2",9,10,9};
            Student student2 = {"Lucy","Andrews","203-1",8,7,8};

            _data.push_back(student1);
            _data.push_back(student2);

            pointerToModel = model;
            initModel();
        }

        void save(QMainWindow* window)
        {
            QString filename = QFileDialog::getSaveFileName(window, "Save file", "", ".csv");
            QFile f(filename);
            f.open(QIODevice::WriteOnly);
            f.write("firstName,lastName,group,history,english,math\n");
            for(int i = 0; i < (int) _data.size(); i++)
            {
                std::stringstream ss;
                ss << _data[i].firstName << "," << _data[i].lastName << "," << _data[i].group << "," << _data[i].history << "," << _data[i].english << "," << _data[i].math << "\n";
                f.write(ss.str().c_str());
            }
            f.close();
        }

        Student getStudent(int i)
        {
            return _data[i];
        }

        void setMarks(int history, int math, int english, int i)
        {
            // set marks for student #i in the _data
            std::cout << "Setting marks: history=" << history << " math=" << math << " english=" << english << " for student "<< _data[i].firstName << std :: endl;
            _data[i].history = history;
            _data[i].math = math;
            _data[i].english = english;
        }

        void initModel()
        {
            // fill the model with data
            for(int row = 0; row < 2; row++)
            {
                for(int col = 0; col < 3; col++)
                {
                    QModelIndex index = pointerToModel->index(row, col, QModelIndex());
                    QString cellValue;
                    switch(col)
                    {
                        case 0: cellValue = QString::fromStdString(_data[row].firstName);
                                break;

                        case 1: cellValue = QString::fromStdString(_data[row].lastName);
                                break;

                        case 2: cellValue = QString::fromStdString(_data[row].group);

                                break;
                    }

                    pointerToModel->setData(index, cellValue); // initialize a cell in the model with zero value (you can also put a string instead of 0)
                }
            }
        }

        void remove()
        {
            // A student was removed from the model. Update the data
            _data.clear();
            update();
        }

        void update()
        {
            std :: cout << "Cell updated! Updating data..." << std::endl;

            for(int row = 0; row < pointerToModel->rowCount(); row++){

                if(row >= (int) _data.size())           // if the "model" has more elements than the "data"
                    _data.push_back(Student());         // add a new element to the "data".

                for(int col = 0; col < pointerToModel->columnCount(); col++)
                {
                    QModelIndex index = pointerToModel->index(row,col);
                    std::string cellValue = (index.data().toString()).toStdString();

                    switch(col)
                    {
                        case 0: _data[row].firstName = cellValue;
                                break;

                        case 1: _data[row].lastName = cellValue;
                                break;

                        case 2: _data[row].group = cellValue;
                                break;
                    }
                }
            }
        }

    private:
        std::vector<Student> _data;

        QStandardItemModel* pointerToModel;
};

#endif // STUDENT_H
