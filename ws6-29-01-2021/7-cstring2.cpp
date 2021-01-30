// 7  a function that returns a pointer to char

#include <iostream>

char* buildstr(char c, int n);

int main()
{
	int times;
	char ch;
	
	std :: cout << "Enter a character: ";
	std :: cin >> ch;
	
	std :: cout << "Enter an integer: ";
	std :: cin >> times;
	
	char *ps = buildstr(ch, times);
	
	std :: cout << ps << std :: endl;
	
	delete [] ps;

	return 0;
}

// builds string made of n c characters
char * buildstr(char c, int n)
{
	char * pstr = new char[n + 1];
	
	pstr[n] = '\0'; // null character at the end of the string
	
	while (n-- > 0)
		pstr[n] = c; // fill n positions of the string with the character c
	
	return pstr;
}