// 4 firstref.cpp -- defining and using a reference
#include <iostream>

int main()
{
	int cats = 101;

	int& felines = cats; // felines is a reference to an int variable

	std :: cout << "cats = " << cats;
	std :: cout << " felines = " << felines << std :: endl;

	felines++;

	std :: cout << "cats = " << cats;
	std :: cout << " felines = " << felines << std :: endl;

	std :: cout << "cats address = " << &cats;
	std :: cout << ", felines address = " << &felines << std :: endl;

	return 0;
}