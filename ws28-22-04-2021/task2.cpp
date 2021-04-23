#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <set>
#include <tuple>
#include <cstdint> 
#include <cstdlib>
#include <algorithm>

struct Coordinate
{
    double lat;
    double lon;
};

struct City
{
	std::string country;
	std::string name;
	int population;
    Coordinate coordinate;
};

using CityVector = std::vector<City>;

double distanceToMoscow(const City& city);
void fill(CityVector& c);

// ======================================================
// ======================================================

class CityPrinter
{
	// Your code here...
};

class CityDistanceChecker
{
	// Your code here...
};

void task(CityVector v)
{
	// Your code here...
}

// ======================================================
// ======================================================


int main()
{
	CityVector v;
	fill(v);

	task(v);

	return 0;
}

// ======================================================

double distanceToMoscow(const City& city)
{
	// Returns the distance in kilometers between a city and Moscow

	double earthRadius = 6371.0;
	double moscowLat = 55.7558;
	double moscowLon = 37.6178;

	// convert latitude and longitude of cityA and cityB in degrees
	double latA, lonA, latB, lonB, u, v;
	
	latA = city.coordinate.lat * M_PI / 180;
	lonA = city.coordinate.lon * M_PI / 180;

	latB = moscowLat * M_PI / 180;
	lonB = moscowLon * M_PI / 180;
	
	u = sin((latB - latA)/2);
	v = sin((lonB - lonA)/2);

	return 2.0 * earthRadius * asin(sqrt(u * u + cos(latA) * cos(latB) * v * v));
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

        Coordinate coordinate;
        coordinate.lat = stod(lineAsVector[1]);
        coordinate.lon = stod(lineAsVector[2]);

        City city;
        city.name = lineAsVector[0];
        city.country = lineAsVector[3];
        city.population = atoi(lineAsVector[4].c_str());
        city.coordinate = coordinate;

        c.push_back(city);
    }
    inputFile.close();
}