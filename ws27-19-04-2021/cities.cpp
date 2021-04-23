#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>
#include <cstdlib>
#include <algorithm>
#include <cstdint> 
#include <tuple>
#include <cstdlib>

enum CityField{country, name, population};

struct City
{
	std::string country;
	std::string name;
	int population;
};

class CityCompare
{
    public:

        bool operator()(City c1, City c2)
        {
            return std::make_tuple(c1.country, c1.population, c1.name) < std::make_tuple(c2.country, c2.population, c2.name);
        }
    // remember that also we can modify this function-like object to sort by specific attribute of city
    // here, it is very elegant to use for example the enum CityField to indicate which attribute use to sort! :)    
};

// function-style class

using CityVector = std::vector<City>;

std::ostream& operator<<(std::ostream& os, const City& city)
{
    os << "city=" << city.name << " population=" << city.population;
    os << " country=" << city.country;
    return os;
}

std::ostream& operator<<(std::ostream& os, const CityVector& c)
{
	for(int i = 0; i < c.size(); i++)
		os << c[i] << std :: endl;
	return os;
}

void fill(CityVector& c)
{
	std::ifstream inputFile("cities.csv");

    std::string line, token;

    std::getline(inputFile, line);

    while(std::getline(inputFile, line))
    {
        std::istringstream ss(line);

        std::vector<std::string> lineAsVector;
        while(std::getline(ss,token,','))
            lineAsVector.push_back(token);

        City city;
        city.name = lineAsVector[0];
        city.country = lineAsVector[3];
        city.population = atoi(lineAsVector[4].c_str());

        c.push_back(city);
    }
    inputFile.close();
}

int main()
{
	CityVector c; // std::vector<City>
	
	fill(c);

    // How to sort c by all attributes? Use of tuple

    CityCompare cmp;

    std::sort(c.begin(), c.end(), cmp);

    // many functions in the STL algorithm library

    City minCity = *std::min_element(c.begin(), c.end(), cmp);

    City maxCity = *std::max_element(c.begin(), c.end(), cmp);

	std::cout << c << std::endl;

    std :: cout << "MIN: " << minCity << std :: endl;

    std :: cout << "MAX: " << maxCity << std :: endl;

	return 0;
}