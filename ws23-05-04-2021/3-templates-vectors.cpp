#include <iostream>
#include <string>
#include <vector>
#include <map>

using MyVector = std::vector<std::string>;

template<typename T>
void swap(T& x, T& y)
{
	T temp;		// T must have a constructor!
	temp = x;	// ... and assignments!
	x = y;
	y = temp;
}

template<typename C>
void swapVectors(C& x, C& y)
{
	for(size_t i = 0; i < x.size(); ++i) // caution! we assume .size() is defined for T !
	{
		swap(x[i], y[i]); // caution! we assume [] is overloaded!
	}
}

int main()
{
	MyVector coffees = {"espresso", "americano", "latte"};

	MyVector teas =  {"oolong", "ginger", "chamomile"};

	swapVectors(coffees, teas);

	for(int i = 0; i < 3; i++)
		std :: cout << coffees[i] << std :: endl;

	for(int i = 0; i < 3; i++)
		std :: cout << teas[i] << std :: endl;

	return 0;
}
