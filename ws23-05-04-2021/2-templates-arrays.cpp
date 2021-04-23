#include <iostream>
#include <string>

template<typename T>
void mySwap(T& x, T& y)
{
	T temp;		// T must have a constructor!
	temp = x;	// ... and assignments!
	x = y;
	y = temp;
}

template<typename T, size_t n> // an array of n elements of T-type!
void mySwap(T(& x)[n], T(& y)[n])
{
	std::cout << n << std :: endl;

	for(size_t i = 0; i < n; ++i)
		mySwap(x[i], y[i]);
}

int main()
{
	std::string coffees[] = {"espresso", "americano", "latte"};

	std::string teas[] =  {"oolong", "ginger", "chamomile"};

	mySwap(coffees, teas);

	for(int i = 0; i < 3; i++)
		std :: cout << coffees[i] << std :: endl;

	for(int i = 0; i < 3; i++)
		std :: cout << teas[i] << std :: endl;

	return 0;
}
