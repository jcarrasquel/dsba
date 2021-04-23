#include <iostream>
#include <vector>
#include <sstream>
#include <cmath>
#include <string>

typedef unsigned int UInt;

typedef std::vector<char> BinInt;

std::ostream& operator<<(std::ostream& os, const BinInt& bin)
{
	for(int i = 0; i < bin.size(); i++)
		if(i % 4 == 0 && i > 0 ){
			os << '\'' << bin[i];
		}else{
			os << bin[i];
		}
	return os;
}

std::istream& operator>>(std::istream& in, BinInt& bin)
{
	std::string s;
	in >> s;
	for(int i = 0; i < s.size(); i++)
		bin.push_back(s[i]);
	return in;
}

char int2char(int x)
{
	std::stringstream ss;
	ss << x;
	char c;
	ss >> c;
	return c;
}

int char2int(char c)
{
	return atoi(&c);
}

void to32bits(BinInt& bin)
{
	int digits = bin.size();

	int x = 32 - digits; // how many zeroes at the beggining?
 
	for(int i = 0; i < x; i++)
		bin.insert(bin.begin(), '0');
}	

BinInt dec2bin(UInt dec)
{
	BinInt bin;

	while(dec > 0)
	{
		bin.insert(bin.begin(), int2char(dec % 2));
		dec = dec / 2;
	}

	to32bits(bin);

	return bin;
}

UInt bin2dec(const BinInt& bin)
{
	UInt res = 0;

	for(int i = 0; i < bin.size(); i++)
		res += char2int(bin[i]) * pow(2, bin.size() - i - 1);;

	return res;
}

int main()
{
	UInt dec;

	std :: cin >> dec;

	BinInt bin = dec2bin(dec);

	std :: cout << bin << std :: endl;

	UInt res = bin2dec(bin);

	std :: cout << res << std :: endl;

	return 0;
}
