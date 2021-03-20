// Implementation of biginteger.h
#include "biginteger.h"
#include <sstream>
#include <vector>
#include <cmath>
#include <algorithm>

// === constructors ===

BigInteger::BigInteger()
{
    _v = {'0'};
    _sign = true;
}

BigInteger::BigInteger(const BigInteger &v)
{
    _v = v._v;
    _sign = v._sign;
}

BigInteger::BigInteger(std::vector<char> v)
{
    if (v[0] == '-')
    {
        _sign = false;
        _v.erase(v.begin());
    }
    else
    {
        _sign = true;
    }
    _v = v;
}

BigInteger::BigInteger(int x)
{
    operator=(x);
}

// === setters ===

void BigInteger::setInt(std::vector<char> v)
{
    _v = v;
}

void BigInteger::setSign(bool s)
{
    _sign = s;
}

// === getters ===

const std::vector<char> &BigInteger::getInt()
{
    return _v;
}

const bool &BigInteger::getSign()
{
    return _sign;
}

// === operators overload ===

std::ostream &operator<<(std::ostream &os, BigInteger v)
{
    if (!v._sign)
    {
        os << '-';
    }
    for (std::vector<char>::iterator it = v._v.begin(); it != v._v.end(); ++it)
    {
        os << *it;
    }
    return os;
}

std::istream &operator>>(std::istream &in, BigInteger &v)
{
    std::string line;
    in >> line;

    std::stringstream ss(line);
    if (ss.good() && !ss.eof())
    {
        char temp;
        ss >> temp;
        if (temp == '-')
        {
            v._sign = false;
        }
        else
        {
            if (isdigit(temp))
            {
                v._v.push_back(temp);
            }
            v._sign = true;
        }
    }
    if (v._v[0] == '0')
    {
        v._v.erase(v._v.begin());
    }
    while (ss.good() && !ss.eof())
    {
        char temp;
        ss >> temp;
        if (isdigit(temp))
        {
            v._v.push_back(temp);
        }
    }
    v._v.pop_back();
    return in;
}

void BigInteger::operator=(BigInteger v2)
{
    setInt(v2.getInt());
    setSign(v2.getSign());
}

void BigInteger::operator=(long long int x)
{
    while(x != 0)
    {
        _v.insert(_v.begin(), (x % 10) + 48);
        x /= 10;
    }
    if (x >= 0)
    {
        _sign = true;
    }
    else
    {
        _sign = false;
    }
}

bool BigInteger::operator==(BigInteger &v2)
{
    BigInteger v = *this;
    bool equals = v.getInt() == v2.getInt() && v.getSign() == v2.getSign();
    return equals;
}

bool BigInteger::operator<(BigInteger &v2)
{
    bool s1 = getSign();
    bool s2 = v2.getSign();

    if (s1 && !s2)
    {
        return false;
    }

    if (s2 && !s1)
    {
        return true;
    }
    std::vector<char> n1 = getInt();
    std::vector<char> n2 = v2.getInt();
    if (s1)
    {
        if (n1.size() > n2.size())
        {
            return false;
        }

        if (n1.size() < n2.size())
        {
            return true;
        }

        for (size_t i = 0; i < n1.size(); ++i)
        {
            if (n1[i] < n2[i])
            {
                return true;
            }
            else
            {
                if (n1[i] > n2[i])
                {
                    return false;
                }
            }
        }
        return false;
    }
    else
    {
        if (n1.size() > n2.size())
        {
            return true;
        }

        if (n1.size() < n2.size())
        {
            return false;
        }

        for (size_t i = 0; i < n1.size(); ++i)
        {
            if (n1[i] < n2[i])
            {
                return false;
            }
            else
            {
                if (n1[i] > n2[i])
                {
                    return true;
                }
            }
        }
        return false;
    }
}

