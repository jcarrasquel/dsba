// 4 while.cpp introducing the while loop.

#include <iostream>

const int NAME_SIZE = 20;

int main()
{
	char name[NAME_SIZE]; // C-like strings (array of characters)

	std :: cout << "Your first name, please: ";
	std :: cin >> name;

	std :: cout << "Here is your name, verticalized and ASCIIized:\n";
	
	int i = 0;
	while (name[i] != '\0') // process to end of string
	{
		std :: cout << name[i] << ": " << int(name[i]) << std :: endl; // explicit conversion
		i++;
	}
	return 0;
}