#include "Array.hpp"

int main()
{
	unsigned int size = 10;
	Array<int> arr(size);

	for (unsigned int i = 0; i < size; i++)
		arr[i] = i * 10;
	
	for (unsigned int i = 0; i < size; i++)
		std::cout << i << ": " << arr[i] << std::endl;

	try
	{
		std::cout << arr[size + 10] << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	
	return 0;
}