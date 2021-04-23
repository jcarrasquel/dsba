#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <unordered_set>

using MyContainer = std::set<std::string>; // why not ordered MAPS, SETS

template<typename T>
void mySwap(T& x, T& y)
{
	T temp;			
	temp = x;		
	x = y;
	y = temp;
}

template<typename Iter> // a generic iterator
void swap(Iter xIt, Iter xEnd, Iter yIt, Iter yEnd)
{
	for(; xIt != xEnd; ++xIt, ++yIt)
	{
		//mySwap(xIt, yIt);
		std :: cout << *xIt << " " << *yIt << std :: endl;
	}
}


int main()
{
	MyContainer coffees = {"espresso", "americano", "latte"};

	MyContainer teas =  {"oolong", "ginger", "chamomile"};

	swap(coffees.begin(), coffees.end(), teas.begin(), teas.end());

	return 0;
}