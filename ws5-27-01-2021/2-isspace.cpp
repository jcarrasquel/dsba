/* isspace example */
#include <iostream>
#include <cctype>

const int BUFF_SIZE = 255;

int main ()
{
  std :: cout << "Insert your string:" << std :: endl;

  char buffer[BUFF_SIZE];

  std :: cin.get(buffer, BUFF_SIZE, '\n');

  char c;
  int i = 0;

  while (buffer[i] != '\0')
  {
    c = isspace(buffer[i]) ? '\n' : buffer[i];

    std :: cout << c;

    i++;
  }

  std :: cout << std :: endl;

  return 0;
}