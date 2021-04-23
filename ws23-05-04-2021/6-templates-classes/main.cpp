#include <iostream>
#include <vector>
#include <stdexcept>
#include "list.h"

int main()
{
	List<int> l; // our "homemade" container :)!

	l.insert(100); // l[0] = [100]

	try{
		std:: cout << l[-1] << std :: endl;
	}catch(std::exception& e)
	{
		std::cout << e.what() << std :: endl;
	}

	return 0;
}