#include <iostream>
#include <cmath>

typedef unsigned long long UInt;

typedef bool Bit;

int main()
{
	UInt a,i;

	std :: cin >> a >> i;

	UInt x = pow(2, i);

	UInt res = (a & x);

	Bit b = res == x;

	std :: cout << b << std :: endl;

	return 0;
}