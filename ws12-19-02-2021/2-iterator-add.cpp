// 1 iterator addition in a for
#include <vector>
#include <iostream>

int main()
{
    std::vector<int> v = { 1, 2, 3, 4, 5, 6 };

    std::vector<int>::iterator it = v.begin();

    for(it = v.begin(); it != v.end();)
    {
        bool add = *it % 2 != 0; // add new value to the right if its odd
 
        it = add ? v.insert(it, 0) : ++it;
    }

    for (it = v.begin(); it != v.end(); ++it)
        std :: cout << *it << ' ';
	
    std :: cout << '\n';
}