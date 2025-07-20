#include "Brain.hpp"

Brain::Brain()
{
	std::cout << "Brain Default constructor called !" << std::endl;
}

Brain::Brain(const Brain &copy)
{
	std::cout << "Brain Copy constructor called" << std::endl;
	*this = copy;
}

Brain::~Brain()
{
	std::cout << "Brain Destructor called" << std::endl;
}

Brain	&Brain::operator=(const Brain &cpy)
{
	if (this == &cpy)
		return *this;
	for (int i = 0; i < 100; i++)
		_ideas[i] = cpy._ideas[i];
	return *this;
}