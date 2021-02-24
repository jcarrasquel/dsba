#include <iostream>
#include <set>

bool myCompare(int x, int y) // TODO Change so that positive numbers go first!
{
	return x < y; // true if x is "less" than y, false otherwise.
}

using IntSetCompare = std::set<int, decltype(myCompare)*>;

int main()
{
	IntSetCompare s({3, -2, 1, -4, 8, 7, -15}, myCompare);

	for(int el : s)
		std :: cout << el << ' ';

	std:: cout << '\n';

	return 0;
}