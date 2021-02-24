#include <iostream>
#include <string>
#include <map>
#include <iostream>

using MultiMap = std::multimap<std::string,std::string>;

using MultiMapIterator = MultiMap :: iterator;

int main()
{
	MultiMap friends;

	// adding pairs "who-follows-who"

	friends.insert(std::make_pair("Natasha","Katya"));
	friends.insert(std::make_pair("Natasha","Timofei"));
	friends.insert(std::make_pair("Natasha","Sasha"));

	friends.insert(std::make_pair("Katya", "Natasha"));
	friends.insert(std::make_pair("Katya", "Sasha"));

	friends.insert(std::make_pair("Sasha", "Natasha"));
	
	friends.insert(std::make_pair("Timofei", "Natasha"));

	// Let's look the people that Natasha follows!

	std :: pair<MultiMapIterator, MultiMapIterator> ret = friends.equal_range("Natasha");

	// ret = equal_range(k) returns a range [ret.first, ret.second) of all elements with key k in the multimap

	for(MultiMapIterator it = ret.first; it != ret.second; ++it)
		std :: cout << it->first << " => " << it->second << '\n';

}
