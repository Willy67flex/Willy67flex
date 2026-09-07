#include "RPN.hpp"

RPN::RPN() {}

RPN::RPN(const RPN &other)
{
	*this = other;
}

RPN::~RPN() {}

RPN	&RPN::operator=(const RPN &other)
{
	if (this != &other)
		_data = other._data;
	return *this;
}

void	RPN::calculate(const char &op)
{
	if (_data.size() < 2)
		throw std::runtime_error("Error");

	int	b = _data.back();
	_data.pop_back();
	

	int	a = _data.back();
	_data.pop_back();


	if (op == '+')
		_data.push_back(a + b);
	else if (op == '-')
		_data.push_back(a - b);
	else if (op == '*')
		_data.push_back(a * b);
	else if (op == '/')
	{
		if (b == 0)
			throw std::runtime_error("Error");
		_data.push_back(a / b);
	}
}

int	RPN::getResult() const
{
	if (_data.size() != 1)
		throw std::runtime_error("Error");
	return _data.back();
}

void	RPN::setData(const int &value)
{
	_data.push_back(value);
}
