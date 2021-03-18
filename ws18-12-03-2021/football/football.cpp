// Implementation of methods for structures in "football.h"
#include "football.h"
#include <iostream>
#include <math.h>
#include <random>
#include <array>

/* === Implementation of structure FootballTeam === */

FootballTeam::FootballTeam(){}

FootballTeam::FootballTeam(std::string name, std::string city, std::string stadium, double level)
{
	_name = name;
	_city = city;
	_stadium = stadium;
	_level = level;

	_wins = 0;
	_losses = 0;
	_draws = 0;
	_points = 0;
}

std::string FootballTeam::getName()
{
	return _name;
}

std::string FootballTeam::getCity()
{
	return _city;
}

std::string FootballTeam::getStadium()
{
	return _stadium;
}

int FootballTeam::getPoints()
{
	return _points;
}

double FootballTeam::getLevel()
{
	return _level;
}

void FootballTeam::addWin()
{
	_wins++;
}

void FootballTeam::addLoss()
{
	_losses++;
}

void FootballTeam::addDraw()
{
	_draws++;
}

int FootballTeam::getWins()
{
	return _wins;
}

int FootballTeam::getLosses()
{
	return _losses;
}

int FootballTeam::getDraws()
{
	return _draws;
}


void FootballTeam::addPoints(int morePoints)
{
	_points = _points + morePoints;
}

/* === Declaration of structure Tournament === */

Tournament::Tournament()
{
	_round = 1;
}

void Tournament::simulateRound()
{

}

std::vector<FootballTeam>& Tournament::getTeams()
{
	return _teams;
}

/* === Implementation of structure Match === */

int Match::getLocalGoals()
{
	return _localGoals;
}

int Match::getVisitorGoals()
{
	return _visitorGoals;
}

FootballTeam& Match::getLocalTeam()
{
	return _localTeam;
}

FootballTeam& Match::getVisitorTeam()
{
	return _visitorTeam;
}

std::piecewise_linear_distribution<double> triangularDist(double min, double peak, double max)
{
	std::array<double, 3> i{min, peak, max};
    std::array<double, 3> w{0, 1, 0};
    return std::piecewise_linear_distribution<double>{i.begin(), i.end(), w.begin()};
}

void Match::play() 
{
	// "seed" for generating different random numbers on program execution
	std::random_device rd;
	std::mt19937 gen(rd());

	// how different team levels are?
	double diff = _localTeam.getLevel() - _visitorTeam.getLevel();

	// the maximum number of goals in a match, based on difference btw teams
	int maxGoals = ceil( std::abs(diff) * 10);

	// uniform distribution
	std::uniform_int_distribution<int> uniform(0, maxGoals);

	// generate the number of goals in the match
	int numberOfGoals = uniform(gen);

	// triangular distribution
	std::piecewise_linear_distribution<double> triangular = triangularDist(-1 * _localTeam.getLevel(), 0.0, _visitorTeam.getLevel());

	for(int i = 0; i < numberOfGoals; i++) // assign goals to teams
	{
		double x = triangular(gen); 

		if(x < 0)				// x is on the "left side" of the triangle?
		{
			_localGoals++;		// then, count a goal for the local team!
		}else
		{
			_visitorGoals++;	// else, count a goal of the visitor team!
		}
	}

	if(_localGoals > _visitorGoals) // local team won!
	{
		_localTeam.addWin();
		_localTeam.addPoints(3);
		_visitorTeam.addLoss();
	}

	if(_localGoals < _visitorGoals) // visitor team won!
	{
		_visitorTeam.addWin();
		_visitorTeam.addPoints(3);
		_localTeam.addLoss();
	}

	if(_localGoals == _visitorGoals) // a tie!
	{
		_localTeam.addPoints(1);
		_visitorTeam.addPoints(1);
		_localTeam.addDraw();
		_visitorTeam.addDraw();
	}
}