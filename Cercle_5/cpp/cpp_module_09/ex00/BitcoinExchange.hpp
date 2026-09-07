#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

#include <iostream>
#include <map>
#include <fstream>
#include <algorithm>
#include <iomanip>

class	Bitcoin
{
	private:
		std::map<std::string, double>	_data;

	public:
		Bitcoin();
		Bitcoin(const Bitcoin &other);
		~Bitcoin();

		Bitcoin	&operator=(const Bitcoin &other);

		void	execute(const std::string &date, const double &val) const;

		void	setData(const std::string &date, const double &rate);
		void	printData();
};

#endif