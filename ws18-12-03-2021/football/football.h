#include <string>
#include <iostream>
#include <vector>

#ifndef FOOTBALL_H
#define FOOTBALL_H

/* === Declaration of structure FootballTeam === */

struct FootballTeam
{
	public:
		// ----< Methods >----
		FootballTeam();
		FootballTeam(std::string name, std::string city, std::string stadium, double level);
		
		std::string getName();
		std::string getCity();
		std::string getStadium();

		int getPoints();
		double getLevel();
		int getWins();
		int getDraws();
		int getLosses();

		void addWin();
		void addDraw();
		void addLoss();
		void addPoints(int morePoints);
	
	private:
		// ----< Fields >----
		std::string _name;
		std::string _city;
		std::string _stadium;
		int _points;
		int _wins;
		int _losses;
		int _draws;
		double _level;
};

/* === Declaration of structure Tournament === */

struct Tournament
{
	public:
		// ----< Methods >----
		Tournament();
		void simulateRound();
		std::vector<FootballTeam>& getTeams();

	private:
		// ----< Fields >----
		std::vector<FootballTeam> _teams; 
		int _round;
};

/* === Declaration of structure Match === */

struct Match
{
	public:
		// ----< Methods >----
		Match(FootballTeam& lt, FootballTeam& vt) : _localTeam(lt), _visitorTeam(vt), _localGoals(0), _visitorGoals(0) {}
		void play();

		int getLocalGoals();
		int getVisitorGoals();
		FootballTeam& getLocalTeam();
		FootballTeam& getVisitorTeam();

	private:
		// ----< Fields >----
		int _localGoals;
		int _visitorGoals;
		FootballTeam& _localTeam;
		FootballTeam& _visitorTeam;
};

#endif