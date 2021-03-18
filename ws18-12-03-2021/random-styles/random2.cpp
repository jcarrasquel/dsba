#include <ctime>
#include <cstdlib>

int main()
{
	int a = 0; 
	int b = 10;

	// seed
	srand(time(NULL));

	// No generator object.
	// For [a,b], use: (rand() % (b+1-a)) + a

	int randomNumber = (rand() % (b + 1 - a)) + a; 

	int nextRandomNumber = (rand() % (b + 1 - a)) + a;

	return 0;
}





