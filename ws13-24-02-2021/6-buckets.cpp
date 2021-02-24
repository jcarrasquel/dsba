#include <iostream>
#include <vector>
#include <string>
#include <unordered_set>

using UnorderedSet = std::unordered_set<std::string>;

using UnorderedSetIter = std::unordered_set<std::string> :: local_iterator;

int main ()
{
    std::vector<std::string> planets = {"Mercury", "Venus", "Earth", "Mars", "Jupiter", "Saturn", "Uranus", "Neptune", "Pluto"};        

    UnorderedSet unorderedSet;

    char k;

    for(int p = 0; p < 9; p++)
    {
        std :: cout << "Inserting " << planets[p] << " to the unordered set!\n";

        unorderedSet.insert(planets[p]);

        UnorderedSet :: hasher h = unorderedSet.hash_function();

        // Let's see what happens inside the unordered set!

        for (int i = 0; i < unorderedSet.bucket_count(); i++)
        {
            std::cout << "bucket #" << i << " contains: ";

            for (UnorderedSetIter it = unorderedSet.begin(i); it != unorderedSet.end(i); ++it)
                std::cout << " " << *it << ":" << h(*it);

            std::cout << "\n";
        }
        
        std::cout << "buckets = " << unorderedSet.bucket_count() << '\n';
        std::cout << "load_factor = " << unorderedSet.load_factor() << '\n';

        std::cin.get(); // press enter to move to the next iteration
    }

    return 0;
}