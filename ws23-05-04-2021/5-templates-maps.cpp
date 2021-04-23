#include <iostream>
#include <string>
#include <map>

template<typename K, typename C>
std::ostream& operator<<(std::ostream& os, std::map<K, C> m)
{
	typename std::map<K,C>::iterator it;
	
	for(it = m.begin(); it != m.end(); ++it)
		std::cout << "(" << it->first << "," << it->second << ")" << "\t";

	return os;
}

int main()
{
	std::map<std::string, double> m = { {"latte", 100}, {"espresso", 70}, {"americano", 80}};

	std::cout << m << std :: endl;

	return 0;
}