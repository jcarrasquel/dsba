#include <iostream>

// ============ employee.h ============ 

class Employee
{
	public:
		static double getMaxSalary();
		
		static double setMaxSalary(double ms);
	private:
		static double maxSalary; // static attribute = only one copy initialized in memory
};

// ============ employee.cpp ============ 

double Employee::maxSalary = 1000.0; // initialization of Employee context attribute (just once!)

double Employee::getMaxSalary()
{
	return maxSalary;
}

double Employee::setMaxSalary(double ms)
{
	maxSalary = ms;
}

//============  main.cpp ============ 

int main()
{
	//Employee::maxSalary = 2000.0; cannot initialize here!
	Employee::setMaxSalary(2000.0);
	std :: cout << Employee::getMaxSalary() << std::endl;
	return 0;
}