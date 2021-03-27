// length_error example

#include <iostream>       // std::cerr
#include <stdexcept>      // std::length_error
#include <vector>         // std::vector

int main ()
{
	try
	{
		// vector throws a length_error if resized above max_size
		
		std::vector<int> v;
		
		v.resize( v.max_size() + 1 );
	
	}
	catch (const std::length_error& le)
	{
	  
	  std::cerr << "Length error: " << le.what() << '\n';
	
	}

	return 0;
}