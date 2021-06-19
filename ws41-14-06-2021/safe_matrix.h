#ifndef SAFE_MATRIX_H_
#define SAFE_MATRIX_H_

#include <cstddef>
#include <algorithm>
#include <stdexcept>        
#include <iostream>

template<typename T>
class SafeMatrix{

	public: 

	    SafeMatrix()
	    	: _mat(nullptr),
	    	_rows(0),
	    	_cols(0)
	    {} 

	    SafeMatrix(size_t rows, size_t cols, T def = T())
	    {
	   		if(!rows || !cols)
				return;

			_rows = rows;
			_cols = cols;

			_mat = new T*[_rows];
			for(int i = 0; i < _rows; i++)
			{
				_mat[i] = new T[_cols];
				for(int j = 0; j < _cols; j++)
					_mat[i][j] = def;
			}
	    }

	    SafeMatrix(std::initializer_list<std::initializer_list<T>> matrix)
	    {
	    	if(!matrix.size())
				return;

			_rows = matrix.size();
			
			_mat = new T*[_rows];

			int i = 0;
			for(const std::initializer_list<T>& row : matrix)
			{
				_cols = row.size();
				_mat[i] = new T[_cols];
				int j = 0;
				for(const T& el : row)
				{
					_mat[i][j] = el;
					j++;
				}
				i++;
			}
	    }

	    ~SafeMatrix()
	    {
	    	for (int i = 0; i < _rows; ++i)
    			delete[] _mat[i];
			delete[] _mat;
	    }
	
	public:
    	
    	void resize(size_t newRows, size_t newCols, T def = T())
    	{
	        T** newMat = new T*[newRows];

	        for (int i = 0; i < newRows; ++i)
	        {
	        	newMat[i] = new T[newCols];
	        	for(int j = 0; j < newCols; ++j)
	        		newMat[i][j] = i >= _rows || j >= _cols ? def : _mat[i][j];
	        }

	        for (int i = 0; i < _rows; ++i)
    			delete[] _mat[i];
			delete[] _mat;

        	_rows = newRows;
        	_cols = newCols;

        	_mat = newMat;
    	}

    	void print()
    	{
    		std::cout << std::endl;
    		for(int i = 0; i < _rows; i++)
    		{
    			std::cout << &(_mat[i]) << "|" << (_mat[i]) << "|" << " ===> ";

    			for(int j = 0; j < _cols; j++)
    			{
    				std::cout << &(_mat[i][j]) << "|" << _mat[i][j] << "|";
    				if(j != _cols - 1)
    					std::cout << ' ';
    			}
    			std::cout << '\n';
    		}
    	}

	private:
	    T** _mat;           
	    size_t _rows;
	    size_t _cols;
};

#endif
