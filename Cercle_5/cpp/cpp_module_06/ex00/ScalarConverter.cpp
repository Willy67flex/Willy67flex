#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter()
{
	std::cout << "ScalarConverter constructor called" << std::endl;
}

ScalarConverter::ScalarConverter(const ScalarConverter &other)
{
	(void)other;
	std::cout << "ScalarConverter copy constructor called" << std::endl;
}

ScalarConverter::~ScalarConverter()
{
	std::cout << "ScalarConverter destructor called" << std::endl;
}

ScalarConverter	&ScalarConverter::operator=(const ScalarConverter &other)
{
	(void)other;
	return *this;
}

void ScalarConverter::convert(const std::string& literal)
{
	if (literal == "nan" || literal == "nanf"
		|| literal == "inf" || literal == "inff"
		|| literal == "+inf" || literal == "+inff"
		|| literal == "-inf" || literal == "-inff")
	{
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossible" << std::endl;
		
		if (literal.find("nan") != std::string::npos)
		{
			std::cout << "float: nanf" << std::endl;
			std::cout << "double: nan" << std::endl;
		}
		else
		{
			std::string sign;
			if (literal[0] == '-')
				sign = "-";
			else if (literal[0] == '+')
				sign = "+";
			
			std::cout << "float: " << sign << "inff" << std::endl;
			std::cout << "double: " << sign << "inf" << std::endl;
		}
		return;
	}

	double dbl;
	char *endptr;

	if (literal.length() == 1 && !std::isdigit(literal[0]))
	{
		dbl = static_cast<double>(literal[0]);
	}
	else
	{
		dbl = std::strtod(literal.c_str(), &endptr);

		if (endptr == literal.c_str() || (*endptr != '\0' && !(*endptr == 'f' && *(endptr + 1) == '\0')))
		{
			std::cout << "char: impossible" << std::endl;
			std::cout << "int: impossible" << std::endl;
			std::cout << "float: nanf" << std::endl;
			std::cout << "double: nan" << std::endl;
			return;
		}
	}
	std::cout << "char: ";
	if (dbl != dbl || dbl < 0 || dbl > 127)
		std::cout << "impossible" << std::endl;
	else if (!std::isprint(static_cast<int>(dbl)))
		std::cout << "Non displayable" << std::endl;
	else
		std::cout << "'" << static_cast<char>(dbl) << "'" << std::endl;

	std::cout << "int: ";
	if (dbl != dbl || dbl > INT_MAX || dbl < INT_MIN)
		std::cout << "impossible" << std::endl;
	else
		std::cout << static_cast<int>(dbl) << std::endl;

	std::cout << std::fixed << std::setprecision(1);

	std::cout << "float: " << static_cast<float>(dbl) << "f" << std::endl;
	std::cout << "double: " << dbl << std::endl;
}
