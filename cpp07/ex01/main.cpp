#include "iter.hpp"

char	mytoupper(char c) { return toupper(c); }
int		multiplay(int x) { return x * 10; }

int main()
{
	char	arr[] = "hello world!";

	std::cout << "before: " << arr << std::endl;
	iter(arr, sizeof(arr) - 1, mytoupper);
	std::cout << "after : " << arr << std::endl;


	int		intArr[] = {0, 1, 2, 3, 4, 5};
	std::cout << std::endl;

	std::cout << "before: ";
	for (unsigned long i = 0; i < sizeof(intArr) / sizeof(int); i++)
		std::cout << intArr[i] << " ";

	iter(intArr, sizeof(intArr) / sizeof(int), multiplay);

	std::cout << "\nafter : ";
	for (unsigned long i = 0; i < sizeof(intArr) / sizeof(int); i++)
		std::cout << intArr[i] << " ";
	std::cout << std::endl;

	return 0;
}