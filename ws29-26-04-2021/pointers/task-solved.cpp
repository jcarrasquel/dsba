#include <iostream>
#include <fstream>
#include <sstream>
#include <map>
#include <vector>
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
	std::string name;
	Coordinate coordinate;
	std::string country;
	int population;
	
	City(std::string cityName, Coordinate coord, std::string con, int pop)
	{
		name = cityName;
		coordinate = coord;
		country = con;
		population = pop;
	}
};

struct CityMap
{
	public:
		void insertCity(std::string cityName, Coordinate coordinate, std::string country, int population)
		{
			// ===< TASK 1 >=== 
			City* newCity = new City(cityName, coordinate, country, population);
			_m[cityName] = newCity;	
		}

		City* findCity(std::string cityName)
		{
			// ===< TASK 2 >=== 
			City* c = nullptr;
			for(std::pair<std::string,City*> e : _m)
			{
				if(e.first == cityName)
				{
					c = e.second;
					break;
				}
			}
			return c;
		}

		void deleteCity(std::string cityName)
		{
			// ===< TASK 3 >=== 
			City* c = findCity(cityName);
			if(c != nullptr)
			{
				delete c;
				_m.erase(cityName);
			}
		}

		void deleteAllCities()
		{
			// ===< TASK 4 >=== 
			for(std::pair<std::string,City*> e : _m)
				delete e.second;
			_m.clear();
		}

		int size()
		{
			return _m.size();
		}

	private:
		std::map<std::string, City*> _m;
};

void fill(CityMap& cityMap);
void test(CityMap& cityMap);

int main()
{
	CityMap cityMap;
	fill(cityMap);
	test(cityMap);

	return 0;
}

// ===========================================================

void fill(CityMap& cityMap)
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

        std::string cityName = lineAsVector[0];
        Coordinate coordinate = { stod(lineAsVector[1]),  stod(lineAsVector[2]) };
        std::string country = lineAsVector[3];
        int population = atoi(lineAsVector[4].c_str());

        // inserting city inside the map
        cityMap.insertCity(cityName, coordinate, country, population);

    }
    inputFile.close();
}

void test(CityMap& cityMap)
{
	if(cityMap.size() > 0){
		std::cout << cityMap.size() << " cities were added! [OK]" << std::endl;
	}else{
		std::cout << "No cities added! [ERROR]" << std::endl;
		return;
	}

	City* c1 = cityMap.findCity("Moscow");
	City* c2 = cityMap.findCity("Venice");

	if(c1 != nullptr)
		std::cout << c1->name << "," << c1->country << " has been found [OK]" << std::endl;

	if(c2 == nullptr)
		std::cout << "Venice not found! [OK]" << std::endl;

	cityMap.deleteCity("Moscow");
	City* c3 = cityMap.findCity("Moscow");
	if(c3 == nullptr)
		std::cout << "Moscow deleted! New map size: " << cityMap.size() << " [OK]" << std::endl;

	cityMap.deleteAllCities();

	std::cout << "Deleting all cities. New map size: " << cityMap.size() << " [OK]" << std::endl;	

}