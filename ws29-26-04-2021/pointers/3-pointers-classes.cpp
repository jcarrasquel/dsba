#include <iostream>
#include <vector>

class MyInt
{
	public:
		MyInt()
		{
			_x = nullptr;
		}
		MyInt(int x)
		{
			_x = new int(x); // we allocate a 4-bytes space of memory for _x
		}
		void free()
		{
			delete _x;
		}

		~MyInt()
		{
			std :: cout << "calling destructor!" << std :: endl;
			delete _x;
		}
	private:
		int* _x;
};

int main()
{

	MyInt* myInt = new MyInt(42); // nested

	// we do whatever we want myInt....

	delete myInt;

	// C-style array
	MyInt* ints = new MyInt[5];
	delete[] ints;

	return 0;
}