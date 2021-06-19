#include "safe_matrix.h"
#include <cstdint>

int main()
{
	std::vector<int> v = {1,2,3}; // <-- std::initializer_list<int>

	SafeMatrix<uint32_t> s1 = { {1,2,3} , {4,5,6} , {7,8,9} };

	s1.print();

	s1.resize(5,4,0);
	
	s1.print();

	s1.resize(2,2);

	s1.print();
}