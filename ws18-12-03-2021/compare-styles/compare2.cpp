#include <vector>
#include <set>
#include <algorithm>
#include <iostream>

struct B
{
	int x;
	bool operator<(B b2) const
	{
		return x < b2.x;
	}
};

using Set = std::set<B>;
using Vector = std::vector<B>;

int main()
{
	B b1 = {20};
	B b2 = {10};
	
	Set s = {b1, b2};

	Vector v = {b1, b2};
	std::sort(v.begin(), v.end());

	return 0;
}