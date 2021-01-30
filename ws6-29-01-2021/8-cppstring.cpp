// 8 handling an array of string objects
#include <iostream>
#include <string>

const int SIZE = 3;

void display(const std :: string sa[], int n);

int main()
{
	std :: string list[SIZE]; 	// an array holding 3 string objects

	std :: cout << "Enter your " << SIZE << " favorite dishes:\n";

	for (int i = 0; i < SIZE; i++)
	{
		std :: cout << i + 1 << ": ";
		std :: getline(std :: cin, list[i]);
	}

	std :: cout << "Your list:\n";
	display(list, SIZE);

	return 0;
}

void display(const std :: string sa[], int n)
{
	for (int i = 0; i < n; i++)
		std :: cout << i + 1 << ": " << sa[i] << std :: endl;
}