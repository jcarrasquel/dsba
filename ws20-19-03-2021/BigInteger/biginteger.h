#include <iostream>
#include <vector>

#ifndef BigInteger_H
#define BigInteger_H

struct BigInteger
{
public:
    // ----< Methods >----

    // === constructors ===
    BigInteger();
    BigInteger(const BigInteger &v);
    BigInteger(std::vector<char> v);
    BigInteger(int x);
    // === setters ===
    void setInt(std::vector<char> v);
    void setSign(bool s);
    // === getters ===
    const std::vector<char> &getInt();
    const bool &getSign();
    // === overloads ===
    BigInteger operator+(BigInteger &v2);
    BigInteger operator+=(BigInteger &v2);
    BigInteger operator-(BigInteger &v2);
    BigInteger operator-=(BigInteger &v2);
    void operator=(long long int x);
    void operator=(BigInteger v2);
    bool operator==(BigInteger &v2);
    bool operator<(BigInteger &v2);
    bool operator>(BigInteger &v2);
    
    friend std::ostream &operator<<(std::ostream &out, BigInteger v);
    friend std::istream &operator>>(std::istream &in, BigInteger &v);

private:
    // ----< Fields >----
    std::vector<char> _v;
    bool _sign;
    // ----< Methods >----
    std::vector<char> add(std::vector<char> number1, std::vector<char> number2);
	std::vector<char> subtract(std::vector<char> number1, std::vector<char> number2);
    bool absolutecomparison(BigInteger &v2);
};

#endif