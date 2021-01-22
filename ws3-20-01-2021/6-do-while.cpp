// 6 dowhile.cpp -- exit-condition loop
#include <iostream>
int main()
{	
	int n;
	std :: cout << "Enter numbers in the range 1-10 to find ";
	std :: cout << "my favorite number\n";
	
	do
	{
		std :: cin >> n;
	} while (n != 7);
	
	std :: cout << "Yes, 7 is my favorite! The lucky number! \n" ;
	
	return 0;
}