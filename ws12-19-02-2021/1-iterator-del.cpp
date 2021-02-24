// 1 iterator addition and deletion
#include <vector>
#include <iostream>

int main()
{
    std::vector<int> v = { 1, 2, 3, 4, 5, 6 };
 
    std::vector<int>::iterator it;

    for(it = v.begin(); it != v.end();)
    {
        bool remove = *it % 2 != 0; // remove if value is odd, e.g. 1, 3, 5...

        // erase() returns an iterator to the next element that followed the last element erased
    	
        it = remove ? v.erase(it) : ++it;
    }

    for (it = v.begin(); it != v.end(); ++it)
        std :: cout << *it << ' ';
	
    std :: cout << '\n';
}