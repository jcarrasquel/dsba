#ifndef LIST_CPP
#define LIST_CPP

#include "list.h"

#include <stdexcept>
#include <string>

// Implementation of list.h

template<typename T>
List<T>:: List() // implementation of the constructor
{
	_n = 0; // at the beggining, our list is empty.
}

template<typename T>
int List<T>:: size()
{
	return _n;
}

template<typename T>
void List<T>::insert(const T& x) // x = 5
{
	_l[_n] = x;
	_n++;  // n = 2
}

template<typename T>
const T& List<T>::operator[](int i)
{
	// to throw an exception if i < 0 and i >= _n
	if(i < 0 || i >= _n)
		throw std::out_of_range("ERROR!");

	return _l[i];
}


#endif