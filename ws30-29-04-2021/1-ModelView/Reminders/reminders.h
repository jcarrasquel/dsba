#ifndef REMINDERS_H
#define REMINDERS_H

#include<vector>
#include <string>
#include <fstream>
#include <iostream>
#include <QStringList>
#include <QStringListModel>
#include <QObject>

class Reminders : public QObject
{
    Q_OBJECT

    public:
        Reminders(QStringListModel* model)
        {
            pointerToModel = model;
        }
        QStringList read()
        {
            QStringList list;
            std::ifstream inputFile("reminders.txt");
            std::string line;
            while(std::getline(inputFile, line))
                list << QString::fromStdString(line);
            inputFile.close();
            return list;
        }
    public slots:
        void update()
        {
            std::ofstream outputFile("reminders.txt");
            for(int i = 0; i < pointerToModel->rowCount(); i++){
                QModelIndex index = pointerToModel->index(i);
                std::string reminder = (index.data().toString()).toStdString();
                outputFile << reminder << "\n";
            }
            outputFile.close();
        }
    private:
        QStringListModel* pointerToModel;
};

#endif
