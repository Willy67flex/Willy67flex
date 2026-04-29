#include "Harl.hpp"

int	main(int argc, char **argv)
{
	if (argc != 2)
		return (std::cout << "Wrong input, usage: ./harlFilter <cmd> (DEBUG, INFO, WARNING or ERROR)" << std::endl, 1);
	Harl	harl;

	std::string	str = argv[1];
	harl.complain(str);
	return 0;
}
