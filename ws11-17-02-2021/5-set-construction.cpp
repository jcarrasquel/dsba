// 5 constructing sets
#include <set>

int main()
{
	std :: set<int> s1;

	int values[] = {10,20,30,40,50};
 	
 	// constructor from array
 	std::set<int> s2(values, values + 5);

 	// copy constructor
  	std::set<int> s3(s2);

 	// constructor using iterators
  	std::set<int> s4 (s2.begin(), s2.end());

  	return 0;
}