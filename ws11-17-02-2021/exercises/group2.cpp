// Exercise 2 - Group 2. 17.02.2021. Count passengers and number of survivors by gender (male/female)

#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>

void printNumberOfSurvivorsByGender(std:: ifstream& inputFile);

int main()
{
    std :: ifstream inputFile("titanic.csv");

    printNumberOfSurvivorsByGender(inputFile);

    inputFile.close();
}

void printNumberOfSurvivorsByGender(std:: ifstream& inputFile)
{
    std :: string line, token;

    while(getline(inputFile, line)) // reading line-by-line
    {
        std::istringstream ss(line);
       
        int numberOfColumn = 0;

        // Complete here...
        
        while(getline(ss, token, ',')) // reading word-by-word in a line, separated by commas.
        {
        	// Complete here...

        	numberOfColumn++;
        }
    }

    // Print here number of passengers per gender, and also the number of gender per class.

    /* EXAMPLE
    std :: cout << "Male Passengers: " << numberOfMalePassengers << " Number of Male Survivors: " << numberOfMaleSurvivors << std :: endl;
    std :: cout << "Female Passengers: " << numberOfFemalePassengers << " Number of Female Survivors: " << numberOfFemaleSurvivors << std :: endl;
    */
}