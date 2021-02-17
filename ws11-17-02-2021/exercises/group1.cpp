// Exercise 1 - Group 1. 17.02.2021. Count passengers and number of survivors by class 1, 2 and 3.

#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>

void printNumberOfSurvivorsByClass(std:: ifstream& inputFile);

int main()
{
    std :: ifstream inputFile("titanic.csv");

    printNumberOfSurvivorsByClass(inputFile);

    inputFile.close();
}

void printNumberOfSurvivorsByClass(std:: ifstream& inputFile)
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

    // Print here number of passengers per class, and also the number of survivors per class.

    /* EXAMPLE
    for(int i = 0; i < 3; i++)
    {
		std :: cout << "Class #" << i + 1 << " Number of Passengers: " << numberOfPassengers[i] << " Number of Survivors: " << numberOfSurvivors[i] << std :: endl;
    } 
    */
}