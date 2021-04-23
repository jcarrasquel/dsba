#include <iostream>

// to discuss...

// case 1
enum nums{one = 1, two = 2, four = 4, eight = 8};

// case 2
enum numx{first, second = 100, third, fourth = 200, fifth};

// case 3
enum voltage{low = 0, null = 0, high = 1};

int main()
{
	numx n;

	n = fifth;

	std :: cout << n << std :: endl;

	return 0;
}