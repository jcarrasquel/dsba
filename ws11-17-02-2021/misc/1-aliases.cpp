// example on the use of aliases

#include <set>
#include <vector>
#include <map>
#include <iostream>
#include <string>

using IntVector = std::vector<int>;
using Int2StringMap = std::map<int, std::string>;
using IntSet = std::set<int>;

using std::cin;
using std::cout;

int main()
{
	IntVector v;
	
	IntSet s;

	Int2StringMap m;

	int values[] = {20,10,70,50,40};
	std :: string fruits[] = {"pear", "mango", "apple", "melon", "kiwi"};

	for(int i = 0; i < 5; i++)
	{
		v.push_back(values[i]);
		
		s.insert(values[i]); // works similar to the insert of a map

		m[values[i]] = fruits[i];
	}

	// Let's print the containers!
	
	IntVector :: iterator itv;
	IntSet :: iterator its;
	Int2StringMap :: iterator itm;

	cout << "vector = ";
	for(itv = v.begin(); itv != v.end(); ++itv)
		cout << *itv << ' ';
	cout << '\n';

	cout << "set = ";
	for(its = s.begin(); its != s.end(); ++its)
		cout << *its << ' ';
	cout << '\n';

	cout << "map = ";
	for(itm = m.begin(); itm != m.end(); ++itm)
		cout << "(" << itm->first << "," << itm->second << ")" << ' ';
	cout << '\n';
}