bool BigInteger::operator>(BigInteger &v2)
{
    bool s1 = getSign();
    bool s2 = v2.getSign();

    if (s1 && !s2)
    {
        return true;
    }

    if (s2 && !s1)
    {
        return false;
    }
    std::vector<char> n1 = getInt();
    std::vector<char> n2 = v2.getInt();
    if (s1)
    {
        if (n1.size() > n2.size())
        {
            return true;
        }

        if (n1.size() < n2.size())
        {
            return false;
        }

        for (size_t i = 0; i < n1.size(); ++i)
        {
            if (n1[i] - '0' < n2[i] - '0')
            {
                return false;
            }
            else
            {
                if (n1[i] - '0' > n2[i] - '0')
                {
                    return true;
                }
            }
        }
        return false;
    }
    else
    {
        if (n1.size() > n2.size())
        {
            return false;
        }

        if (n1.size() < n2.size())
        {
            return true;
        }

        for (size_t i = 0; i < n1.size(); ++i)
        {
            if (n1[i] - '0' < n2[i] - '0')
            {
                return true;
            }
            else
            {
                if (n1[i] - '0' > n2[i] - '0')
                {
                    return false;
                }
            }
        }
        return false;
    }
}

BigInteger BigInteger::operator+(BigInteger &v2)
{
    BigInteger addition;
    if (getSign() == v2.getSign())
    {
        addition.setInt(add(getInt(), v2.getInt()));
        addition.setSign(getSign());
    }
    else
    {
        if (absolutecomparison(v2))
        {
            addition.setInt(subtract(getInt(), v2.getInt()));
            addition.setSign(getSign());
        }
        else
        {
            addition.setInt(subtract(v2.getInt(), getInt()));
            addition.setSign(v2.getSign());
        }
    }
    std::vector<char> empty = {'0'};
    if (addition.getInt() == empty)
        addition.setSign(true);

    return addition;
}

BigInteger BigInteger::operator+=(BigInteger &v2)
{
    (*this) = (*this) + v2;
    return (*this);
}

BigInteger BigInteger::operator-(BigInteger &v2)
{
    v2.setSign(!v2.getSign());
    return (*this) + v2;
}

BigInteger BigInteger::operator-=(BigInteger &v2)
{
    (*this) = (*this) - v2;
    return (*this);
}

std::vector<char> BigInteger::add(std::vector<char> number1, std::vector<char> number2)
{
    std::vector<char> add = (number1.size() > number2.size()) ? number1 : number2;
    char carry = '0';
    int differenceInLength = abs((int)(number1.size() - number2.size()));

    if (number1.size() > number2.size())
        number2.insert(number2.begin(), differenceInLength, '0');

    else
        number1.insert(number1.begin(), differenceInLength, '0');

    for (int i = number1.size() - 1; i >= 0; --i)
    {
        add[i] = ((carry - '0') + (number1[i] - '0') + (number2[i] - '0')) + '0';

        if (i != 0)
        {
            if (add[i] > '9')
            {
                add[i] -= 10;
                carry = '1';
            }
            else
                carry = '0';
        }
    }
    if (add[0] > '9')
    {
        add[0] -= 10;
        add.insert(add.begin(), 1, '1');
    }
    return add;
}

std::vector<char> BigInteger::subtract(std::vector<char> number1, std::vector<char> number2)
{
    std::vector<char> sub = (number1.size() > number2.size()) ? number1 : number2;
    int differenceInLength = abs((int)(number1.size() - number2.size()));

    if (number1.size() > number2.size())
        number2.insert(number2.begin(), differenceInLength, '0');

    else
        number1.insert(number1.begin(), differenceInLength, '0');

    for (int i = number1.size() - 1; i >= 0; --i)
    {
        if (number1[i] < number2[i])
        {
            number1[i] += 10;
            number1[i - 1]--;
        }
        sub[i] = ((number1[i] - '0') - (number2[i] - '0')) + '0';
    }

    while (sub[0] == '0' && sub.size() != 1)
        sub.erase(sub.begin());

    return sub;
}

bool BigInteger::absolutecomparison(BigInteger &v2)
{
    std::vector<char> n1 = getInt();
    std::vector<char> n2 = v2.getInt();
    if (n1.size() > n2.size())
    {
        return true;
    }

    if (n1.size() < n2.size())
    {
        return false;
    }

    for (size_t i = 0; i < n1.size(); ++i)
    {
        if (n1[i] - '0' < n2[i] - '0')
        {
            return false;
        }
        else
        {
            if (n1[i] - '0' > n2[i] - '0')
            {
                return true;
            }
        }
    }
    return false;
}