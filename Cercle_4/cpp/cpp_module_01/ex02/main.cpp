#include <iostream>

int	main()
{
	std::string	var = "HI THIS IS BRAIN";
	std::string	*stringPTR = &var;
	std::string	&stringREF = var;

	std::cout << "Memory address of var:            " << &var << std::endl;
	std::cout << "Memory address held by stringPTR: " << stringPTR << std::endl;
	std::cout << "Memory address held by stringREF: " << &stringREF << std::endl;


	std::cout << "\nValue of var:       " << var << std::endl;
	std::cout << "Value of stringPTR: " << *stringPTR << std::endl;
	std::cout << "Value of stringREF: " << stringREF << std::endl;
}
