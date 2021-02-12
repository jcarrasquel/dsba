#include <iostream>
#include <cstring>
#include <cctype>
#include <vector>

void readVector(std::istream& in, std :: vector<int>& v)
{
	char buffer[255];
	in.get(buffer, 255, '\n');
	for(int i = 0; i < strlen(buffer); ++i)
		if(!isspace(buffer[i]))
			v.push_back(buffer[i]);
}

int findSubstring(const std::vector<int>& v, std::string word)
{
	int i,j;
	bool found = false;
	for(i = 0; i < v.size(); ++i)
	{
		j = 0;
		while(v[i + j] == word[j])
		{
			j++;
			if(j == word.size())
			{
				found = true;
				break;
			}
		}
		if(found) // check only first ocurrence
			break;
	}
	return found ? i : -1;
}

int main(int argc, char *argv[])
{
	// Read and store the vector of ASCII elements
	std :: vector<int> v;
	readVector(std :: cin, v);

	// Read and store a word
	std :: string word;
	std :: cin >> word;

	std :: cout << findSubstring(v, word) << std :: endl;

    return 0;
}