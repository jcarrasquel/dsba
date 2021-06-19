#ifndef SAFE_ARRAY_H_
#define SAFE_ARRAY_H_

#include <cstddef>
#include <algorithm>        // std::min
#include <stdexcept>        // std::out_of_range
#include <iostream>

template<typename T>
class SafeArray{

	public:
	    
	    SafeArray()
	    	: _arr(nullptr),
	    	  _size(0)
	   	{}

	    SafeArray(size_t n, T def = T())
	    {
			if(!n)
				return;

			_size = n;

			_arr = new T[_size];

			for(int i = 0; i < _size; i++)
				_arr[i] = def;
		}

	    SafeArray(const SafeArray& origin)
	    	: _size(origin._size),
	  		  _arr(new T[origin._size])
		{
			for(int i = 0; i < _size; i++)
				_arr[i] = origin._arr[i];
		}

		SafeArray(std::initializer_list<T> vals)
			: SafeArray()
		{
			if(! vals.size())
				return;

			_size = vals.size();
			_arr = new T[_size];

			int i = 0;
			for(const T& el : vals)
			{
				_arr[i] = el;
				i++;
			}
		}

	    ~SafeArray()
	    {
	    	delete[] _arr;
	    }

	    const SafeArray& operator=(const SafeArray& rightArr)
	    {
	    	if (this == &rightArr)
            	return *this;

            SafeArray tmpArr(rightArr);

            swap(tmpArr, *this);

        	return *this;
	    }
	
	public:
    
    	void resize(size_t newSize, T def = T())
    	{
    		if(newSize == _size)
            	return;

        	if(!newSize)                         
        	{
            	if(_arr)
            	{
	                delete [] _arr;
	                _arr = nullptr;
	                _size = 0;
           		}
            	return;
        	}
        	
	        T* newArr = new T[newSize];
	        for (int i = 0; i < std::min(newSize, _size); ++i)
	        	newArr[i] = _arr[i];

	        if(newSize > _size)
	        {
	            for(int j = _size; j < newSize; ++j)
	                newArr[j] = def;
	        }

        	_size = newSize;
        	delete [] _arr;
        	_arr = newArr;
    	}

    	T& operator [] (size_t i) noexcept  { return _arr[i]; }
    	const T& operator [] (size_t i) const noexcept { return _arr[i]; }
    
    	// Throw exception "std::out_of_range" if "i" is not in range.
    	T& at(size_t i)
    	{
	        if (i >= _size)
	            throw std::out_of_range("Bad index");
	        return _arr[i];
    	}

    	const T& at(size_t i) const
    	{
	        if (i >= _size)
	            throw std::out_of_range("Bad index");
	        return _arr[i];
    	}

    	// getters
    	size_t getSize() const { return _size; }	
    	const T* getPtr() const { return _arr; }

	private:

	    static void swap(SafeArray& leftArr, SafeArray& rightArr) noexcept
	    {
	    	std::swap(leftArr._arr, rightArr._arr);
        	std::swap(leftArr._size, rightArr._size);
	    } // use std::swap

	private:
	    T* _arr;                
	    size_t _size;

};

template <typename T>
std::ostream& operator<< (std::ostream& s, const SafeArray<T> arr)
{
    s << "[";
    for (size_t i = 0; i < arr.getSize(); ++i)
    {
        if(i)
            s << ", ";
        s << arr[i];
    }

    s << "]";

    return s;
}

// print the array as [10, 20, 30] using square brackets and commas

#endif