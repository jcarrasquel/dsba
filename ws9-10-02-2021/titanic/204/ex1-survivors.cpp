#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <fstream>
#include <stdlib.h>

/* Implement a function called survivors, that takes an input stream by reference and an empty vector by reference,
   The function should include in vector v the surnames of each survivor from the file "titanic.csv"
   For checking if the user survived check  */
void survivors(std::ifstream& inputFile, std::vector<std :: string>& passengerNames)
{
    std :: string line;
    int counter = 0;
    char a;
    std :: string token;
    while (std :: getline(inputFile,line)) {
        std :: cout<<line<<'\n';
        std::istringstream ss2(line);
        int i = 0;
        std::string survivor;
        while (std::getline(ss2, token, ',')) {
            if (i == 1) {
                survivor = token;
            }
            if (i == 3 and survivor == "1") {
                passengerNames.push_back(token);
            }
            i++;
        }
    }
}
int main(int argc, char *argv[])
{
    std::ifstream inputFile;
    inputFile.open("titanic.csv");
    std::vector<std :: string> passengerNames;
    survivors(inputFile, passengerNames);
    inputFile.close();
    std :: vector<std :: string> :: iterator it;
    for (it = passengerNames.begin(); it != passengerNames.end(); ++it)
        std :: cout << *it << "\n";

    return 0;
}