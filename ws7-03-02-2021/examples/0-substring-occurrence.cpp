// 0 searching for occurrences of a substring in a string using the function "find"

#include <iostream>
#include <string>

// How many times a sub-string "myWord" occurs in a string line
int substringOccurrences(const std::string line, const std::string myWord)
{
    int occurrences = 0, position = line.find(myWord, 0);

    while( position != std::string::npos)
    {
        occurrences++;
        std :: cout << "Occurrence #" << occurrences << " at char " << position << std :: endl;
        position = line.find(myWord, position + myWord.size());
    }

    return occurrences;
}

int main()
{
	std :: string line = "He knew very well that this was Napoleon, but Napoleon’s presence could";

	std :: string myWord = "Napoleon";

	std :: cout << "Occurrences: " << substringOccurrences(line, myWord) << std :: endl;
	
	return 0;
}