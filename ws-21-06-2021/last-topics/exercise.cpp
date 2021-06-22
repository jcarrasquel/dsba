#include <iostream>
#include "number.h"

double sum(Number* r[], int n)
{
    double s = 0.0;
    
    for (int i = 0; i < n; i++)
    	s += r[i]->toDouble();
    
    return s;
}

int main()
{
    Number* r[3];
    r[0] = new Integer(1);
    r[1] = new Real(3.14142);
    r[2] = new Rational(4,5); // 4/5 = 0.8

    // should print sum=4.94142
    std::cout << "sum=" << sum(r, 3) << std::endl;

    delete r[0];
    delete r[1];
    delete r[2];
    
    return 0;
}
