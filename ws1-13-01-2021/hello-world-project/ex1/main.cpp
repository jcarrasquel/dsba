// include some definitions needed for woring with standard input/output (streams)
#include <iostream>
#include <climits>
#include<string>

// the entrypoint of the application
int main()
{
    // put a string literal "Hello world!" to the standard output stream in order 
    // to print it at the console, which is normally associated with this stream
    std::cout << "Hello world!\n";


    size_t s1 = sizeof(char);
    size_t s2 = sizeof(short);
    size_t s3 = sizeof(int);
    size_t s4 = sizeof(long);

    std::cout << "char: " << s1 << " byte" << std::endl;
    std::cout << "short: " << s2 << " bytes" << std::endl;
    std::cout << "int: " << s3 << " bytes" << std::endl;
    std::cout << "long: " << s4 << " bytes" << std::endl;

    // must return a "errorlevel code": 0 is for OK
    return 0;
}
