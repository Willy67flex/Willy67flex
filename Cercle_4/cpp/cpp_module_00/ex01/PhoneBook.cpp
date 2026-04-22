#include "PhoneBook.hpp"

int	main()
{
	PhoneBook	directory;
	std::string	cmd;

	while (1)
	{
		std::cout << "Please enter a command (ADD, SEARCH or EXIT)" << std::endl;
		std::cin >> cmd;
		if (std::cin.eof())
			break ;
		if (cmd == "ADD")
			directory.AddNewContact();
		if (cmd == "SEARCH")
			directory.SearchContact();
		if (cmd == "EXIT")
			break ;
	}
	return 0;
}
