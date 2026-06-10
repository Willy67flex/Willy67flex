#include "ScalarConverter.hpp"

int	main(int argc, char **argv)
{
	if (argc != 2)
		return (std::cout << "Usage: ./convert <something you want to convert>" << std::endl, 1);

	std::string	str = argv[1];

	ScalarConverter::convert(str);

	return 0;
}
