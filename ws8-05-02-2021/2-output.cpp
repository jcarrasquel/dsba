#include <iostream> 
#include <fstream>    
#include <string>

int main ()
{
	// We also can configure the output in the command line using flags for formatting text and numbers...
	// Check a list of flags at: https://doc.bccnsoft.com/docs/cppreference_en/io_flags.html

	int number = 0x3FF;
	std :: cout.setf( std :: ios::dec );

	std :: cout << "Decimal: " << number << std :: endl;

	std :: cout.unsetf( std :: ios::dec );
	std :: cout.setf(std::ios::hex);
	std :: cout.setf(std::ios::showbase);
	std :: cout.setf(std::ios::uppercase);
	std :: cout << "Hexadecimal: " << number << std:: endl;          
}