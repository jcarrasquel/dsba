// 4 passing vectors by copy

#include <iostream> 
#include <iterator>
#include <vector>
#include <string>

void addElement(std :: vector<std :: string> myVector, std :: string element) 
{ 
	myVector.push_back(element); 
}
   
int main() 
{ 
	std :: vector<std::string> v; 
	v.push_back("Petersburg"); 
	v.push_back("live");
	v.push_back("Bonaparte");

	addElement(v, "travel"); 
   
    /* check the vector v state after calling the function*/
    std :: vector<std :: string> :: iterator it; 
    for (it = v.begin(); it < v.end(); ++it) 
    	std :: cout << *it << "\n"; 
   
    return 0; 
}