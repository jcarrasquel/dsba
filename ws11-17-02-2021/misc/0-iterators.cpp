#include <vector>
#include <iterator>
#include <iostream>

int main()
{
	std :: vector<int> v;

	for(int i = 0; i < 5; i++)
		v.push_back(i);

	// common iterators
	std :: vector<int> :: iterator it;
	
	for(it = v.begin(); it != v.end(); ++it)
		*it += 1;

	// const iterator
	std :: vector<int> :: const_iterator c;

	for(c = v.cbegin(); c != v.cend(); ++c)
	{
		//*c += 1; // not allowed		
		std :: cout << *c << ' ';
	}

	std :: cout << '\n';

	// reverse iterator

	std :: vector<int> :: reverse_iterator r;

	for(r = v.rbegin(); r != v.rend(); ++r)
		std :: cout << *r << ' ';

	std :: cout << '\n';
}