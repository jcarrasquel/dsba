#include <iostream>

struct City
{
	std::string name;
	std::string country;
	int population;
	City(){}
	City(std::string nam, std::string con, int pop)
	{
		name = nam;
		country = con;
		population = pop;
	}
	void print()
	{
		std :: cout << name << "," << country << std :: endl;
	}
};

int main()
{
	int* a = new int(19000000);

	City *c;
	
	c = new City();

	c->name = "New York";
	c->country = "USA";
	c->population = *a;

	c->print();

	std :: cout << &(c->population) << " " << &a << std :: endl;

	delete a;

	delete c;

	//std :: cout << c->name << std :: endl; ?
}