#ifndef	__ARRAY__
#define __ARRAY__

#include <iostream>

template<typename type>
class Array
{
	type			*_arr;
	unsigned int	_n;
public:
	Array(): _arr(new type[0]), _n(0) {}
	Array(unsigned int n): _arr(new type[n]), _n(n) {}
	Array(const Array& copy)
	{
		*this = copy;
	}
	~Array()
	{
		delete[] _arr;
	}

	Array	&operator=(const Array& copy)
	{
		if (this != &copy)
		{
			// deep copy
			delete _arr;
			_n = copy._n;
			_arr = new type[copy._n];
			for (int i = 0; i < _n; i++)
				_arr[i] = copy._arr[i];
		}
		return *this;
	}

	type			&operator[](unsigned index)
	{
		if (index >= _n)
			throw(std::exception());
		return _arr[index];	
	}

	unsigned int	size(void) const { return _n; }
};

#endif