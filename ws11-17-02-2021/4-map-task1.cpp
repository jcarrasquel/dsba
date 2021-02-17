#include <iostream>
#include <string>
#include <map>
#include <random>
#include <vector>

void fillVector(std::vector<int>& myVector, int n, int r, int q);
void printVector(std::vector<int>& myVector);
void printReverseVector(std::vector<int>& myVector);

void fillMap(std::vector<int>& myVector, std::map<int,int>& myMap);
void printMap(std::map<int,int>& myMap);

/* ====================================
 Task 1
 Fill and print a map<int,int> of key-value pairs such that:
 key: a distinct number in the vector
 value: the number of occurrences
*/ 

void fillMap(std::vector<int>& myVector, std::map<int,int>& myMap)
{
	// Code your solution here...
}

void printMap(std::map<int,int>& myMap)
{
	// Code your solution here....
}
// ====================================

int main()
{
	int n, r, q;

	std :: cout << "n: ";
	std :: cin >> n;

	std :: cout << "r: ";
	std :: cin >> r;

	std :: cout << "q: ";
	std :: cin >> q;

	std :: vector<int> myVector;
	fillVector(myVector, n, r, q);

	printVector(myVector);

	// TODO Put vector elements and how many times they appear on the map.

	// Create a map, and call fill and print.

	std :: map<int, int> myMap;

	fillMap(myVector, myMap);
	printMap(myMap);
}

void fillVector(std::vector<int>& myVector, int n, int r, int q)
{
	std :: default_random_engine generator;

	// generating random numbers in the range [r, q)
	std :: uniform_int_distribution<int> uniform(r , q - 1);

	for(int i = 0; i < n; i++)
	{
		int newNumber = uniform(generator);
		myVector.push_back(newNumber);
	}
}

void printVector(std::vector<int>& myVector)
{
	std :: vector<int> :: iterator it;
	
	std :: cout << "v: ";

	for(it = myVector.begin(); it != myVector.end(); ++it)
		std :: cout << *it << ' ';
	
	std :: cout << '\n';
}

void printReverseVector(std::vector<int>& myVector)
{
	std :: vector<int> :: reverse_iterator rit = myVector.rbegin();

	std :: cout << "reverse v: ";

	for(rit = myVector.rbegin(); rit != myVector.rend(); ++rit)
		std :: cout << *rit << ' ';
	std :: cout << '\n';
}