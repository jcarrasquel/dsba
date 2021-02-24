#include <iostream>
#include <set>
#include <functional> // std::less

// set<int, less<int>> is the same as set<int>

// when defining only set<int>, it is taken the default comparator of ints.

using IntSetLess = std::set<int, std::less<int>>;  // TODO Change to std::greater

int main()
{
	IntSetLess s = {2, 6, 4, 2, -1, 3, -4};

	for(int el : s)
		std :: cout << el << ' ';

	std:: cout << '\n';

	return 0;
}