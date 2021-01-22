#include <iostream>
int main()
{
	int a, b;
	
	std :: cout << "Enter two integers: ";
	std :: cin >> a >> b;
	std :: cout << "The larger of " << a << " and " << b;

	int c = a > b ? a : b; // c = a if a > b, else c = b

	std :: cout << " is " << c << std :: endl;

	return 0;
}