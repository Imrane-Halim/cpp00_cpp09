#ifndef	__ITER__
#define __ITER__

#include <iostream>

template<typename T>
void	iter(T arr[], size_t lenght, T(*fun)(T))
{
	for (size_t i = 0; i < lenght; i++)
		arr[i] = fun(arr[i]);
}

#endif