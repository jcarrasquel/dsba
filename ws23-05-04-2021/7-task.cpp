#include <iostream>
#include <map>
#include <vector>

template<typename K, typename V>
void split(std::map<K,V> m, std::vector<K>& keys, std::vector<V>& values, K x)
{
	typename std::map<K,V>::iterator it;
	
	for(it = m.begin(); it != m.end(); ++it)
	{
		keys.push_back(it->first);
		values.push_back(it->second);
	}
}

int main()
{
	std::vector<int> keys;
	std::vector<double> values;

	std::map<int, double> m = { {1,3.14}, {100,20.0}, {99, 66.3} };
	split(m, keys, values, 3);

	for(int i = 0 ; i < keys.size(); i++)
	{
		std::cout << keys[i] << " " << values[i] << std :: endl;
	}

}
