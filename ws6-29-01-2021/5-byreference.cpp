// 5 example of passing variables by references

#include <iostream>
void swap(int & a, int & b); // a and b are aliases for integer variables a and b

int main()
{
	int wallet1 = 300;

	int wallet2 = 350;

	std :: cout << "wallet1 = $" << wallet1;
	std :: cout << " wallet2 = $" << wallet2 << std :: endl;
	
	std :: cout << "Using references to swap contents:\n";
	
	swap(wallet1, wallet2);

	std :: cout << "wallet1 = $" << wallet1;
	std :: cout << " wallet2 = $" << wallet2 << std :: endl;

	return 0;
}

// swapping integer variables by references
void swap(int & a, int & b) // int& a = wallet1, int& b = wallet2
{
	int temp;
	temp = a;
	a = b;
	b = temp;
}