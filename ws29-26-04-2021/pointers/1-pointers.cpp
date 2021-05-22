#include <iostream>

int main()
{
	int a = 42;

	int& r = a;
	r = 43;

	int* p = &a;
	*p = 44;

	std :: cout << a << std :: endl;
	std :: cout << r << std :: endl;
	
	std :: cout << p << std :: endl;
	std :: cout << *p << std :: endl;
	
	std :: cout << &a << std :: endl;
	std :: cout << &p << std :: endl;	

	return 0;
}


