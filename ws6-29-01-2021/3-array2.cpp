// 3 another example with array arguments and showing the organization of an array in memory (arr + i)

#include <iostream>
const int ARRAY_SIZE = 8;

int sumArray(int arr[], int n);

void visitArray(int arr[], int n);

int main()
{
	// each position marks the number of cookies a person eats!
	int cookies[ARRAY_SIZE] = {1, 2, 4, 8, 16, 32, 64, 128};

	//int sum = sumArray(cookies, ARRAY_SIZE);

	std :: cout << cookies << " = array address, ";

	std :: cout << sizeof(cookies) << " = sizeof cookies\n";

	int sum = sumArray(cookies, ARRAY_SIZE);

	std :: cout << "Total cookies eaten: " << sum << std :: endl;

	sum = sumArray(cookies + 4, 4);

	std::cout << "Last four cookie eaters ate " << sum << " cookies.\n";

	// TODO Use function visitArray to show the organization in memory of the array
	visitArray(cookies, ARRAY_SIZE);

	std :: cout << std :: endl;
	return 0;
}

int sumArray(int arr[], int n)
{
	std :: cout << arr << " = arr, "; // Pay attention that this memory address is the address of cookies
	
	int total = 0;
	for (int i = 0; i < n; i++)
		total = total + arr[i];

	return total;
}

void visitArray(int arr[], int n)
{
	std :: cout << std :: endl;
	for (int i = 0; i < n; i++)
		std :: cout << "memory address: " << arr + i << " value: " << arr[i] << std :: endl;
}