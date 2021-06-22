#ifndef PERSON_H
#define PERSON_H

#include <iostream>

class Person
{
	public:

		Person(std::string name)
		{
			this->_name = name;
			std::cout<< "Person(): " << _name << std::endl;
		}

		~Person()
		{
			std::cout<< "~Person(): "<< _name << std::endl;
		}

		virtual int calcSalary()
		{
			return 1000;
		}

		std::string getName()
		{
			return _name;
		}

	protected:
		std::string _name;
};

class Student : public Person
{
	public:

		Student(std::string name, int averageMark)
			: Person(name), _averageMark(averageMark)
		{
			std::cout<< "Student(): " << _name << std::endl;
		}

		~Student()
		{
			std::cout<< "~Student(): " << _name << std::endl;
		}

		int getAverageMark()
		{
			return _averageMark;
		}

		virtual int calcSalary() override
		{
			return _averageMark * 200;
		}

	protected:
		int _averageMark;
};

class Professor : public Person
{
	public:
		
		Professor(std::string name, int qualification)
			: Person(name), _qualification(qualification)
		{
			std::cout<< "Professor(): " << _name << std::endl;
		}

		~Professor()
		{
			std::cout<< "~Professor(): " << _name << std::endl;
		}

		int getQualification()
		{
			return _qualification;
		}

		virtual int calcSalary() override
		{
			return _qualification * 500;
		}

	private:
		int _qualification;
};

#endif