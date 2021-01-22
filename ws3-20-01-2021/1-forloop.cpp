// 1 forloop.cpp -- introducing the for loop
#include <iostream>
int main()
{
	int i;

	for (i = 0; i < 5; i++)
		std :: cout << "C++ knows loops.\n"; // one statement - no need for open/close brackets

	std :: cout << "C++ knows when to stop.\n";
	
	std :: cout << "Let us go backwards...\n";

	/* 	 Two things to note below:
		(1) The loop quits when "i" is 0... why? 
		(2) Pay also attention to internal declaration of "int i" in the for statement. */
	
	for (int i = 5; i; i--)
		std:: cout << "i = " << i << "\n";

	std :: cout << "Done now that i = " << i << "\n"; 

	return 0;
}