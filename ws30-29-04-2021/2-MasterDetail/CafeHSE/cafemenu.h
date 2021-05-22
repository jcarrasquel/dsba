#include <map>
#include <vector>
#include <string>
#include <sstream>
#include <fstream>
#include <algorithm>
#include <QStringList>

#ifndef CAFEMENU_H
#define CAFEMENU_H

struct Product
{
    std::string name;
    std::string price;
    std::string size;
    std::string description;
    std::string calories;
    std::string imagePath;
};

class CafeMenu
{
    public:
        CafeMenu()
        {
            fill();
        }

        QStringList getKeys()
        {
            QStringList l;

            std::map<std::string,Product>::iterator it;

            for(it = _m.begin(); it != _m.end(); ++it)
            {
                l << QString::fromStdString(it->first);
            }
            return l;
        }

        QStringList getProductByKey(std::string name)
        {
            QStringList l;

            Product p = _m[name];

            l << QString::fromStdString("Prod.: " + p.name);
            l << QString::fromStdString("Price: " + p.price);
            l << QString::fromStdString("Size: " + p.size);
            l << QString::fromStdString("Desc.: " + p.description);
            l << QString::fromStdString("Cals: " + p.calories);

            return l;
        }

        const char* getImage(std::string name)
        {
            return _m[name].imagePath.c_str();
        }

    private:

        std::map<std::string,Product> _m;

        void fill()
        {
            std::ifstream inputFile("cafe.csv");

            std::string line, token;

            std::getline(inputFile, line);

            while(std::getline(inputFile, line))
            {
                std::istringstream ss(line);

                std::vector<std::string> lineAsVector;
                while(std::getline(ss,token,','))
                    lineAsVector.push_back(token);

                std::string name = lineAsVector[0];
                std::string price = lineAsVector[1];
                std::string size = lineAsVector[2];
                std::string description = lineAsVector[3];
                std::string calories = lineAsVector[4];
                std::string imagePath = lineAsVector[5];

                Product product = {name, price, size, description, calories, imagePath};

                _m[name] = product;

            }
            inputFile.close();
        }
};

#endif
