#include <iostream>     
#include <fstream>
#include <sstream>
#include <string>

// Generic function to print in file or terminal according to the stream argument
void print(std::ostream& os, std::string myWord)
{
	os << myWord;
}

int main ()
{
	// printing in the command line
	print(std::cout, "Hello World!\n");

	// printing in a file
	std::fstream fs;
	fs.open("war-and-peace.txt", std::fstream::out | std::fstream::app);
	print(fs,"\nNow I will write my comments at the end of the book...");
	fs.close();

	// printing in a string stream object
	std::stringstream s;
	print(s, "And this is my string stream object!\n");
	print(std::cout, s.str());
}