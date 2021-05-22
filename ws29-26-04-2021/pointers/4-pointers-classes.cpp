#include <iostream>
#include <vector>

class MyInt
{
	public:
		MyInt(int x)
		{
			_x = new int(x);
			std :: cout << "MyInt():" << *_x << std :: endl;
		}
		~MyInt()
		{
			std :: cout << "~MyInt(): " << *_x << std :: endl;
			delete _x;
		}
	private:
		int* _x;
};

class IntCollection
{
	public:
		IntCollection(std::vector<int> v) // also we could add number-by-number
		{
			for(int i = 0; i < v.size(); i++)
				_v.push_back(new MyInt(v[i]));
		}
		~IntCollection()
		{
			std :: cout << "~IntCollection()" << std :: endl;
			for(int i = 0; i < _v.size(); i++)
				delete _v[i];
		}

	private:
		std::vector<MyInt*> _v;
};

int main()
{
	IntCollection* c1 = new IntCollection({1,2,3,4});

	delete c1;

	return 0; // check with non-dynamic class
}