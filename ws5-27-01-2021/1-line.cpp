#include <iostream>
#include <string>

int main()
{   
    std :: cout << "Input first and last name: ";

    std :: string firstName;
    std :: string lastName;

    std :: cin >> firstName >> lastName;

    std :: string fullName(lastName + "," + firstName);

    std :: cout << "Format #1: " << firstName + " " + lastName << std :: endl;
    std :: cout << "Format #2: " << fullName << std :: endl;

    return 0;
}