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

void reverse(std::vector<int>& v, int li, std::string word)
{
	int n = word.size() - 1;
	for(int i = 0; i < word.size(); ++i)
		v[i + li] = word[n - i];
}

// Modification of the task 1. Upon susbtring matching, reverse
void findAndReverse(std::vector<int>& v, std::string word)
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
				reverse(v, i, word);
				break;
			}
		}
		if(found) // check only first ocurrence
			break;
	}
}

int main(int argc, char *argv[])
{
	// Read and store the vector of ASCII elements
	std :: vector<int> v;
	readVector(std :: cin, v);

	// Read and store a word
	std :: string word;
	std :: cin >> word;

	findAndReverse(v, word);
	std :: vector<int> :: iterator it;
	for(it = v.begin(); it != v.end(); ++it)
		std :: cout << (char) *it;
	std :: cout << '\n';

    return 0;
}