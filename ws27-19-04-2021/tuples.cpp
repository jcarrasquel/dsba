#include <tuple>
#include <iostream>
#include <string>

using CityTuple = std::tuple<std::string,std::string,int>;

struct City
{
	std::string country;
	std::string name;
	int population;
};


int main()
{
	City c1 = {"Russia","Moscow",12000000};

	City c2 = {"Russia","SaintPetersburg",6000000};
	
	CityTuple v1 = std::make_tuple(c1.country,c1.name,c1.population);

	CityTuple v2 = std::make_tuple(c2.country,c2.name,c2.population);

	std :: cout << (v1 < v2) << std :: endl;

	return 0;
}