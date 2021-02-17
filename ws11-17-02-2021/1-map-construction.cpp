// 1 constructing maps

#include <iostream>
#include <map>

int main ()
{
  // basic declaration
  std::map<char,int> myMap;

  myMap['a'] = 10;
  myMap['b'] = 20;
  myMap['c'] = 30;
  myMap['d'] = 40;

  myMap['a'] = 99;

  // copy by ranges using iterators
  std::map<char,int> mySecondMap (myMap.begin(), myMap.end());

  // copy constructor
  std::map<char,int> myThirdMap (mySecondMap);

  // moving thru a map
  std::map<char,int>::iterator it;

  for (it = myMap.begin(); it != myMap.end(); ++it)
    std::cout << it->first << " => " << it->second << '\n';

  // note: it->x is the same as (*it).x

  return 0;
}