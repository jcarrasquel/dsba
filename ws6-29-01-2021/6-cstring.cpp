// 6 passing C-style strings as arguments

/* Recall that a C-style string consists of an array of characters terminated by the null character.
   What you’ve learned about designing array-as-parameter functions applies to string functions too! 

   For example, passing a string as an argument means passing an address, and you can use the 
   "const" to protect a string argument from being altered. */

#include <iostream>

// count the number of ocurrences of a char ch in a string str
unsigned int charFrequency(const char* str, char ch);

int main()
{
	char mmm[] = "minimum";
	char wail[] = "ululate";	

	unsigned int ms = charFrequency(mmm, 'm');
	unsigned int us = charFrequency(wail, 'u');

	std :: cout << ms << " m characters in " << mmm << std :: endl;
	std :: cout << us << " u characters in " << wail << std :: endl;

	return 0;
}

// using char* we are passing the first character in the string (similar to arrays)
// with const we are avoiding that the char is modified 

unsigned int charFrequency(const char* str, char ch) 
{
	unsigned int count = 0;

	while (*str) // quit when *str is '\0'
	{
		if (*str == ch)
			count++; 
			//std :: cout << *str << std :: endl;
		
		str++; // move pointer to the next char (recall when moving thru array addresses in previous example!)
	}

	return count;
}