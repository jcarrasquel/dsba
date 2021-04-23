#include <iostream>
#include <string>

template<typename T>
void mySwap(T& x, T& y)
{
	T temp;		// T must have a constructor!
	temp = x;	// ... and assignments!
	x = y;
	y = temp;
}

int main()
{
	int a = 10; 
	int b = 15;

	mySwap<int>(a,b);
	mySwap(a, b); // the compiler infers the data types with the arguments!

	std::cout << a << " " << b << std::endl;
	
	double d1 = 3.14;
	double d2 = 2.4;

	mySwap(d1, d2);

	std::string s1("Hello"), s2("World");
	mySwap(d1, d2);

	return 0;
}