#include "PmergeMe.hpp"

int*    initArr(int* arr, int ac, char** av)
{
    char*   end = NULL;
    long    tmp;
    std::set<int> seen;

    for (int i = 0; i < ac; i++)
    {
        tmp = strtol(av[i], &end, 10);
        if (*end != '\0')
            throw(std::runtime_error("invalid number: " + std::string(av[i])));
        if (tmp > INT_MAX || tmp < INT_MIN || errno == ERANGE)
            throw(std::runtime_error("range error: " + std::string(av[i])));   
        if (!seen.insert(tmp).second)
            throw(std::runtime_error("duplicates: " + std::string(av[i])));
        arr[i] = tmp;
    }

    return arr;
}


