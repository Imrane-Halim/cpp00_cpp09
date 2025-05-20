#ifndef __EASYFIND__
#define __EASYFIND__

#include <iostream>
#include <exception>
#include <algorithm>

class NotFoundExecption: public std::exception
{
public:
    const char* what() const throw() {
        return "Target Was Not Found!";
    }
};

template<typename T>
void	easyfind(T& container, int target)
{
    typename T::iterator it = std::find(
        container.begin(),
        container.end(),
        target
    );

    if (it == container.end())
        throw(NotFoundExecption());
    std::cout   << "Target found at pos: "
                << std::distance(container.begin(), it)
                << std::endl;
}

#endif