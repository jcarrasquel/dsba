// 2 map insertion of elements using pairs

#include <iostream>
#include <string>
#include <map>

int main ()
{
  std::map<std::string, double> salaryMap;

  // the key-value ("Johnson", 1800) is created as a pair for insertion in the map
  
  salaryMap.insert( std::make_pair("Johnson", 1800) );
 
  // the insert function returns a pair ret = (it,b) where
  // - "it": iterator to the new element inserted (or the existing element with that key in the map)
  // - "b" : boolean value. True, if an element with the same key was inserted. False, if it exists.

  std::pair< std::map<std::string, double> :: iterator , bool > ret;
  
  ret = salaryMap.insert( std::make_pair("Johnson", 1500) ); // TODO try changing key and value!

  std::map<std::string, double>::iterator it = ret.first;
  bool inserted = ret.second;

  if (inserted)
     std::cout << "Employee " << it->first << " just inserted with value " << it->second << '\n';
  else
    std::cout << "Employee " << it->first << " already exists with with value " << it->second << '\n';

  std :: cout << "\nelements in map = " << salaryMap.size() << std :: endl;

  // note: it->x is the same as (*it).x

  return 0;
}