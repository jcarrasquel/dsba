#include <iostream>
#include <string>
#include <map>
#include <random>
#include <algorithm> 
#include <vector>
#include <set>

void fillSet(std::map<int,bool>& myMap, std::set<int>& mySet);
void printSet(std::set<int>& mySet);

void fillMap(std::vector<int>& myVector, std::map<int,bool>& myMap, int r, int q);
void printMap(std::map<int,bool>& myMap);

void fillVector(std::vector<int>& myVector, int n, int r, int q);
void printVector(std::vector<int>& myVector);

/* ====================================
 Task 2
 1) Fill a map from elements of the range [r, q) where the key is r <= n < q and the value tells if n appears in myVector
 2) Pass elements of the map to the set only if their value is true.
*/ 

void fillMap(std::vector<int>& myVector, std::map<int,bool>& myMap, int r, int q)
{
	std :: vector<int> :: iterator it;
	
	bool b;

	for(int n = r; n <= q; n++)
	{
		it = std :: find(myVector.begin(), myVector.end(), n);
		
		b = it != myVector.end(); // true if integer i is in vector myVector. False otherwise.
		
		myMap.insert(std::make_pair(n, b));
	}
}

void fillSet(std::map<int,bool>& myMap, std::set<int>& mySet)
{
	std :: map<int,bool> :: iterator it;

	int n, b;
	for(it = myMap.begin(); it != myMap.end(); ++it)
	{
		n = it->first;
		b = it->second;

		if(b) 
			mySet.insert(n);
	}
}

void deleteSet(std::set<int>& s)
{
	std::set<int>::iterator it;

    for(it = s.begin(); it != s.end();)
    {
        bool remove = *it < 0; // remove if value is odd, e.g. 1, 3, 5...
	
        it = remove ? s.erase(it) : ++it;
    }

    for (it = s.begin(); it != s.end(); ++it)
        std :: cout << *it << ' ';
    std :: cout << '\n';
}

void printSet(std::set<int>& mySet)
{
	std :: set<int> :: iterator it;

	std :: cout << "s: ";
	for(it = mySet.begin(); it != mySet.end(); ++it)
		std :: cout << *it << ' ';
	
	std :: cout << '\n';
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

	std :: cout.setf(std::ios::boolalpha); 

	std :: vector<int> myVector;
	fillVector(myVector, n, r, q);

	printVector(myVector);

	// Put vector elements and how many times they appear on the map.

	std :: map<int, bool> myMap;
	fillMap(myVector, myMap, r, q);

	printMap(myMap);

	std :: set<int> mySet;
	fillSet(myMap, mySet);
	
	printSet(mySet);

	deleteSet(mySet);
}

void printMap(std::map<int,bool>& myMap)
{
	std :: map<int, bool> :: iterator it;

	std :: cout << "map: \n";	

	for (it = myMap.begin(); it != myMap.end(); ++it)
   		std::cout << it->first << " => " << it->second << '\n';

   	// Range-based for is also possible!
   	//for (std:: pair<int,bool> el : myMap)
   	//	std::cout << el.first << " => " << el.second << '\n';

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