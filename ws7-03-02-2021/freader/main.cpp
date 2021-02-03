#include <string>
#include <iostream>
#include <cstdlib>
#include "freader.h"

int main(int argc, char *argv[])
{
    short int option = atoi(argv[1]);

    std::string inputFilePath(argv[2]);

    switch(option)
    {
        case 0:     cloneFile(inputFilePath, (std::string) argv[3]);
                    break;

        case 1:     std :: cout << "Word " << argv[3] << " is repeated " << wordOccurrence(inputFilePath, (std::string) argv[3]) << " times in War and Peace!" << std :: endl;
                    break;

        default:    std :: cout << "No option implemented." << std :: endl;
                    break;
    }

    return 0;
}
