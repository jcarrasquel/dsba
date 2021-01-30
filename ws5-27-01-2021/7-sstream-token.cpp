#include <iostream>
#include <sstream>

int main()
{
	std::string input = "Pokrovsky#Boulevard#11#Building#2";

	std::istringstream ss(input);
	
	std::string token;

	int counter = 0;
	while(std::getline(ss, token, '#')) {
	    counter++;
	}

	std :: string myStrings[counter];

	std::istringstream ss2(input);

	// fill the array myStrings with the values from ss2
	int i = 0;
	while(std::getline(ss2, token, '#'))
	{
		myStrings[i] = token;
		std :: cout << myStrings[i] << std :: endl;
		i++;
	}

	return 0;
}