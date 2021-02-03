// 1 very first examples with vector

/* Vectors are sequence containers representing arrays that can change in size. */

/* Vector containers may allocate some extra storage to accommodate for possible growth, 
   and thus the container may have an actual capacity greater than the storage strictly 
   needed to contain its elements */

/* Compared to arrays, vectors consume more memory in exchange for the ability to manage 
   storage and grow dynamically in an efficient way. */

#include <iostream>
#include <vector>

int main()
{
	// See the variants for constructors
	std::vector<int> v1;			// empty vector of ints
	std::vector<int> v2(4,100);     // four ints with value 100
	std::vector<int> v3(v2);        // a copy of v2

	// the iterator constructor can also be used to construct from arrays:
	int values[] = {16,2,77,29};

	std::vector<int> v4 (values, values + sizeof(values) / sizeof(int));

	/* Notes: 
	   - sizeof(values) / sizeof(int) gives you the number of elements in the array
	   - "values" gives you the memory address where the array starts */	

	std::cout << "The contents of v4 are:";
	
	for(int i = 0; i < v4.size(); i++)
		std :: cout << v4[i] << ' ';

	std::cout << '\n';
	
	return 0;
}


