#include <iostream>
#include <stdexcept>
#include <cassert>
#include "safe_array.h"

void test1() // empty constructor
{
    SafeArray<int> arr1;
    assert(arr1.getSize() == 0);
    assert(arr1.getPtr() == nullptr);
}

void test2() // constructor with initialization of n elements with a value
{
    SafeArray<int> arr1(5, 42);
    assert(arr1.getSize() == 5);
    assert(arr1.getPtr() != nullptr);
    assert(arr1[0] == 42);
    assert(arr1.at(4) == 42);
}

void test3() // resize
{
    SafeArray<int> arr1;
    assert(arr1.getSize() == 0);
    assert(arr1.getPtr() == nullptr);

    arr1.resize(6, 42);
    assert(arr1.getSize() == 6);
    assert(arr1.getPtr() != nullptr);
    assert(arr1[0] == 42);
    assert(arr1.at(5) == 42);
}

void test4() // copy constr
{
    SafeArray<int> arr1(5, 42);
    assert(arr1.getSize() == 5);
    assert(arr1.getPtr() != nullptr);
    assert(arr1[0] == 42);
    assert(arr1.at(4) == 42);

    // new array - copied
    SafeArray<int> arr2 = arr1;      // arr2(arr1)

    assert(arr2.getSize() == 5);
    assert(arr2.getPtr() != nullptr);
    assert(arr2[0] == 42);
    assert(arr2.at(4) == 42);

    // check that this is another memory
    arr2[0] = 43;
    arr2.at(4) = 43;
    assert(arr2[0] == 43);
    assert(arr2.at(4) == 43);

    // initial must be the same
    assert(arr1[0] == 42);
    assert(arr1.at(4) == 42);
}


void test5() // copy assgn op
{
    SafeArray<int> arr1(5, 42);
    assert(arr1.getSize() == 5);
    assert(arr1.getPtr() != nullptr);
    assert(arr1[0] == 42);
    assert(arr1.at(4) == 42);

    // new array
    SafeArray<int> arr2(1, 10);
    arr2 = arr1;
    assert(arr2[0] == 42);
    assert(arr2.at(4) == 42);
}

void test6() // initializer list
{
    SafeArray<int> arr1( {10, 20, 30} );
    assert(arr1.getSize() == 3);
    assert(arr1.getPtr() != nullptr);
    assert(arr1[0] == 10);
    assert(arr1.at(2) == 30);

    std::cout << arr1 << '\n';
}


int main()
{
    test1();
    test2();
    test3();
    test4();        
    test5();        
    test6();

    return 0;
}