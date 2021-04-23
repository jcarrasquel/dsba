#include <iostream>
#include <string>
#include <vector>
#include <cstdint> 
#include <cstdlib>

enum Task{PRINT_SIZE = 8, PRINT_ELEMENTS = 4, INSERT_ELEMENT = 2, FIND_ELEMENT = 1};


/*** Code your function here!... ***/

//templ...
//void executeTasks(...vector... v, uint16_t mode, ...element)


void test1()
{	
	uint16_t mode = 0x2048;

	std::vector<int> v1 = {100, 200, 300, 400, 500, 600, 700, 800};

	//executeTasks<int>(v1, mode, 999);

	std::cout << std::endl;
}

void test2()
{
	uint16_t mode = 0x0014;

	std::vector<std::string> v2 = {"Avocado", "Lemon", "Pepper", "Onion", "Lettuce"};

	//executeTasks<std::string>(v2, mode, "Onion");
}


int main()
{
	test1();

	test2();

	return 0;

}