#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>

double getFarePerClass(std:: ifstream& inputFile, int cabinClass);

using namespace std;

int main()
{
    std :: ifstream inputFile("titanic.csv"); // path to the file
    cout << getFarePerClass(inputFile, 3) << endl;
}

double getFarePerClass(std:: ifstream& inputFile, int cabinClass)
{
    std :: vector<double> myVector;
    string line, token;
    while(getline(inputFile, line))
    {
        std::istringstream ss2(line);
        std::stringstream ss1;
        int tn;
        double tn1;
        int i = 0;
        int pcc;
        while(getline(ss2, token, ','))
        {
            if (i == 2) // check for class
            {
                ss1 << token;
                ss1 >> tn;
                pcc = tn;
            }
            if (i == 9) // pushing back fair in myVector
            {
                if (pcc == cabinClass)
                {
                    ss1 << token;
                    ss1 >> tn1;
                    myVector.push_back(tn1);
                }
            }
            i++;
        }

    }
    inputFile.close();
    double acc = 0;
    for(int i = 0; i < myVector.size(); i++)
    {
        acc += myVector[i];
    }
    acc = acc/myVector.size();
    return acc;
}