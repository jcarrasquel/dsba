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

	// Let's look the persons that Natasha follows!

	MultiMapIterator lowerBound, upperBound;

	lowerBound = friends.lower_bound("Natasha"); 
  	upperBound = friends.upper_bound("Natasha");

  	std :: cout << "lowerBound: " << lowerBound->first << " => " << lowerBound->second << '\n';

  	std :: cout << "upperBound: " << upperBound->first << " => " << upperBound->second << '\n';

}