// 2 expressions.cpp
#include <iostream>
int main()
{
	int x;
	
	std :: cout << "The expression x = 100 has the value ";
	std :: cout << (x = 100) << std :: endl;

	std :: cout << "Now x = " << x << std :: endl;
	std :: cout << "The expression x < 3 has the value " << (x < 3) << std :: endl;
	std :: cout << "The expression x > 3 has the value " << (x > 3) << std :: endl;

	// instructs cout to display words true and false instead of 1 and 0.
	std :: cout.setf(std :: ios_base::boolalpha);

	std :: cout << "The expression x < 3 has the value " << (x < 3) << std :: endl;
	std :: cout << "The expression x > 3 has the value " << (x > 3) << std :: endl;

	// The following is not possible!
	// eggs = int toad * 1000;
	// cin >> int toad;
	// int fx = for (i = 0; i< 4; i++)

	return 0;
}