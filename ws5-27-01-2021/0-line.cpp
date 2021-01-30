#include <iostream>
#include <string>

int main()
{   
    std :: cout << "Input first and last name: ";

    char buf[255];                      

    //std :: cin >> buf; // FIXME Only one word is assigned here. How to solve?

    std :: cin.get(buf, 255, '\n');

    std :: cout << buf << std :: endl;

    return 0;
}