// sort algorithm example
// see http://www.cplusplus.com/reference/algorithm/

#include <iostream>
#include <algorithm>   
#include <vector>
#include <iterator>

int main ()
{
    int values[] = {32,71,12,45,26,80,53,33};

    std::vector<int> v(values, values + 8);
    std::vector<int> v2(v);

    // sorting all elements
    std::sort (v.begin(), v.end());
    
    // sorting half of the vector
    std::sort (v2.begin(), v2.begin() + 4); //(12 32 45 71)26 80 53 33

    // print v1
    std::vector<int>::iterator it;
    for (it = v.begin() ;it != v.end(); ++it)
        std::cout << *it << " ";

    std::cout << '\n';

    // print v2
    for (it = v2.begin(); it != v2.end(); ++it)
        std::cout << *it << " ";

    std::cout << '\n';

    return 0;
}