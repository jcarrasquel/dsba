#include <iostream>

// ==== Employee.h

struct Employee
{
	static double maxSalary; // static attribute = only one copy initialized in memory
};

// Employee.cpp

double Employee::maxSalary = 2000.0; // must to initialize the static attributes of the class

// main.cpp

int main()
{
	Employee e1;
	Employee e2;

	std::cout << e1.maxSalary << " " << e2.maxSalary << std :: endl;

	Employee::maxSalary = 900.0;

	std::cout << e1.maxSalary << " " << e2.maxSalary << std::endl;

}
