#include <vector>
#include <set>
#include <algorithm>

struct B
{
	int x;
};

bool cmp(B b1, B b2)
{
	return b1.x < b2.x;
}

using Set = std::set<B, decltype(cmp)*>;
using Vector = std::vector<B>;

int main()
{
	B b1 = {20};
	B b2 = {10};
	
	Set s({b1, b2}, cmp);
	
	Vector v = {b1, b2};
	std::sort(v.begin(), v.end(), cmp);

	return 0;
}