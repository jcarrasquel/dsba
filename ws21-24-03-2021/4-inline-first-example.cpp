#include <iostream>

inline double cube(double x)
{
	return x*x*x;
}

int main()
{
	double z1 = cube(5.0);

	double z2 = cube(3.0);

	return 0;
}