#include <iostream>

typedef unsigned long long int UInt;

typedef bool Bit;

int main()
{
	UInt a;

	std :: cin >> a;

	UInt one = 1;

	UInt counter = 0;

	while(a > 0)
	{
		counter += a & one;
		a = a >> one;
	}

	std :: cout << counter << std :: endl;

	return 0;
}