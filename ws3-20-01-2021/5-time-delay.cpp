// waiting.cpp -- using clock() in a time-delay loop

#include <iostream>
#include <ctime> // describes clock() (elapsed time of the program) function, clock_t type

int main()
{
	std :: cout << "Enter the delay time, in seconds: ";
	float secs;
	std :: cin >> secs;
	
	clock_t delay = secs * CLOCKS_PER_SEC; // convert to clock ticks

	std :: cout << "starting\a\n";

	clock_t start = clock();

	while (clock() - start < delay )
		;
	
	std :: cout << "done \a\n";

	return 0;
}