#include <iostream>     
#include <fstream>

int main () {

	// fstream is the base class of ifstream and ofstream.
	std::fstream fs;

	/* The second (optional) parameter to the function open() is the file "mode"
	   The "mode" is a combination of FLAGS:
	   	- fstream::in - the file has been opened in read mode
	   	- fstream::out - the file has been opened in output mode
	   	- fstream::app - all output operations (write) happen at the end of the file append
	   	- see https://www.cplusplus.com/reference/fstream/fstream/open/ to see other modes...
	*/

	// the fs object has an attribute "mode" that consists of BIT1, BIT2, BIT3,.....BIT_EOF (An array of booleans)

	fs.open("war-and-peace.txt", std::fstream::in | std::fstream::out | std::fstream::app);

	fs << "\nNow I will write my comments at the end of the book...";

	fs.close();

	// Let's open again the file only in read only mode...

	fs.open("war-and-peace.txt", std::fstream::in);

	char c;
	while(fs.get(c)) // we also can loop through single characters!
		std :: cout << c;

	// check for the end-of-the-file flag
	if (fs.eof())
		std::cout << "[EoF reached]\n";
	else
		std::cout << "[error reading]\n";

	return 0;
}