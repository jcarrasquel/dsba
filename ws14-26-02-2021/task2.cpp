#include <map>
#include <vector>
#include <string>
#include <fstream>
#include <sstream>
#include <iostream>
#include <cmath>

using CityCoordinate = std :: pair<std::string, std::pair<double,double>>; // element of CityMaps --- a type for pairs (cityName, (latitude, longitude))

using CityMap = std :: map<std::string, std::pair<double,double>>; // a map of CityCoordinates (keys are city names, and values are latitude/longitue pairs).

using CityPair = std :: pair<std::string, std::string>;

using DistanceMap = std :: map<double, CityPair>;

const int CITY_COL = 0;
const int LATITUDE_COL = 1;
const int LONGITUDE_COL = 2;

double calculateDistance(const CityCoordinate& cityA, const CityCoordinate& cityB)
{
	// Returns the distance in kilometers between two cities (with coordinates) on the Earth.
	// Curious? :-) Check http://en.wikipedia.org/wiki/Haversine_formula

	double earthRadius = 6371.0;

	// convert latitude and longitude of cityA and cityB in degrees
	double latA, lonA, latB, lonB, u, v;
	
	latA = cityA.second.first * M_PI / 180;
	lonA = cityA.second.second * M_PI / 180;

	latB = cityB.second.first * M_PI / 180;
	lonB = cityB.second.second * M_PI / 180;
	
	u = sin((latB - latA)/2);
	v = sin((lonB - lonA)/2);

	return 2.0 * earthRadius * asin(sqrt(u * u + cos(latA) * cos(latB) * v * v));
}

void fillCityMap(CityMap& cityMap)
{
	std :: ifstream inputFile("cities.csv");

	std::string line, token; 

	std::getline(inputFile, line); // skip first line

	while(std::getline(inputFile, line)) // reading line-by-line
	{
		std::istringstream ss(line);

		std::vector<std::string> lineAsVector;

		while(std::getline(ss,token,','))
		{
			lineAsVector.push_back(token); // insert all words of this line in a vector
		}

		// Take the city, the latitude, and the longitude of the city from the lineAsVector
		// For example, you can take the city from the line like this lineAsVector[CITY_COL]
		// For converting the latitude and longitude from string to double you can use stod()

		std::string city = lineAsVector[CITY_COL];
		double latitude = stod(lineAsVector[LATITUDE_COL]);
		double longitude = stod(lineAsVector[LONGITUDE_COL]);

		// #1 Create a variable of type CityCoordinate, which is a pair (cityName, (latitude,longitude)). Look line 8 of this file.

		CityCoordinate cityCoordinate(city, std::make_pair(latitude, longitude));

		// #2 Add the created pair to the "cityMap" container
		cityMap.insert(cityCoordinate);
	}

	inputFile.close();
}

void fillDistanceMap(CityMap& cityMap, DistanceMap& distanceMap)
{
	// #3 Create a distance map of all possible pairs of cities in the city map (like a "cartesian product", you'll need a nested loop)
	// Keys in this new map will be the distances between two cities and values are pairs of cities

	// You can use the distance function in line 20 to get the distance between two cities
	// Use the function as follows calculateDistance(*i,*j) where *i and *j are iterators to two elements of cityMap.

	for(CityMap :: iterator i = cityMap.begin(); i != cityMap.end(); ++i)
	{
		for(CityMap :: iterator j = cityMap.begin(); j != cityMap.end(); ++j)
		{
			distanceMap[calculateDistance(*i, *j)] = std::make_pair(i->first, j->first);
		}
	}
}

void printFarthestDistanceBetweenCities(DistanceMap& distanceMap, int n)
{
	// Hint: reverse iterator might help you here :)

	DistanceMap :: reverse_iterator itr =  distanceMap.rbegin();

	std :: cout << "Cities with farthest distances between each other: " << n << std :: endl;

	int c = 0; 

	while(c < n)
	{
		std :: cout << "#" << c << ":" << itr->second.first << " <===> " << itr->second.second << " : " << itr->first << " kms" << std::endl;
		c++;
		++itr;
	}
}

int main()
{
	CityMap cityMap;

	fillCityMap(cityMap);

	DistanceMap distanceMap;

	fillDistanceMap(cityMap, distanceMap);

	printFarthestDistanceBetweenCities(distanceMap, 5); // print the n = 5 farthest distance between pairs of cities

	return 0;
}
