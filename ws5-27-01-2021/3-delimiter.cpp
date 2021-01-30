#include <iostream>
#include <cctype>

const int BUFF_SIZE = 255;

int main ()
{
  std :: cout << "Insert your string:" << std :: endl;

  char buffer[BUFF_SIZE], delimiter;

  std :: cin.get(buffer, BUFF_SIZE, '\n');

  std :: cout << "Insert the delimiter character:" << std :: endl;

  std :: cin >> delimiter;

  char c;
  int i = 0;
  while (buffer[i] != '\0')
  {
    c = buffer[i] == delimiter ? '\n' : buffer[i];

    std :: cout << c;

    i++;
  }

  std :: cout << std :: endl;

  return 0;
}