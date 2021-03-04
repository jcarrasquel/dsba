#include <map>
#include <vector>
#include <string>
#include <fstream>
#include <sstream>
#include <iostream>

using CityPopulation = std :: pair<std::string, int>;

using CountryMap = std :: map<std::string, std::vector<CityPopulation>>;

using PopulationMap = std :: map<int, std::string>;

const int CITY_COL = 0;
const int COUNTRY_COL = 3;
const int POPULATION_COL = 4;

void fillCountryMap(CountryMap& countryMap)
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

		// Take the city, the country, and the population of the city from the lineAsVector
		// For example, you can take the city from the line like this lineAsVector[CITY_COL]
		// For the population, you can also transform string to integer using stoi()
		std::string city = lineAsVector[CITY_COL];
		std::string country = lineAsVector[COUNTRY_COL];
		int population = stoi(lineAsVector[POPULATION_COL]);

		// #1 Create a variable of type CityPopulation (see line 8) and fill it with the city name and the population size of the current line
		
		CityPopulation cityPopulation(city, population);

		// #2 Add the created pair city-population to the "countryMap"
		// - 2.1 You need to check if there is an element in the countryMap whose key is the name of the country (lineAsVector[COUNTRY_COL])
		// - 2.2 If there is no, create a new element in countryMap where the pair is name of the country, and the value is vector that you need to create of CityPopulation elements.
		// - 2.3 Then, you add the pair you created in the vector in position countryMap[lineAsVector[COUNTRY_COL]]

		if(countryMap.find(country) == countryMap.end())
		{
			std::vector<CityPopulation> v;

			countryMap[country] = v; 
		}

		countryMap[country].push_back(cityPopulation);

	}

	inputFile.close();
}

void createPopulationMap(CountryMap& countryMap, PopulationMap& populationMap)
{
	// #3.1 BEGIN FOR you need to iterate in thru' the countryMap, to move thru' countries
	// Remember that the countryMap is a collection of pairs (countryNames, vectors of cityPopulation)

		// # 3.2 Then, in an inner loop, you need to move thru' an element of the map (a vector)
		// When moving through the vector, you move thru' pairs (cityName, population)
		// You need to accumulate in a variable the population of all cities of a country 
		
		// 3.3 After the inner loop, you finally to create a entry in the populationMap where the key is the accumulator!
		// for example, populaitonMap[accumulator] = countryName
	// END FOR

	for(std::pair<std::string, std::vector<CityPopulation>> el : countryMap)
	{
		int accumulator = 0; // total population of all the stored cities of a country 
		for(CityPopulation x : el.second)
			accumulator += x.second;
		
		populationMap[accumulator] = el.first;
	}
}	

void printMostPopulatedCountries(PopulationMap& populationMap, CountryMap& countryMap, int n)
{
	// #4 Use the n = 5 last positions of the populationMap to get the country names
	// With the country names, then you have the "keys" to know the "values" (vectors of cities) we want to print from the countryMap
	// Hint: here you also need a nested loop.

	PopulationMap :: reverse_iterator itr =  populationMap.rbegin();

	std :: cout << "Countries with most populated cities: " << n << std :: endl;

	int c = 0; 

	while(c < n)
	{
		std :: string country = itr->second;
		std :: cout << "#" << c+1 << " " << country << " cities: " << countryMap[country].size() << std :: endl;
		for(CityPopulation x : countryMap[country])
		{
			std :: cout << x.first << " => " << x.second << std::endl;
		}
		std :: cout << std :: endl;
		c++;
		++itr;
	}

}

int main()
{
	CountryMap countryMap;

	fillCountryMap(countryMap);

	PopulationMap populationMap;

	createPopulationMap(countryMap, populationMap);

	printMostPopulatedCountries(populationMap, countryMap, 5); // print cities (and their population) of the n = 5 most populated countries

	return 0;
}