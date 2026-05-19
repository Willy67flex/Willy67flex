#include "ClapTrap.hpp"

int main()
{
	ClapTrap eliott("Eliott");
	ClapTrap greg("Greg");
	ClapTrap antoine("Antoine");

	std::cout << "\n" << std::endl;
	eliott.attack("a gnat");
	std::cout << eliott << std::endl;
	eliott.takeDamage(5);
	std::cout << eliott << std::endl;
	eliott.beRepaired(3);
	std::cout << eliott << std::endl;

	std::cout << "\n\n\n" << std::endl;
	for (int i = 0; i < 9; i++) 
	{
		std::cout << eliott << std::endl;
		eliott.attack("a horde of gnats");
	}
	eliott.beRepaired(10);

	std::cout << "\n\n\n" << std::endl;
	std::cout << greg << std::endl;
	greg.takeDamage(100);
	std::cout << greg << std::endl;
	greg.attack("Git");
	greg.beRepaired(5);

	std::cout << "\n\n\n" << std::endl;
	std::cout << antoine << std::endl;
	antoine.takeDamage(8);
	std::cout << antoine << std::endl;
	antoine.beRepaired(100);
	std::cout << antoine << "\n\n" << std::endl;

	return 0;
}
