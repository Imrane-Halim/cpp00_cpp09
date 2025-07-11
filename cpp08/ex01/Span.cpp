#include "Span.hpp"

Span::Span():
	_vec(0),
	_max(0) { }

Span::Span(unsigned int N):
	_max(N) { }

Span::Span(const Span& other):
	_vec(other._vec),
	_max(other._max) { }

Span::~Span() { }

Span&	Span::operator=(const Span& other)
{
	if (this != &other)
	{
		_vec = other._vec;
		_max = other._max;
	}
	return *this;
}

void	Span::addNumber(int num)
{
	if (_vec.size() < _max)
		_vec.push_back(num);
	else
		throw(std::runtime_error("Can't add number"));
}

void    Span::addRange(std::vector<int>::iterator begin, std::vector<int>::iterator end)
{
	int	dist = std::distance(begin, end);

	if (_vec.size() + dist > _max)
		throw(std::runtime_error("Can't add range"));
	_vec.insert(
		_vec.end(),
		begin,
		end	
	);
}

void	Span::print(void) const
{
	for (long unsigned i = 0; i < _vec.size(); i++)
		std::cout << _vec[i] << std::endl;
}

int		Span::longestspan(void)
{
	if (_vec.size() <= 1)
		throw(std::runtime_error("Can't find span"));

	return	*std::max_element(_vec.begin(), _vec.end())
			- *std::min_element(_vec.begin(), _vec.end());
}

int		Span::shortestSpan(void)
{
	if (_vec.size() <= 1)
		throw(std::runtime_error("Can't find span"));
	
	std::vector<int> tmp(_vec);
	std::sort(tmp.begin(), tmp.end());

	long span = UINT_MAX;
	for (size_t i = 0; i < tmp.size() - 1; i++)
	{
		if (labs(tmp[i + 1] - tmp[i]) < span)
			span = labs(tmp[i + 1] - tmp[i]);
	}
	return span;
}