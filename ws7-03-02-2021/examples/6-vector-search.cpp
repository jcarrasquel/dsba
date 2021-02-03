// 6 yet another example of vectors - a function that adds an element to a vector if the element does not exist

#include <iostream> 
#include <iterator>
#include <vector>
#include <string>

// addElement to the vector only if the vector does not exist
// return true if the element was added, false otherwise.

bool addElement(std :: vector<std :: string>& myVector, std :: string element) 
{ 
    bool elementExists = false;

    std :: vector<std :: string> :: iterator it; 
    for (it = myVector.begin(); it < myVector.end(); ++it)
    {
        if(*it == element)
        {
            elementExists = true;
            break; // the element to add already in the array, so we do not add it.
        }
    }

    if(!elementExists)
        myVector.push_back(element);

    return elementExists;
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