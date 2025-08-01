#include "easyfind.hpp"
#include <vector>
#include <list>
#include <queue>

#define ERR "targed was not found!\n"

int	main(void)
{
	int	arr[] = {1, 2, 3, 4, 5, 6};
	int	size = sizeof(arr) / sizeof(arr[0]);

	std::vector<int> vec;
	std::list<int> lst;
	std::deque<int> que;

	for (int i = 0; i < size; i++)
	{
		vec.push_back(arr[i]);
		lst.push_back(arr[i]);
		que.push_back(arr[i]);
	}

	try
	{ easyfind(que, 3); }
	catch(const std::exception& e)
	{ std::cerr << ERR; }

	try
	{ easyfind(que, 4); }
	catch(const std::exception& e)
	{ std::cerr << ERR; }

	try
	{ easyfind(que, 7); }
	catch(const std::exception& e)
	{ std::cerr << ERR; }

	return 0;
}