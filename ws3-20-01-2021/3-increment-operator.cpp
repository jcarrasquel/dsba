// 3-increment-operator.cpp -- the increment operator
#include <iostream>
int main()
{
	int a = 20;
	int b = 20;

	std :: cout << "a = " << a << ": b = " << b << "\n"; // 20 20

	std :: cout << "a++ = " << a++ << ": ++b = " << ++b << "\n"; // 20 21

	std :: cout << "a = " << a << ": b = " << b << "\n";  // 21 21

	return 0;
}

