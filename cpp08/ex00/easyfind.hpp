#ifndef __EASYFIND__
#define __EASYFIND__

#include <iostream>
#include <exception>

template<typename T>
void	easyfind(T& container, int target)
{
	for (typename T::iterator it = container.begin(); it != container.end(); ++it)
    {
        if (*it == target)
        {
            std::cout << "Target was found!\n";
            return;
        }
    }
    throw(std::exception());
}

#endif