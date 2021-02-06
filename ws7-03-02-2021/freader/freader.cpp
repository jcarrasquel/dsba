/* Implementation of a library for reading and analyzing plain text files */
#include <string>
#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>

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

// How many times a sub-string "myWord" occurs in a file
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

// To obtain all the different words in the file
void distinctWords(const std :: string inputFilePath, const std :: string outputFilePath)
{
    std :: ifstream inputFile(inputFilePath);

    std :: ofstream outputFile(outputFilePath);

    std :: string line;

    std :: vector<std :: string> v;

    // Read line-by-line
    while(std :: getline(inputFile, line))
    {
        // Read the words in the line variable
        std :: istringstream ss(line);
        std :: string token;
        while(std::getline(ss, token, ' ')) // token has the next word to read
        {
            bool found = false;
            std::vector<std::string>::iterator it;
            for(it = v.begin(); it != v.end(); ++it)
            {
                if(*it == token)
                {
                    found = true;
                    break;
                }
            }
            if(!found)
            {
                v.push_back(token);
            }
        }
    }

    std::vector<std::string>::iterator it;
    for(it = v.begin(); it != v.end(); ++it)
    {
        outputFile << *it << std :: endl;
    }

    inputFile.close();
    outputFile.close();
}