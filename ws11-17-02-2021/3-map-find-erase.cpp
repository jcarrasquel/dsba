// 3 erasing and finding elements in a map
#include <iostream>
#include <map>

void printMap(std :: map <char, int>& myMap)
{
  std::map<char,int>::iterator it;
  for (it = myMap.begin(); it != myMap.end(); ++it)
    std::cout << it->first << " => " << it->second << '\n';
}

int main ()
{
  std::map<char,int> myMap;

  // insert some values:
  myMap['a'] = 10;
  myMap['b'] = 20;
  myMap['c'] = 30;
  myMap['d'] = 40;
  myMap['e'] = 50;
  myMap['f'] = 60;

  // Erase by iterator
  // Function find () returns an iterator to the element, if an element with the specified key is found, or map::end otherwise.
  
  std::map<char,int>::iterator it;
  it = myMap.find('b');

  if(it != myMap.end())
    std :: cout << "Element " << it->first << " exists, now let's erase it!\n";
    myMap.erase(it);                  

  printMap(myMap);

  // Erase by key
  std :: cout << "\nLet's now erase by key!\n";

  myMap.erase('c');

  printMap(myMap);

  return 0;
}