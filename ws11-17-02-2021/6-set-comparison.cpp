// 6 comparison between sets, vectors, and maps
#include <set>
#include <vector>
#include <map>
#include <iostream>

int main()
{
	std :: vector<int> v;
	std :: set<int> s;
	std :: map<int, std::string> m;

	int values[] = {20,10,70,50,40}; // TODO repeat some value to see effects
	std :: string fruits[] = {"pear", "mango", "apple", "melon", "kiwi"};

	for(int i = 0; i < 5; i++)
	{
		v.push_back(values[i]);
		
		s.insert(values[i]); // works similar to the insert of a map

		m[values[i]] = fruits[i];
	}

	// Let's print the containers!
	
	std :: vector<int> :: iterator itv;
	std :: set<int> :: iterator its;
	std :: map<int, std::string> :: iterator itm;

	std :: cout << "vector = ";
	for(itv = v.begin(); itv != v.end(); ++itv)
		std :: cout << *itv << ' ';
	std :: cout << '\n';

	std :: cout << "set = ";
	for(its = s.begin(); its != s.end(); ++its)
		std :: cout << *its << ' ';
	std :: cout << '\n';

	std :: cout << "map = ";
	for(itm = m.begin(); itm != m.end(); ++itm)
		std :: cout << "(" << itm->first << "," << itm->second << ")" << ' ';
	std :: cout << '\n';
}
