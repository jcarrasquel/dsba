#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>

double getFarePerClass(std:: ifstream& inputFile, int cabinClass);

int main()
{
    std :: ifstream inputFile("titanic.csv"); // path to the file
    
    for(int i = 1; i <= 3; i++){
        std :: cout << "Cabin class: " << i << " Avg Ticket Price: " << getFarePerClass(inputFile, i) << "$" << std :: endl;
        inputFile.clear();                     //clear the buffer
        inputFile.seekg(0, std::ios::beg);     //reset the reading position to beginning
    }

    //inputFile.close();
}

double getFarePerClass(std:: ifstream& inputFile, int cabinClass)
{
    std :: vector<double> myVector;
    std :: string line, token;

    while(getline(inputFile, line))
    {
        std::istringstream ss2(line);
        
        std::stringstream ss1; // auxiliary string stream for transforming string to double and int
        
        int tn;
        
        double tn1;
        
        int i = 0;
        
        int pcc;
        
        while(getline(ss2, token, ','))
        {
            if (i == 2) // check for class
            {
                // assign the class to variable pcc
                ss1 << token;
                ss1 >> tn;
                pcc = tn; // a bit redudant?
            }

            if (i == 9 && pcc == cabinClass) // pushing back fare in myVector
            {
                ss1.clear();

                ss1 << token;
                ss1 >> tn1;

                myVector.push_back(tn1);
            }
            i++;
        }

    }

    double acc = 0;

    for(int i = 0; i < myVector.size(); i++)
    {
        acc += myVector[i];
    }

    acc = acc / myVector.size();
    
    return acc;
}