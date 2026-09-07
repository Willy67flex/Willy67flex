#include "BitcoinExchange.hpp"

Bitcoin::Bitcoin() {}

Bitcoin::Bitcoin(const Bitcoin &other) 
{
	*this = other;
}

Bitcoin::~Bitcoin() {}

Bitcoin	&Bitcoin::operator=(const Bitcoin &other)
{
	if (this != &other)
		_data = other._data;
	return *this;
}

void	Bitcoin::execute(const std::string &date, const double &val) const
{
	double											price;
	std::map<std::string, double>::const_iterator	it = _data.lower_bound(date);

	if (it == _data.end() || it->first != date)
	{
		if (it == _data.begin())
		{
			std::cerr << "Error: date too early => " << date << std::endl;
			return ;
		}
		--it;
	}

	price = it->second;
	std::cout << date << " => " << val << " = " << (val * price) << std::endl;
}

void	Bitcoin::setData(const std::string &date, const double &rate)
{
	_data[date] = rate;
}
