// 9 creating and writing a file

#include <iostream>
#include <fstream>
#include <string>

int main() {

	// Create a text string, which is used to output the text file
	std :: string myText;

	// Read from the text file
	std :: ifstream myReadFile("filename.txt");

	// Use a while loop together with the getline() function to read the file line by line
	while (std :: getline (myReadFile, myText))
	{
	  // Output the text from the file
	  std :: cout << myText;
	}

	// Close the file
	myReadFile.close(); 
}