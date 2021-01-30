// 1 nchars.cpp -- example of passing by value. Look that the value of "times" do not change.

#include <iostream>

void nchars(char, int);

int main()
{
	int times;
	char ch;
	std :: cout << "Enter a character: ";
	std :: cin >> ch;
	
	while (ch != 'q')
	{
		std :: cout << "Enter an integer: ";
		std :: cin >> times;
		
		nchars(ch, times); // function with two arguments
		
		std :: cout << "\nEnter another character or press the q-key to quit: ";
		std :: cin >> ch;
	}

	std :: cout << "The value of times is " << times << ".\n";
	std :: cout << "Bye\n";
	return 0;
}

void nchars(char c, int n) // displays c n times
{
	while (n-- > 0)
		std :: cout << c;
}