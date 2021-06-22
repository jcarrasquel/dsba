#include <iostream>
#include <functional>
#include <memory>

int square(int x)
{
    return x*x;
}

int cube(int x)
{
    return x*x*x;
}

template<typename T>
class BaseClass
{
    public:
        BaseClass(){}
        virtual int calc(std::function<T> f, int x) = 0;
};

template<typename T>
class DerivedClass : public BaseClass<T>
{
    public:
        DerivedClass(){}
        virtual int calc(std::function<T> f, int x) 
        {
            return f(x);
        }
};

int main()
{
    using F = decltype(square); // alias of square. data type of the function square and cube.

    std::unique_ptr<BaseClass<F>> ptr(new DerivedClass<F>); // like "upcasting"

    std::cout << ptr->calc(square, 3) << "\n";
    
    std::cout << ptr->calc(cube, 3) << "\n";
}