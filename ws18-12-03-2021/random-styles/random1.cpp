#include <random>

int main()
{
	int a = 0;
	int b = 10;

	// seed
	std::random_device	r;
	std::mt19937        gen(r());

	// uniform random number generator
	std::uniform_int_distribution<int> u(a, b); // [a,b]

	int randomNumber = u(gen);

	int nextRandomNumber = u(gen);

	return 0;
}



