// 3 introducing iterators

/* Iterators are used to point at the memory addreses of STL containers */
#include <iostream> 
#include <iterator>
#include <vector>

int main()
{
	int values[] = {16,2,77,29};
	std::vector<int> v (values, values + sizeof(values) / sizeof(int));
      
    // Declaring iterator to a vector.
    std :: vector<int> :: iterator it; 

    // You could think of iterator "it" as a variable that allows to "reference" elements of integer vectors

    // Displaying vector elements using begin() and end() 
    std :: cout << "The vector elements are : "; 
    
    for (it = v.begin(); it < v.end(); ++it) 
    	std :: cout << *it << " "; 
    
    std :: cout << std :: endl;

	std :: cout << "begin: " << *(v.begin()) << std :: endl; 
	std :: cout << "end: " << *(v.end()) << std :: endl; 

    return 0; 

}