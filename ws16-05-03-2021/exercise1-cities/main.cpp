#include <iostream>
#include "cities.h"
#include <string>
#include <vector>
#include <fstream>
#include <sstream>

const int CITY_COL = 0;
const int LAT_COL = 1;
const int LON_COL = 2;
const int COUNTRY_COL = 3;
const int POPULATION_COL = 4;

void fillCountries(std::vector<Country>& countries)
{
    std::ifstream inputFile("cities.csv");

    std::string line, token;

    std::getline(inputFile, line);

    while(std::getline(inputFile, line))
    {
        std::istringstream ss(line);

        std::vector<std::string> lineAsVector;
        while(std::getline(ss,token,','))
        {
            lineAsVector.push_back(token);
        }

        Coordinate coord;
        coord.latitude = stod(lineAsVector[LAT_COL]);
        coord.longitude = stod(lineAsVector[LON_COL]);

        // finish....
    }
    inputFile.close();
}

int main()
{
    std::vector<Country> countries;

    fillCountries(countries);

    for(int i = 0; i < countries.size(); i++)
        std :: cout << countries[i] << std :: endl;
}