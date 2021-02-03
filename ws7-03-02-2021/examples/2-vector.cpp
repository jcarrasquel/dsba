// 2 adding elements using push back, comparing size and capacity
#include <iostream>
#include <vector>

int main ()
{
	std::vector<int> v;

	for (int i = 0; i < 100; i++)
		v.push_back(i);

	std::cout << "size: " << (int) v.size() << '\n';
	std::cout << "capacity: " << (int) v.capacity() << '\n';

	for (int i = 0; i < 100; i++)
		v.push_back(i);

	std::cout << "new size: " << (int) v.size() << '\n';
	std::cout << "new capacity: " << (int) v.capacity() << '\n';

	return 0;
}