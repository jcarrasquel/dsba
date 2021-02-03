// 5 passing vectors by reference

#include <iostream> 
#include <iterator>
#include <vector>
#include <string>

/* To avoid to pass by copy (which may be inefficient),
   we pass by reference using the operator &.
   Yet, if we want not the object to be modified, we use the keyword const */

void addElement(std :: vector<std :: string>& myVector, std :: string element) 
{ 
	myVector.push_back(element); // error here if we write "const"
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