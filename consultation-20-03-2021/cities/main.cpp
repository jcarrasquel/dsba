#include <iostream>
#include <string>

int main ()
{
  std::string str="We generalities, but we live in details.";
                                      
  // find() returns the position of the first occurrence of "think"  
  int pos = str.find("think");

  std::cout << pos << '\n';

  return 0;
}