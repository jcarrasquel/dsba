#include <iostream>
#include "football.h"
#include <string>
#include <vector>
#include <fstream>
#include <sstream>
#include <algorithm>

void fillTeams(std::vector<FootballTeam>& teams)
{
	std::ifstream inputFile("football.csv");

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

		std::string name = lineAsVector[0];
		std::string city = lineAsVector[1];
		std::string stadium = lineAsVector[2];
		double level = stod(lineAsVector[3]);

		FootballTeam footballTeam(name, city, stadium, level);
		teams.push_back(footballTeam);
	}
}

void printTeams(std::vector<FootballTeam>& teams)
{
	// In each line, print the name of the team, the city and the stadium where the team plays
	for(int i = 0; i < teams.size(); i++)
	{
		std :: cout << teams[i].getName() << " " << teams[i].getCity() << " " << teams[i].getStadium() << " " << std :: endl;
	}
}

int main()
{
    Tournament tn;

    fillTeams(tn.getTeams());

    // a match between Zenit of Saint Petersburg and the rest of the teams   
    FootballTeam& zenit = tn.getTeams()[0];

    for(int i = 1; i < tn.getTeams().size(); i++)
    {
    	FootballTeam& otherTeam = tn.getTeams()[i];

    	Match m(zenit, otherTeam);

    	m.play();

    	// std :: cout << m << std :: endl;
    }

    std :: cout << "Zenit Team won " << zenit.getWins() << " matches!" << std :: endl;
    // std :: cout << zenit << std :: endl;

    return 0;
}