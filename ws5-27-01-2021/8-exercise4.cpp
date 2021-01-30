#include <iostream>
#include <sstream>

const int BUFF_SIZE = 255;

int main()
{
	char buffer[BUFF_SIZE], delimiter;
	int counter = 0; // number of words in the input string separated by the delimiter.

	std :: cout << "Insert your string:" << std :: endl;
  	std :: cin.get(buffer, BUFF_SIZE, '\n');

  	std :: cout << "Insert the delimiter character:";
  	std :: cin >> delimiter;

	std::istringstream ss1(buffer);
	std::string token;

	while(std::getline(ss1, token, delimiter))
		counter++;
	
	std :: string myStrings[counter];

	int i = 0;

	std::istringstream ss2(buffer);

	while(std::getline(ss2, token, delimiter)) {
		myStrings[i] = token;
		std :: cout << myStrings[i] << std :: endl;
		i++;
	}

	return 0;
}