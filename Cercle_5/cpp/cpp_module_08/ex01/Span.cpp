#include "Span.hpp"

Span::Span(unsigned int N) : _N(N) {}

Span::Span(const Span &other)
{
	*this = other;
}

Span::~Span() {}

Span	&Span::operator=(const Span &other)
{
	if (this != &other)
	{
		_value = other._value;
		_N = other._N;
	}
	return *this;
}

void Span::addNumber(int n)
{
	if (_value.size() >= _N)
		throw Span::NbOfIntegerExceeds();
	_value.push_back(n);
}

int Span::shortestSpan() const
{
	if (_value.size() < 2)
		throw Span::SpanImpossible();

	std::vector<int> tmp = _value;
	std::sort(tmp.begin(), tmp.end());

	int min = tmp[1] - tmp[0];
	for (unsigned int i = 1; i < tmp.size() - 1; i++)
		if ((tmp[i+1] - tmp[i]) < min)
			min = tmp[i+1] - tmp[i];
	return min;
}

int Span::longestSpan() const
{
	if (_value.size() < 2)
		throw Span::SpanImpossible();

	int min = *std::min_element(_value.begin(), _value.end());
	int max = *std::max_element(_value.begin(), _value.end());

	return (max - min);
}

const char	*Span::NbOfIntegerExceeds::what() const throw()
{
	return "The number of values has reached its maximum";
}

const char	*Span::SpanImpossible::what() const throw()
{
	return "We need at least two values to calculate a Span";
}
