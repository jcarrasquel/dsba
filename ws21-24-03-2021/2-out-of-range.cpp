#include <iostream>       // std::cerr
#include <stdexcept>      // std::out_of_range
#include <vector>         // std::vector


int main () {

	std::vector<int> v(10);

	try
	{
		v.at(20) = 100;      // vector::at throws an out-of-range
	}
	catch (const std::out_of_range& oor)
	{
		std::cerr << "Out of Range error: " << oor.what() << '\n';
	}
	return 0;

}