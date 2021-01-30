#include <iostream>
#include <sstream>

int main ()
{
  std :: stringstream ss;

  int a,b,c;

  ss << "1 2 3"; // the string stream understands spaces for tokenizing.

  ss >> a >> b >> c;

  std :: cout << "ss = " << ss.str() << std :: endl;

  std :: cout << "a = " << a << " "
  			  << "b = " << b << " "
  			  << "c = " << c << std :: endl;

  return 0;
}