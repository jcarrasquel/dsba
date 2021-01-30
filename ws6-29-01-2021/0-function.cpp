// 0 ourfunc.cpp -- defining your own function

/* Suppose you want to add a user-defined function. Just as with a library function,
you can call a user-defined function by using its name. And, as with a library function, you
must provide a function prototype before using the function, which you typically do by
placing the prototype above the main() definition. You must provide source code for 
the function.The simplest way is to place the code in the same file after the code for main() */

#include <iostream>

// function prototype for simon()
void simon(int);

int main()
{
	simon(3);
	
	std :: cout << "Pick an integer: ";
	
	int count;
	std :: cin >> count; // 2
	
	simon(count);

	std :: cout << count << std :: endl;
	
	std :: cout << "Done!" << std :: endl;
	return 0;
}

// define the simon() function
void simon(int n)
{
	std :: cout << "Simon says touch your toes " << n << " times!" << std :: endl;
	n = 3;
}