#include <string>
#include <iostream>
#include <vector>

#ifndef CITIES_H
#define CITIES_H

struct Coordinate
{
    double latitude;
    double longitude;
};

std::ostream& operator<<(std::ostream& os, const Coordinate& c);

struct City
{
    std::string name;
    int population;
    Coordinate coordinate;

    // overload of <
	bool operator<(const City& c2)
	{
		return name < c2.name;
	}

};

std::ostream& operator<<(std::ostream& os, const City& city);

struct Country
{
    std::string name;
    std::vector<City> cities;
};

std::ostream& operator<<(std::ostream& os, const Country& country);

#endif
