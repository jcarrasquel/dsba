#ifndef SMARTPTR_H
#define SMARTPTR_H

#include <iostream>

template <class T>
class SmartPtr
{
	public:
    
    	SmartPtr(T* p = nullptr)
    	{
    		_ptr = p;
    	}
  
    	~SmartPtr()
    	{
    		delete _ptr;
    	}

	    T& operator*()
	    {
	    	return *_ptr;
	    }

    	T* operator->()
    	{
    		return _ptr;
    	}
    
    private:

    	T* _ptr;
};

#endif