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
		else if (cmd == "ADD")
			directory.AddNewContact();
		else if (cmd == "SEARCH")
			directory.SearchContact();
		else if (cmd == "EXIT")
			break ;
		else
			std::cout << "invalid command" << std::endl;
	}
	return 0;
}
