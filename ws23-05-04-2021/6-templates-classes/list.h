#ifndef LIST_H
#define LIST_H

template <typename T>
class List // our "homemade" container 
{
	public:
		List();
		int size();
		void insert(const T& x); //setter of an element T in the list
		const T& operator[](int i); //getter of an element T in

	private:
		// attributes?
		static const int MAX_CAPACITY = 100;

		int _n; // current size of the list

		T _l[MAX_CAPACITY]; // "_l" will be an array of T elements
};

#include "list.cpp"

#endif