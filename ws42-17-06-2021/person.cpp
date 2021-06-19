#include "person.h"
#include <iostream>

//==============================================================================
// class Person
//==============================================================================

double Person::calcSalary() const
{
	std::cout << "Calculating Person() salary..." << std::endl;
    return 1000;
}

//==============================================================================
// class Student
//==============================================================================

double Student::calcSalary() const
{
	std::cout << "Calculating Student() salary..." << std::endl;
    for(int curMark : _grades)
        if(curMark < 6)
            return 0;

    return _grades.size() * 500;
}

//==============================================================================
// class Professor
//==============================================================================

double Professor::calcSalary() const
{
	std::cout << "Calculating Professor() salary..." << std::endl;
    return _qualPeriod * 1000;
}