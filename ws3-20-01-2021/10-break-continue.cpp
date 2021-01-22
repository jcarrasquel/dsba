// 10 using continue and break
#include <iostream>

const int LINE_SIZE = 80;

int main()
{
	char line[LINE_SIZE];

	int spaces = 0;
	std :: cout << "Enter a line of text:\n";
	std :: cin.get(line, LINE_SIZE);
	std :: cout << "Complete line:\n" << line << std :: endl;
	std :: cout << "Line through first period:\n";

	for (int i = 0; line[i] != '\0'; i++)
	{
		std :: cout << line[i];		
		if (line[i] == '.')			
			break;
		if (line[i] != ' ')			
			continue;
		spaces++;	
	}
	std :: cout << "\n" << spaces << " spaces\n";
	std :: cout << "Done.\n";
	return 0;
}