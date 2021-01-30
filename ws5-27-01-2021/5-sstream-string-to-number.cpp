#include <iostream>
#include <sstream>

int main ()
{
  std :: string numberAsString = "9999";

  std :: stringstream ss; // read/write operations over ss like if it were a input/output channel (for example a file)!

  ss << numberAsString;

  int number;

  ss >> number;

  std :: cout << numberAsString + ".9" << std :: endl;
  std :: cout << number + 1 << std :: endl;

  // Note: you also may print the content of a string stream using ss.str()

  return 0;
}