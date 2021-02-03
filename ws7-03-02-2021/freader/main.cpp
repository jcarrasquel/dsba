#include <string>
#include <iostream>
#include <cstdlib>
#include "freader.h"

int main(int argc, char *argv[])
{
    // Read arguments by console

    // First argument will be the option (function number)
    short int option = atoi(argv[1]);

    // The second argument will be the input file address
    std::string inputFilePath(argv[2]);

    // Write here a pretty "switch" statement to execute the function indicate by the number "option"...

    return 0;
}
