#include <iostream>
#include <string>

double divide(double x, double y)
{
	if(y == 0)
	{
		std :: string errorMessage = "bad divide() arguments: y = 0 not allowed";
		throw errorMessage; // like a "return"
	}
	return x / y;
}

int main()
{
	double x, y, z;

	while(std::cin >> x >> y)
	{
		try // start of exception handler
		{
			z = divide(x,y);
		}catch(std::string errorMessage)
		{
			std :: cout << errorMessage << std :: endl;
			continue;
		}
		std :: cout << x << " " << y << " " << z << std :: endl;
	}
	return 0;
}