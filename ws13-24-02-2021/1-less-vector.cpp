#include <iostream>
#include <vector>
#include <functional> // std::less
#include <algorithm>

// std::less also can be used for other functions

using IntVector = std::vector<int>;

int main()
{
	IntVector v = {-2, 4, -7, 2, 3}; // in vector, elements stay like you put them

	std :: sort(v.begin(), v.end(), std::less<int>());

	for(int el : v)
		std :: cout << el << ' ';

	std:: cout << '\n';

	return 0;
}