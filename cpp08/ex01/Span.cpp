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

const char*	Span::_FullSpanException::what() const throw()
{
	return "Span is Full!";
}

const char*	Span::_CantFindSpan::what() const throw()
{
	return "No Span can be found!";
}

Span::_NumGen::_NumGen(int num): _num(num) { }
int		Span::_NumGen::operator()()  { return _num++; }

void	Span::addNumber(int num)
{
	if (_vec.size() < _max)
		_vec.push_back(num);
	else
		throw(_FullSpanException());
}

void	Span::addRange(int start, int end)
{
	if (_vec.size() + (end - start + 1) > _max)
		throw(_FullSpanException());
	_NumGen gen(start);
	std::generate_n(std::back_inserter(_vec), (end - start + 1), gen);
}

void	Span::print(void) const
{
	for (long unsigned int i = 0; i < _vec.size(); i++)
		std::cout << _vec[i] << std::endl;
}

int		Span::longestspan(void)
{
	if (_vec.size() <= 1)
		throw(_CantFindSpan());

	return	*std::max_element(_vec.begin(), _vec.end())
			- *std::min_element(_vec.begin(), _vec.end());
}

int		Span::shortestSpan(void)
{
	if (_vec.size() <= 1)
		throw(_CantFindSpan());
	
	std::vector<int> tmp(_vec);
	std::sort(tmp.begin(), tmp.end());

	int span = INT_MAX;
	for (long unsigned i = 0; i < tmp.size(); i++)
	{
		if (abs(tmp[i + 1] - tmp[i]) < span)
			span = abs(tmp[i + 1] - tmp[i]);
	}
	return span;
}