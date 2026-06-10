#ifndef ScalarConverter_HPP
# define ScalarConverter_HPP

#include <iostream>
#include <cstdlib>
#include <climits>
#include <iomanip>
#include <cmath>
#include <limits>

class	ScalarConverter
{
	private:

		ScalarConverter();
		ScalarConverter(const ScalarConverter &other);
		~ScalarConverter();
		ScalarConverter	&operator=(const ScalarConverter &other);

	public:
	
		static void	convert(const std::string &str);
};

#endif