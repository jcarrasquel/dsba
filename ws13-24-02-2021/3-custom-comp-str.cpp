#include <iostream>
#include <string>
#include <set>

// strings by default are ordered in "lexicographical order", let's sort them by their "length"!

using StringSetCompare = std::set<std :: string>;

// TODO Modify so that strings are ordered by their length!


int main()
{	
	StringSetCompare s = {"Watermelon","Berry", "Avocado", "Cherry", "Kiwi"}; //TODO Later, add "Blackberry" to the set.

	for(std::string el : s)
		std :: cout << el << ' ';

	std:: cout << '\n';

	return 0;
}
