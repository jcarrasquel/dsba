/* Header file of a library of reading and analyzing plain text files */
#ifndef FREADER_H
#define FREADER_H

/* 0 Copy and paste the content of file stored in "inputFilePath" into a new file at "cloneFilePath" */

void cloneFile(const std :: string inputFilePath, const std :: string cloneFilePath);

/* 1 Prints the number of occurrences of "myWord" in the file stored at "inputFilePath" */

int wordOccurrence(const std :: string inputFilePath, const std :: string myWord);

#endif
