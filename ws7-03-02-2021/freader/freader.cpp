/* Implementation of a library for reading and analyzing plain text files */
#include <string>
#include <iostream>
#include <fstream>

void cloneFile(const std :: string inputFilePath, const std :: string cloneFilePath)
{
     std :: cout << "Opening file: " + inputFilePath << std :: endl;

     std :: ifstream inputFile(inputFilePath);

     std :: ofstream cloneFile(cloneFilePath);

     std :: string line;

     unsigned int c = 0;

     while (std :: getline(inputFile,line))
     {
        // Output the text from the file
        cloneFile << line << std :: endl;
        c++;
     }

     std :: cout << c << " lines were cloned to file " + cloneFilePath << std :: endl;

     // Close files
     inputFile.close();
     cloneFile.close();
}

// How many times a sub-string "myWord" occurs in a string line
int substringOccurrences(const std::string line, const std::string myWord)
{
    int occurrences = 0, position = line.find(myWord, 0);

    while( position != std::string::npos)
    {
        occurrences++;
        position = line.find(myWord, position + myWord.size());
    }

    return occurrences;
}

int wordOccurrence(const std :: string inputFilePath, const std :: string myWord)
{
    std :: cout << "Opening file: " + inputFilePath << std :: endl;
    std :: cout << "Searching for word: " + myWord << std :: endl;

    std :: ifstream inputFile(inputFilePath);

    std :: string line;

    unsigned int accum = 0;

    int i =0;

    while (std :: getline(inputFile,line))
        accum += substringOccurrences(line, myWord);

    inputFile.close();

    return accum;
}
