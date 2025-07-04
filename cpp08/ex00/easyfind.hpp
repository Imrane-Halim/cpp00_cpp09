#ifndef __EASYFIND__
#define __EASYFIND__

#include <iostream>
#include <exception>
#include <algorithm>

template<typename T>
void	easyfind(T& container, int target)
{
    // this is called dependent type resolution
    // helps the compiler tell if it's a static data member
    // of a class, or a nested type `eg: vector<>::iter...etc`
    typename T::iterator it = std::find(
        container.begin(),
        container.end(),
        target
    );

    if (it == container.end())
        throw(std::runtime_error("Target Not found!"));
    std::cout   << "Target found at pos: "
                << std::distance(container.begin(), it)
                << std::endl;
}

#endif