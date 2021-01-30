#include <iostream>
#include <sstream>

int main ()
{
  std :: cout << "Enter an integer value:";

  int n;

  std :: cin >> n;

  // read/write operations over ss like if it were a input/output channel (for example a file)!
  std :: stringstream ss;

  ss << n; // the integer n is being written in the string stream object ss

  std :: string s;

  ss >> s; // the string stream objects passes its current content to string s

  std :: cout << "the integer number is: " << n << std :: endl;
  std :: cout << "the integer as string is: " << s << std :: endl;

  return 0;
}