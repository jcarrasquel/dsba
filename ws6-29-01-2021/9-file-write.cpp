// 9 creating and writing a file

#include <iostream>
#include <fstream>
#include <string>

int main() {

  // Create and open a text file
  std :: ofstream myFile("filename.txt");

  // Write to the file
  myFile << "Files can be tricky, but it is fun enough!";

  // Close the file
  myFile.close();

  return 0;
} 